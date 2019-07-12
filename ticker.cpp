/*
 * ticker.cpp
 *
 *  Created on: 21.07.2015
 *      Author: Frank Andre
 */

/**********************************************************************************

Description:		Class that implements a ticker text.
					(see www.fab4U.de for details)

Author:				Frank Andre
Copyright 2015:		Frank Andre
License:			see "license.md"
Disclaimer:			This software is provided by the copyright holder "as is" and any
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
#include <avr/pgmspace.h>
//#include <util/atomic.h>

#include "dot_matrix.h"
#include "ticker.h"

#ifdef EEPROM
#include <avr/eeprom.h>
#endif


/**********
 * macros *
 **********/

// Usage: b=swap(a) or b=swap(b)
#define swap(x)                                            \
 ({                                                        \
    unsigned char __x__ = (unsigned char) x;               \
    asm volatile ("swap %0" : "=r" (__x__) : "0" (__x__)); \
    __x__;                                                 \
  })


/**************************
 * static class variables *
 **************************/

const DotMatrix*	Ticker::dotmatrix;


/********
 * data *
 ********/

const uint16_t PROGMEM speed_table[16] = {
		0, 100, 74, 55, 41, 30, 22, 17,
		12, 9, 7, 5, 4, 3, 2, 1
};

const uint16_t PROGMEM delay_table[16] = {
		0, 50, 100, 150, 200, 300, 400, 500,
		600, 800, 1000, 1200, 1400, 1600, 1800, 2000
};


/***********
 * methods *
 ***********/

Ticker::Ticker(const DotMatrix &dm, char* text_buffer, const uint16_t buffer_size)
// A text_buffer of size n can hold n-1 characters.
{
	dotmatrix = &dm;
	buffer = text_buffer;
	buffer_max = buffer_size - 1;
	buffer[buffer_max] = 0;
	clearBuffer();
	setViewport(0, 0, 8);
	ticker_speed = 0;
	ticker_timer = 0;
	// Note: buffer size is MAX_TEXT_BUFFER+1 to ensure that there is always
	//       a terminating zero at the end which will never be overwritten.
}


void Ticker::clearBuffer()
// fill text buffer with zeroes
{
	uint16_t i;

	i = buffer_max;
	while (i) {
		i--;
		buffer[i] = 0;
	}
	cursor = 0;
}


void Ticker::printChar(const char ch)
// <CR> or <LF> clears the text buffer.
// <backspace> goes back one step and deletes character.
// If text buffer is full character is ignored.
{
	if ( (ch == 13) || (ch == 10) ) {		// <CR> or <LF> clears text buffer
		clearBuffer();
		return;
	}

	if (ch == 8) {							// <backspace>
		if (cursor) {
			cursor--;
			buffer[cursor] = 0;
		}
		return;
	}

	if (cursor < buffer_max ) {
		buffer[cursor] = ch;			// ordinary character
		cursor++;
	}
}


void Ticker::printString(const char* st)
// print a zero-terminated string which is stored in RAM
{
	while (*st) {
		printChar(*st);
		st++;
	}
}


void Ticker::printString_P(const char* st)
// print a zero-terminated string which is stored in FLASH memory
{
	char ch;

	ch = pgm_read_byte(st++);
	while (ch) {
		printChar(ch);
		ch = pgm_read_byte(st++);
	}
}


void Ticker::setViewport(const uint8_t x, const uint8_t y, const uint8_t width)
{
	if (x >= DIM_X) { return; }
	if (y >= DIM_Y) { return; }
	if ((x + width) > DIM_X) { return; }

	vp_x = x;
	vp_y = y;
	vp_width = width;
}


void Ticker::clearViewport()
{
	pixcol_t	p;
	uint8_t		i;

	for (i = 0; i < vp_width; i++) {
		p.lsb = 0;
		p.msb = 0;
		dotmatrix->setPixCol(vp_x + i, vp_y, &p, OPAQUE);
	}
}


void Ticker::setSpeed(const uint8_t speed,const uint8_t delay)
{
	ticker_speed = (swap(delay) & 0xF0) | (speed & 0x0F);
}


void Ticker::start()
{
	ticker_col = 0;
	if ( dotmatrix->displayText(vp_x, vp_y, OPAQUE, buffer, RAM, 0, vp_width) ) {
		// ticker text is shorter than viewport width -> no scrolling needed
		ticker_timer = 0;					// turn ticker scrolling off
		return;
	}

	// load ticker timer with speed
	ticker_timer = pgm_read_word(&speed_table[ticker_speed & 0x0F]);
}


void Ticker::stop()
{
	ticker_timer = 0;						// turn ticker scrolling off
}


void Ticker::update()
{
	if (ticker_timer == 0) { return; }		// ticker is off, do nothing

	if (ticker_timer > 1) {					// wait until timer has elapsed
		ticker_timer--;
		return;
	}

	// ticker action
	if ( 1 == dotmatrix->displayText(vp_x, vp_y, OPAQUE, buffer, RAM, ticker_col, vp_width) ) {	// end of ticker reached?
		ticker_col = 0;
		if ((ticker_speed & 0xF0) > 0) {	// delay > 0?
			// reload ticker timer with delay
			ticker_timer = pgm_read_word(&delay_table[swap(ticker_speed) & 0x0F]);
		}
		else {
			// reload ticker timer with speed
			ticker_timer = pgm_read_word(&speed_table[ticker_speed & 0x0F]);
		}
	}
	else {
		ticker_col++;
		// reload ticker timer with speed
		ticker_timer = pgm_read_word(&speed_table[ticker_speed & 0x0F]);
	}
}



