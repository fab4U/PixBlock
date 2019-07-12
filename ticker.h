/*
 * ticker.h
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

#ifndef TICKER_H_
#define TICKER_H_


#include <inttypes.h>
#include "dot_matrix.h"


/*************
 * constants *
 *************/


/********************
 * class definition *
 ********************/

class Ticker
{
public:
	Ticker(const DotMatrix &dm, char* text_buffer, const uint16_t buffer_size);	// constructor
	void clearBuffer();
	void printChar(const char ch);
	void printString(const char* st);
	void printString_P(const char* st);
	void setViewport(const uint8_t x, const uint8_t y, const uint8_t width);
	void clearViewport();
	void setSpeed(const uint8_t speed,const uint8_t delay);
	void start();
	void stop();
	void update();

private:
	static const DotMatrix* dotmatrix;
	char* buffer;				// pointer to text buffer
	uint16_t cursor;			// current cursor position
	uint16_t buffer_max;		// highest buffer index (= buffer size - 1)
	uint16_t ticker_col;		// current ticker column
	uint16_t ticker_timer;		// counter used for ticker timing (0 = ticker off)
	uint8_t vp_x;				// viewport x-position
	uint8_t vp_y;				// viewport y-position
	uint8_t vp_width;			// viewport width
	uint8_t ticker_speed;		// ticker speed (lower nibble) and delay (upper nibble)
};



#endif /* TICKER_H_ */
