/**************************************************************************/
/*! 
    @file     aafonts.h
    @author   K. Townsend (microBuilder.eu)

    @section LICENSE

    Software License Agreement (BSD License)

    Copyright (c) 2012, microBuilder SARL
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
    1. Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
    3. Neither the name of the copyright holders nor the
    names of its contributors may be used to endorse or promote products
    derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
/**************************************************************************/
#ifndef __AAFONTS_H__
#define __AAFONTS_H__

#include "projectconfig.h"

typedef enum
{
  AAFONTS_FONTTYPE_AA2 = 2,             /* AA2 Fonts (4 shades of gray) */
  AAFONTS_FONTTYPE_AA4 = 4              /* AA4 Fonts (16 shades of gray) */
} aafontsFontType_t;

typedef struct 
{
  uint8_t width;                        /* Character width in pixels */
  uint8_t bytesPerRow;                  /* Data width in bytes */
  const uint8_t *charData;              /* Pointer to the character data array */
} aafontsCharInfo_t;

typedef struct aafontsFont_s
{
  aafontsFontType_t fontType;           /* Anti-aliasing level for the font */
  uint16_t fontHeight;                  /* Font height in pixels */
  uint16_t unknownCharWidth;            /* Width for unknown characters */
  uint16_t heightUpperCase;             /* Height in pixels of upper case characters */
  uint16_t heightLowerCase;             /* Height in pixels of lower case characters */
  uint16_t baseline;                    /* Font baseline */
  uint16_t firstChar;                   /* Unicode address of the first character in the char map */
  uint16_t lastChar;                    /* Unicode address of the last character in the char map */
  const aafontsCharInfo_t *charTable;   /* Pointer to the aafontsCharInfo_t array containing the char data */
} aafontsFont_t;

// Common color lookup tables for AA2 (4-color anti-aliased) fonts
const uint16_t COLORTABLE_AA2_WHITEONBLACK[4] = { 0x0000, 0x52AA, 0xAD55, 0xFFFF};
const uint16_t COLORTABLE_AA2_BLACKONWHITE[4] = { 0xFFFF, 0xAD55, 0x52AA, 0x0000};

// Common color lookup tables for AA4 (16-color anti-aliased) fonts
const uint16_t COLORTABLE_AA4_WHITEONBLACK[16] = { 0x0000, 0x1082, 0x2104, 0x3186, 0x4208, 0x528A, 0x630C, 0x738E, 0x8410, 0x9492, 0xA514, 0xB596, 0xC618, 0xD69A, 0xE71C, 0xFFFF};
const uint16_t COLORTABLE_AA4_BLACKONWHITE[16] = { 0xFFFF, 0xE71C, 0xD69A, 0xC618, 0xB596, 0xA514, 0x9492, 0x8410, 0x738E, 0x630C, 0x528A, 0x4208, 0x3186, 0x2104, 0x1082, 0x0000};

uint16_t  aafontsBlendColor ( uint16_t bgColor, uint16_t foreColor, uint8_t intensity );
void      aafontsDrawString( uint16_t x, uint16_t y, const uint16_t * colorTable, const aafontsFont_t *font, char *str );
uint16_t  aafontsGetStringWidth( const aafontsFont_t *font, char *str );

#endif