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

                  The demo displays the PixBlock-Logo, which consists of a rainbow 
                  square followed by the text "PixBlock fab4U".
                  After 2 seconds a scrolling ticker text is continuously displayed 
                  using the first 22 display columns as a viewport.
                  
                  Operation of the PixBlocks, i. e. multiplexing of the display 
                  columns, is done by an interrupt routine which periodically 
                  calls dm.update();
                  For this purpose Timer2 is setup to issue an interrupt at a 
                  rate specified by DM_REFRESH_FREQ.
                  
                  Advancing the scrolling ticker text is achieved by calling 
                  tt.update();
                  This is done in the main loop every 5 ms.
                  

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

DotMatrix   dm;
char        ticker[61];
Ticker      tt(dm, ticker, sizeof(ticker));	      // ticker text

volatile uint16_t	timer;		// software timer counting milliseconds


/*************
 * functions *
 *************/

void wait(uint16_t ms)
{
	uint16_t alarm;

	alarm = timer + (ms << 1) + (ms >> 1);	// alarm = timer + 2.5 * ms
	while (timer != alarm);					// wait on alarm
}


/*********
 * setup *
 *********/

void setup()
{
	dm.init();

#if		defined (__AVR_ATmega328P__)  || \
		defined (__AVR_ATmega328__)
	// timer2 is used as dot matrix system timer
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

	sei();		// enable interrupts

	dm.clearScreen();
	dm.displayLogo();

	wait(2000);

	tt.setViewport(0, 0, 22);
	tt.clearViewport();
	tt.setSpeed(7, 3);
	tt.printString_P(PSTR("\n\x01\x13" "     3..  " "\x17" "2..  " "\x1C" "1..  " "\x1F" "Boom!     "));
	tt.start();
}


/*************
 * main loop *
 *************/

void loop()
{
	wait(5);
	tt.update();
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
		timer++;
		sei();
		dm.update();
	}

#elif	defined (__AVR_ATtiny84__)  || \
		defined (__AVR_ATtiny84A__)
	ISR(TIM1_COMPA_vect)
	{
		OCR1A += DM_REFRESH;				// setup next interrupt cycle
		timer++;
		sei();
		dm.update();
	}

#else
	#error incompatible controller type
#endif
