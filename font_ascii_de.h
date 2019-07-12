/*
 * font_ascii_de.h
 *
 */

/**********************************************************************************

Description:		PixBlock character font

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

#ifndef FONT_ASCII_DE_H
#define FONT_ASCII_DE_H


#define CHAR_BASE_ASCII_DE	32		// character code of first character


// character pixel data
// first byte = character width (must be >= 1)

FLASHDATA ascii_de_chr_032[] = {0x04, 0x00, 0x00, 0x00, 0x00};	// space
FLASHDATA ascii_de_chr_033[] = {0x02, 0x5F, 0x00};	// !
FLASHDATA ascii_de_chr_034[] = {0x04, 0x03, 0x00, 0x03, 0x00};	// "
FLASHDATA ascii_de_chr_035[] = {0x06, 0x14, 0x7F, 0x14, 0x7F, 0x14, 0x00};	// #
FLASHDATA ascii_de_chr_036[] = {0x06, 0x24, 0x2A, 0x7F, 0x2A, 0x12, 0x00};	// $
FLASHDATA ascii_de_chr_037[] = {0x06, 0x23, 0x13, 0x08, 0x64, 0x62, 0x00};	// %
FLASHDATA ascii_de_chr_038[] = {0x06, 0x36, 0x49, 0x56, 0x20, 0x50, 0x00};	// &
FLASHDATA ascii_de_chr_039[] = {0x03, 0x05, 0x03, 0x00};	// '
FLASHDATA ascii_de_chr_040[] = {0x04, 0x1C, 0x22, 0x41, 0x00};	// (
FLASHDATA ascii_de_chr_041[] = {0x04, 0x41, 0x22, 0x1C, 0x00};	// )
FLASHDATA ascii_de_chr_042[] = {0x06, 0x22, 0x14, 0x6B, 0x14, 0x22, 0x00};	// *
FLASHDATA ascii_de_chr_043[] = {0x06, 0x08, 0x08, 0x3E, 0x08, 0x08, 0x00};	// +
FLASHDATA ascii_de_chr_044[] = {0x03, 0x80, 0x60, 0x00};	// ,
FLASHDATA ascii_de_chr_045[] = {0x05, 0x08, 0x08, 0x08, 0x08, 0x00};	// -
FLASHDATA ascii_de_chr_046[] = {0x02, 0x40, 0x00};	// .
FLASHDATA ascii_de_chr_047[] = {0x06, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00};	// /
FLASHDATA ascii_de_chr_048[] = {0x05, 0x3E, 0x41, 0x41, 0x3E, 0x00};	// 0
FLASHDATA ascii_de_chr_049[] = {0x04, 0x42, 0x7F, 0x40, 0x00};	// 1
FLASHDATA ascii_de_chr_050[] = {0x05, 0x62, 0x51, 0x49, 0x46, 0x00};	// 2
FLASHDATA ascii_de_chr_051[] = {0x05, 0x22, 0x41, 0x49, 0x36, 0x00};	// 3
FLASHDATA ascii_de_chr_052[] = {0x05, 0x18, 0x14, 0x12, 0x7F, 0x00};	// 4
FLASHDATA ascii_de_chr_053[] = {0x05, 0x27, 0x45, 0x45, 0x39, 0x00};	// 5
FLASHDATA ascii_de_chr_054[] = {0x05, 0x3C, 0x4A, 0x49, 0x31, 0x00};	// 6
FLASHDATA ascii_de_chr_055[] = {0x05, 0x01, 0x71, 0x0D, 0x03, 0x00};	// 7
FLASHDATA ascii_de_chr_056[] = {0x05, 0x36, 0x49, 0x49, 0x36, 0x00};	// 8
FLASHDATA ascii_de_chr_057[] = {0x05, 0x06, 0x49, 0x29, 0x1E, 0x00};	// 9
FLASHDATA ascii_de_chr_058[] = {0x02, 0x28, 0x00};	// :
FLASHDATA ascii_de_chr_059[] = {0x03, 0x80, 0x68, 0x00};	// ;
FLASHDATA ascii_de_chr_060[] = {0x05, 0x08, 0x14, 0x22, 0x41, 0x00};	// <
FLASHDATA ascii_de_chr_061[] = {0x05, 0x14, 0x14, 0x14, 0x14, 0x00};	// =
FLASHDATA ascii_de_chr_062[] = {0x05, 0x41, 0x22, 0x14, 0x08, 0x00};	// >
FLASHDATA ascii_de_chr_063[] = {0x05, 0x02, 0x51, 0x09, 0x06, 0x00};	// ?
FLASHDATA ascii_de_chr_064[] = {0x06, 0x32, 0x49, 0x79, 0x41, 0x3E, 0x00};	// @
FLASHDATA ascii_de_chr_065[] = {0x05, 0x7E, 0x09, 0x09, 0x7E, 0x00};	// A
FLASHDATA ascii_de_chr_066[] = {0x05, 0x7F, 0x49, 0x49, 0x36, 0x00};	// B
FLASHDATA ascii_de_chr_067[] = {0x05, 0x3E, 0x41, 0x41, 0x22, 0x00};	// C
FLASHDATA ascii_de_chr_068[] = {0x05, 0x7F, 0x41, 0x41, 0x3E, 0x00};	// D
FLASHDATA ascii_de_chr_069[] = {0x05, 0x7F, 0x49, 0x49, 0x41, 0x00};	// E
FLASHDATA ascii_de_chr_070[] = {0x05, 0x7F, 0x09, 0x09, 0x01, 0x00};	// F
FLASHDATA ascii_de_chr_071[] = {0x05, 0x3E, 0x41, 0x49, 0x3A, 0x00};	// G
FLASHDATA ascii_de_chr_072[] = {0x05, 0x7F, 0x08, 0x08, 0x7F, 0x00};	// H
FLASHDATA ascii_de_chr_073[] = {0x04, 0x41, 0x7F, 0x41, 0x00};	// I
FLASHDATA ascii_de_chr_074[] = {0x05, 0x20, 0x40, 0x40, 0x3F, 0x00};	// J
FLASHDATA ascii_de_chr_075[] = {0x05, 0x7F, 0x08, 0x14, 0x63, 0x00};	// K
FLASHDATA ascii_de_chr_076[] = {0x05, 0x7F, 0x40, 0x40, 0x40, 0x00};	// L
FLASHDATA ascii_de_chr_077[] = {0x06, 0x7F, 0x02, 0x0C, 0x02, 0x7F, 0x00};	// M
FLASHDATA ascii_de_chr_078[] = {0x05, 0x7F, 0x06, 0x18, 0x7F, 0x00};	// N
FLASHDATA ascii_de_chr_079[] = {0x05, 0x3E, 0x41, 0x41, 0x3E, 0x00};	// O
FLASHDATA ascii_de_chr_080[] = {0x05, 0x7F, 0x09, 0x09, 0x06, 0x00};	// P
FLASHDATA ascii_de_chr_081[] = {0x05, 0x3E, 0x41, 0x21, 0x5E, 0x00};	// Q
FLASHDATA ascii_de_chr_082[] = {0x05, 0x7F, 0x09, 0x19, 0x66, 0x00};	// R
FLASHDATA ascii_de_chr_083[] = {0x05, 0x26, 0x49, 0x49, 0x32, 0x00};	// S
FLASHDATA ascii_de_chr_084[] = {0x06, 0x01, 0x01, 0x7F, 0x01, 0x01, 0x00};	// T
FLASHDATA ascii_de_chr_085[] = {0x05, 0x3F, 0x40, 0x40, 0x3F, 0x00};	// U
FLASHDATA ascii_de_chr_086[] = {0x06, 0x07, 0x18, 0x60, 0x18, 0x07, 0x00};	// V
FLASHDATA ascii_de_chr_087[] = {0x06, 0x3F, 0x40, 0x38, 0x40, 0x3F, 0x00};	// W
FLASHDATA ascii_de_chr_088[] = {0x06, 0x63, 0x14, 0x08, 0x14, 0x63, 0x00};	// X
FLASHDATA ascii_de_chr_089[] = {0x06, 0x03, 0x04, 0x78, 0x04, 0x03, 0x00};	// Y
FLASHDATA ascii_de_chr_090[] = {0x05, 0x61, 0x59, 0x45, 0x43, 0x00};	// Z
FLASHDATA ascii_de_chr_091[] = {0x04, 0x7F, 0x41, 0x41, 0x00};	// [
FLASHDATA ascii_de_chr_092[] = {0x06, 0x03, 0x04, 0x08, 0x10, 0x60, 0x00};	// backslash
FLASHDATA ascii_de_chr_093[] = {0x04, 0x41, 0x41, 0x7F, 0x00};	// ]
FLASHDATA ascii_de_chr_094[] = {0x04, 0x02, 0x01, 0x02, 0x00};	// ^
FLASHDATA ascii_de_chr_095[] = {0x05, 0x40, 0x40, 0x40, 0x40, 0x00};	// _
FLASHDATA ascii_de_chr_096[] = {0x03, 0x03, 0x04, 0x00};	// `
FLASHDATA ascii_de_chr_097[] = {0x05, 0x20, 0x54, 0x54, 0x78, 0x00};	// a
FLASHDATA ascii_de_chr_098[] = {0x05, 0x7F, 0x44, 0x44, 0x38, 0x00};	// b
FLASHDATA ascii_de_chr_099[] = {0x05, 0x38, 0x44, 0x44, 0x20, 0x00};	// c
FLASHDATA ascii_de_chr_100[] = {0x05, 0x38, 0x44, 0x44, 0x7F, 0x00};	// d
FLASHDATA ascii_de_chr_101[] = {0x05, 0x38, 0x54, 0x54, 0x48, 0x00};	// e
FLASHDATA ascii_de_chr_102[] = {0x05, 0x04, 0x7E, 0x05, 0x01, 0x00};	// f
FLASHDATA ascii_de_chr_103[] = {0x05, 0x18, 0xA4, 0xA4, 0x7C, 0x00};	// g
FLASHDATA ascii_de_chr_104[] = {0x05, 0x7F, 0x08, 0x08, 0x70, 0x00};	// h
FLASHDATA ascii_de_chr_105[] = {0x02, 0x7D, 0x00};	// i
FLASHDATA ascii_de_chr_106[] = {0x04, 0x40, 0x80, 0x7D, 0x00};	// j
FLASHDATA ascii_de_chr_107[] = {0x05, 0x7F, 0x08, 0x14, 0x62, 0x00};	// k
FLASHDATA ascii_de_chr_108[] = {0x04, 0x41, 0x7F, 0x40, 0x00};	// l
FLASHDATA ascii_de_chr_109[] = {0x06, 0x7C, 0x04, 0x78, 0x04, 0x78, 0x00};	// m
FLASHDATA ascii_de_chr_110[] = {0x05, 0x7C, 0x04, 0x04, 0x78, 0x00};	// n
FLASHDATA ascii_de_chr_111[] = {0x05, 0x38, 0x44, 0x44, 0x38, 0x00};	// o
FLASHDATA ascii_de_chr_112[] = {0x05, 0xFC, 0x24, 0x24, 0x18, 0x00};	// p
FLASHDATA ascii_de_chr_113[] = {0x05, 0x18, 0x24, 0x24, 0xFC, 0x00};	// q
FLASHDATA ascii_de_chr_114[] = {0x04, 0x78, 0x04, 0x04, 0x00};	// r
FLASHDATA ascii_de_chr_115[] = {0x05, 0x48, 0x54, 0x54, 0x24, 0x00};	// s
FLASHDATA ascii_de_chr_116[] = {0x05, 0x04, 0x3F, 0x44, 0x44, 0x00};	// t
FLASHDATA ascii_de_chr_117[] = {0x05, 0x3C, 0x40, 0x40, 0x7C, 0x00};	// u
FLASHDATA ascii_de_chr_118[] = {0x06, 0x0C, 0x30, 0x40, 0x30, 0x0C, 0x00};	// v
FLASHDATA ascii_de_chr_119[] = {0x06, 0x3C, 0x40, 0x30, 0x40, 0x3C, 0x00};	// w
FLASHDATA ascii_de_chr_120[] = {0x06, 0x44, 0x28, 0x10, 0x28, 0x44, 0x00};	// x
FLASHDATA ascii_de_chr_121[] = {0x05, 0x1C, 0xA0, 0xA0, 0x7C, 0x00};	// y
FLASHDATA ascii_de_chr_122[] = {0x05, 0x64, 0x54, 0x4C, 0x44, 0x00};	// z
FLASHDATA ascii_de_chr_123[] = {0x04, 0x08, 0x36, 0x41, 0x00};	// {
FLASHDATA ascii_de_chr_124[] = {0x02, 0x7F, 0x00};	// |
FLASHDATA ascii_de_chr_125[] = {0x04, 0x41, 0x36, 0x08, 0x00};	// }
FLASHDATA ascii_de_chr_126[] = {0x06, 0x08, 0x04, 0x08, 0x10, 0x08, 0x00};	// ~
FLASHDATA ascii_de_chr_127[] = {0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};	// del

FLASHDATA ascii_de_chr_162[] = {0x06, 0x1C, 0x22, 0x7F, 0x22, 0x10, 0x00};	// 
FLASHDATA ascii_de_chr_163[] = {0x06, 0x48, 0x3E, 0x49, 0x41, 0x20, 0x00};	// 
FLASHDATA ascii_de_chr_164[] = {0x06, 0x1C, 0x2A, 0x49, 0x49, 0x22, 0x00};	// 
FLASHDATA ascii_de_chr_165[] = {0x06, 0x15, 0x16, 0x7C, 0x16, 0x15, 0x00};	// 

FLASHDATA ascii_de_chr_167[] = {0x06, 0x20, 0x4A, 0x55, 0x29, 0x02, 0x00};	// 

FLASHDATA ascii_de_chr_169[] = {0x06, 0x7F, 0x41, 0x5D, 0x49, 0x7F, 0x00};	// 

FLASHDATA ascii_de_chr_171[] = {0x07, 0x08, 0x14, 0x22, 0x08, 0x14, 0x22, 0x00};	// 
FLASHDATA ascii_de_chr_172[] = {0x05, 0x08, 0x08, 0x08, 0x18, 0x00};	// 

FLASHDATA ascii_de_chr_174[] = {0x06, 0x7F, 0x41, 0x65, 0x51, 0x7F, 0x00};	// 

FLASHDATA ascii_de_chr_176[] = {0x05, 0x06, 0x09, 0x09, 0x06, 0x00};	// 
FLASHDATA ascii_de_chr_177[] = {0x04, 0x24, 0x2E, 0x24, 0x00};	// 
FLASHDATA ascii_de_chr_178[] = {0x04, 0x19, 0x15, 0x12, 0x00};	// 
FLASHDATA ascii_de_chr_179[] = {0x04, 0x11, 0x15, 0x0A, 0x00};	// 

FLASHDATA ascii_de_chr_181[] = {0x05, 0xFC, 0x20, 0x20, 0x1C, 0x00};	// 

FLASHDATA ascii_de_chr_183[] = {0x03, 0x0C, 0x0C, 0x00};	// 

FLASHDATA ascii_de_chr_185[] = {0x04, 0x12, 0x1F, 0x10, 0x00};	// 

FLASHDATA ascii_de_chr_187[] = {0x07, 0x22, 0x14, 0x08, 0x22, 0x14, 0x08, 0x00};	// 

FLASHDATA ascii_de_chr_196[] = {0x05, 0x7D, 0x12, 0x12, 0x7D, 0x00};	// 

FLASHDATA ascii_de_chr_214[] = {0x05, 0x3D, 0x42, 0x42, 0x3D, 0x00};	// 

FLASHDATA ascii_de_chr_220[] = {0x05, 0x3D, 0x40, 0x40, 0x3D, 0x00};	// 

FLASHDATA ascii_de_chr_223[] = {0x05, 0xFE, 0x49, 0x49, 0x36, 0x00};	// 

FLASHDATA ascii_de_chr_228[] = {0x05, 0x21, 0x54, 0x54, 0x79, 0x00};	// 

FLASHDATA ascii_de_chr_246[] = {0x05, 0x39, 0x44, 0x44, 0x39, 0x00};	// 
FLASHDATA ascii_de_chr_247[] = {0x06, 0x08, 0x08, 0x2A, 0x08, 0x08, 0x00};	// 

FLASHDATA ascii_de_chr_252[] = {0x05, 0x3D, 0x40, 0x40, 0x7D, 0x00};	// 




FLASHDATA* const font_ascii_de[] = {
	ascii_de_chr_032, ascii_de_chr_033, ascii_de_chr_034, ascii_de_chr_035,
	ascii_de_chr_036, ascii_de_chr_037, ascii_de_chr_038, ascii_de_chr_039,
	ascii_de_chr_040, ascii_de_chr_041, ascii_de_chr_042, ascii_de_chr_043,
	ascii_de_chr_044, ascii_de_chr_045, ascii_de_chr_046, ascii_de_chr_047,
	ascii_de_chr_048, ascii_de_chr_049, ascii_de_chr_050, ascii_de_chr_051,
	ascii_de_chr_052, ascii_de_chr_053, ascii_de_chr_054, ascii_de_chr_055,
	ascii_de_chr_056, ascii_de_chr_057, ascii_de_chr_058, ascii_de_chr_059,
	ascii_de_chr_060, ascii_de_chr_061, ascii_de_chr_062, ascii_de_chr_063,
	ascii_de_chr_064, ascii_de_chr_065, ascii_de_chr_066, ascii_de_chr_067,
	ascii_de_chr_068, ascii_de_chr_069, ascii_de_chr_070, ascii_de_chr_071,
	ascii_de_chr_072, ascii_de_chr_073, ascii_de_chr_074, ascii_de_chr_075,
	ascii_de_chr_076, ascii_de_chr_077, ascii_de_chr_078, ascii_de_chr_079,
	ascii_de_chr_080, ascii_de_chr_081, ascii_de_chr_082, ascii_de_chr_083,
	ascii_de_chr_084, ascii_de_chr_085, ascii_de_chr_086, ascii_de_chr_087,
	ascii_de_chr_088, ascii_de_chr_089, ascii_de_chr_090, ascii_de_chr_091,
	ascii_de_chr_092, ascii_de_chr_093, ascii_de_chr_094, ascii_de_chr_095,
	ascii_de_chr_096, ascii_de_chr_097, ascii_de_chr_098, ascii_de_chr_099,
	ascii_de_chr_100, ascii_de_chr_101, ascii_de_chr_102, ascii_de_chr_103,
	ascii_de_chr_104, ascii_de_chr_105, ascii_de_chr_106, ascii_de_chr_107,
	ascii_de_chr_108, ascii_de_chr_109, ascii_de_chr_110, ascii_de_chr_111,
	ascii_de_chr_112, ascii_de_chr_113, ascii_de_chr_114, ascii_de_chr_115,
	ascii_de_chr_116, ascii_de_chr_117, ascii_de_chr_118, ascii_de_chr_119,
	ascii_de_chr_120, ascii_de_chr_121, ascii_de_chr_122, ascii_de_chr_123,
	ascii_de_chr_124, ascii_de_chr_125, ascii_de_chr_126, ascii_de_chr_127,
	UNDEF           , UNDEF           , UNDEF           , UNDEF           ,
	UNDEF           , UNDEF           , UNDEF           , UNDEF           ,
	UNDEF           , UNDEF           , UNDEF           , UNDEF           ,
	UNDEF           , UNDEF           , UNDEF           , UNDEF           ,
	UNDEF           , UNDEF           , UNDEF           , UNDEF           ,
	UNDEF           , UNDEF           , UNDEF           , UNDEF           ,
	UNDEF           , UNDEF           , UNDEF           , UNDEF           ,
	UNDEF           , UNDEF           , UNDEF           , UNDEF           ,
	UNDEF           , UNDEF           , ascii_de_chr_162, ascii_de_chr_163,
	ascii_de_chr_164, ascii_de_chr_165, UNDEF           , ascii_de_chr_167,
	UNDEF           , ascii_de_chr_169, UNDEF           , ascii_de_chr_171,
	ascii_de_chr_172, UNDEF           , ascii_de_chr_174, UNDEF           ,
	ascii_de_chr_176, ascii_de_chr_177, ascii_de_chr_178, ascii_de_chr_179,
	UNDEF           , ascii_de_chr_181, UNDEF           , ascii_de_chr_183,
	UNDEF           , ascii_de_chr_185, UNDEF           , ascii_de_chr_187,
	UNDEF           , UNDEF           , UNDEF           , UNDEF           ,
	UNDEF           , UNDEF           , UNDEF           , UNDEF           ,
	ascii_de_chr_196, UNDEF           , UNDEF           , UNDEF           ,
	UNDEF           , UNDEF           , UNDEF           , UNDEF           ,
	UNDEF           , UNDEF           , UNDEF           , UNDEF           ,
	UNDEF           , UNDEF           , UNDEF           , UNDEF           ,
	UNDEF           , UNDEF           , ascii_de_chr_214, UNDEF           ,
	UNDEF           , UNDEF           , UNDEF           , UNDEF           ,
	ascii_de_chr_220, UNDEF           , UNDEF           , ascii_de_chr_223,
	UNDEF           , UNDEF           , UNDEF           , UNDEF           ,
	ascii_de_chr_228, UNDEF           , UNDEF           , UNDEF           ,
	UNDEF           , UNDEF           , UNDEF           , UNDEF           ,
	UNDEF           , UNDEF           , UNDEF           , UNDEF           ,
	UNDEF           , UNDEF           , UNDEF           , UNDEF           ,
	UNDEF           , UNDEF           , ascii_de_chr_246, ascii_de_chr_247,
	UNDEF           , UNDEF           , UNDEF           , UNDEF           ,
	ascii_de_chr_252, UNDEF           , UNDEF           , UNDEF           
};


#endif /* FONT_ASCII_DE_H*/
