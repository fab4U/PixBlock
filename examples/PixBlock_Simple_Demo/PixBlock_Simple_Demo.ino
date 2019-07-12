/*
 * PixBlock_Demo
 *
 */ 

/**********************************************************************************

Description:      Test software for the PixBlock controlled by an Arduino 
                  with an ATmega328 processor running at 16 MHz or an 
                  ATtiny84A processor running at 8 MHz.

                  Connect your PixBlock(s) to an Arduino Uno using four jumper 
                  wires as described here:
                  http://fab4u.de/de/kits/pixblock/software#konfiguration

                  The demo simply displays static content without scrolling.
                  
                  First it shows the PixBlock-Logo, which consists of a rainbow 
                  square followed by the text "PixBlock fab4U".
                  
                  After 2 seconds the text "Hello world" appears in green and 
                  then in red and further examples.
                  
                  Operation of the PixBlocks, i. e. multiplexing of the display 
                  columns, is done by an interrupt routine which periodically 
                  calls dm.update();
                  For this purpose Timer2 is setup to issue an interrupt at a 
                  rate specified by DM_REFRESH_FREQ.

Author:           Frank Andre
Copyright 2015:   Frank Andre
License:          see "license.md"
Disclaimer:       This software is provided by the copyright holder "as is" and any 
                  express or implied warranties, including, but not limited to, the 
                  implied warranties of merchantability and fitness for a particular 
                  purpose are disclaimed. In no event shall the copyright owner or 
                  contributors be liable for any direct, indirect, incidental, 
                  special, exemplary, or consequential damages (including, but not 
                  limited to, procurement of substitute goods or services; loss of 
                  use, data, or profits; or business interruption) however caused 
                  and on any theory of liability, whether in contract, strict 
                  liability, or tort (including negligence or otherwise) arising 
                  in any way out of the use of this software, even if advised of 
                  the possibility of such damage.
					
**********************************************************************************/


#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <avr/eeprom.h>
//#include <util/atomic.h>

#include "dot_matrix.h"
#include "ticker.h"


/*************
 * constants *
 *************/

// dot matrix system timer
#define DM_REFRESH_FREQ		2500		// dot matrix column refresh rate (Hz)
#define DM_PRESCALER		32			// prescaler division ratio (1, 8, 32 or 64)

#define DM_REFRESH			(uint8_t)(0.5 + F_CPU / ((float)DM_REFRESH_FREQ * (float)DM_PRESCALER))
#if DM_PRESCALER == 1
#define DM_CS				1
#elif DM_PRESCALER == 8
#define DM_CS				2
#elif DM_PRESCALER == 32
#define DM_CS				3
#elif DM_PRESCALER == 64
#define DM_CS				4
#else
#error Bad prescaler setting (DM_PRESCALER)
#endif


/********************
 * global variables *
 ********************/

DotMatrix   dm;     // define a dot matrix object

int pause = 2000;   // time to wait after each demo step (in milliseconds)


/*********
 * setup *
 *********/

void setup()
{
	dm.init();

#if		defined (__AVR_ATmega328P__)  || \
		defined (__AVR_ATmega328__)
	// set up timer2 to work as our dot matrix system timer
	// the timer will then issue an interrupt at a frequency given by DM_REFRESH
	ASSR = 0;					// use internal clock
	OCR2A = DM_REFRESH;			// set dot matrix refresh time
	TCCR2A = 0;					// normal mode
	TCCR2B = (DM_CS << CS00);
	TIMSK2 = (1 << OCIE2A);

#elif	defined (__AVR_ATtiny84__)  || \
		defined (__AVR_ATtiny84A__)
	// timer1 is used as dot matrix system timer
	OCR1A = DM_REFRESH;			// set dot matrix refresh time
	TCCR1A = 0;					// normal mode
	TCCR1B = (1 << ICNC1)|(0 << ICES1)|(DM_CS << CS00);
	TIMSK1 = (1 << OCIE1A);

#else
	#error incompatible controller type
#endif

	sei();		                // globally enable interrupts

	// display the logo string
	dm.clearScreen();
	dm.displayLogo();
  delay(pause);
}


/*************
 * main loop *
 *************/

void loop()
{
  // here starts the demo sequence

  // show a fixed text which is stored in flash memory
  // first in green... (escape code \x13 chooses green color)
  dm.clearScreen();
  dm.displayText(0, 0, OPAQUE, PSTR("\x13" "Hello World"), FLASH, 0, 80);
  delay(pause);
  
  // ... and then in red (escape code \x1C chooses red color)
  dm.clearScreen();
  dm.displayText(0, 0, OPAQUE, PSTR("\x1C" "Hello World"), FLASH, 0, 80);
//  dm.displayText(0, 0, OPAQUE, PSTR("\n\x01\x1C" "Hello World"), FLASH, 0, 80);
  delay(pause);

/* escape codes for selecting different text colors
\x1C = RED
\x1D = LIGHTRED
\x1E = REDORANGE
\x1F = ORANGE
\x1B = LIGHTORANGE
\x17 = YELLOW
\x13 = GREEN
\x18 = MEDIUMRED
\x1A = MEDIUMORANGE
\x12 = MEDIUMGREEN
\x14 = DARKRED
\x15 = DARKORANGE
\x11 = DARKGREEN
\x10 = BLACK
*/

  // now we use the same text string but display only a portion of it
  // starting from pixel column 27 with a length of 14 pixels which shows "Wor"
  // this time in orange
  dm.clearScreen();
  dm.displayText(0, 0, OPAQUE, PSTR("\x1F" "Hello World"), FLASH, 27, 14);
  delay(pause);

  // with escape codes you can also select a different font
  // \x11 = default ascii font
  // \x12 = bold font
  // \x13 = square font
  // \x14 = font containing some special characters
  dm.clearScreen();
  dm.displayText(0, 0, OPAQUE, PSTR("\x02" "bold"), FLASH, 0, 40);
  delay(pause);
  dm.clearScreen();
  dm.displayText(0, 0, OPAQUE, PSTR("\x03" "square"), FLASH, 0, 40);
  delay(pause);
  dm.clearScreen();
  dm.displayText(0, 0, OPAQUE, PSTR("\x04" "SPECIAL"), FLASH, 0, 40);
  delay(pause);
  dm.clearScreen();
  dm.displayText(0, 0, OPAQUE, PSTR("\x01" "normal"), FLASH, 0, 40);
  delay(pause);

  // now let's display some variables
  char st[10];    // a character array in RAM will hold our string
  
  for (int i = 1; i < 10; i++) {
    #if  defined (__AVR_ATtiny84__)  || \
         defined (__AVR_ATtiny84A__)
      // For an ATtiny84 we cannot use sprintf here due to memory restrictions.
      st[0] = 13;
      st[1] = 0x17;  // color = yellow
      st[2] = 48 + i;
      st[3] = 'm';
      st[4] = 'V';
      st[5] = 0;    // string terminating zero

    #else
      sprintf(st, "\n\x17%dmV", i);   // convert loop variable to string
    #endif

    dm.clearScreen();
    dm.displayText(0, 0, OPAQUE, st, RAM, 0, 40);
    delay(500);
  }
  delay(pause);

  // finally we manipulate single pixels
  dm.clearScreen();
  int x = 0;
  for (int y = 0; y < 8; y++) {
    for (int i = 0; i < 8; i++) {
      if (y & 1) {    // check if y is odd (= least significant bit is set)
        x = 7 - i;
      }
      else {
        x = i;
      }
      dm.setPixel(x, y, MEDIUMORANGE);
      delay(100);
      dm.setPixel(x, y, BLACK);
    }
  }
  delay(pause);
    
}


/**********************
 * interrupt routines *
 **********************/

// dot matrix refresh interrupt

#if		defined (__AVR_ATmega328P__)  || \
		defined (__AVR_ATmega328__)
	ISR(TIMER2_COMPA_vect)
	{
		OCR2A += DM_REFRESH;				// setup next interrupt cycle
		sei();
		dm.update();
	}

#elif	defined (__AVR_ATtiny84__)  || \
		defined (__AVR_ATtiny84A__)
	ISR(TIM1_COMPA_vect)
	{
		OCR1A += DM_REFRESH;				// setup next interrupt cycle
		sei();
		dm.update();
	}

#else
	#error incompatible controller type
#endif
