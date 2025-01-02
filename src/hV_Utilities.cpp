//
// hV_Utilities.cpp
// Library C++ code
// ----------------------------------
//
// Project Pervasive Displays Library Suite
// Based on highView technology
//
// Created by Rei Vilo, 01 Jun 2013
//
// Copyright (c) Rei Vilo, 2010-2025
// Licence All rights reserved
//
// See hV_Utilities.h for references
//
// Release 521: Added getDecimalPlaces
// Release 605: Added scaleValue()
// Release 607: Refactored peripherals
// Release 610: Refactored peripherals
// Release 611: Refactored functions
// Release 700: Refactored screen and board functions
// Release 803: Added types for string and frame-buffer
// Release 806: Added Wire debugging
// Release 900: Improved formatString()
// Release 900: Added new driver library
// Release 900: Consolidated constants
//

// Library header
#include "hV_Utilities.h"
#include "stdarg.h"
#include "stdio.h"

char bufferIn[128];
char bufferOut[128];

STRING_TYPE formatString(const char * format, ...)
{
    char bufferWork[128] = {0};
    // memset(&bufferWork, 0x00, sizeof(bufferOut));

    va_list args;
    va_start(args, format);
    vsnprintf(bufferWork, 127, format, args);
    va_end(args);

    memset(&bufferOut, 0x00, sizeof(bufferOut));
    memcpy(bufferOut, bufferWork, strlen(bufferWork));

#if (STRING_MODE == USE_STRING_OBJECT)

    return String(bufferOut);

#elif (STRING_MODE == USE_CHAR_ARRAY)

    return bufferOut;

#endif // STRING_MODE
}

STRING_TYPE utf2iso(STRING_TYPE s)
{
    uint8_t c;

#if (STRING_MODE == USE_STRING_OBJECT)

    s.toCharArray(bufferIn, s.length() + 1);

#elif (STRING_MODE == USE_CHAR_ARRAY)

    strncpy(bufferIn, s, sizeof(bufferIn));

#endif // STRING_MODE

    memset(&bufferOut, 0x00, sizeof(bufferOut));

    for (uint8_t i = 0; i < strlen(bufferIn); i++)
    {
        c = (uint8_t)bufferIn[i];

        if (c < 0x80)
        {
            bufferOut[strlen(bufferOut)] = c;
        }
        else if (c == 0xc3)
        {
            bufferOut[strlen(bufferOut)] = (bufferIn[++i] + 64);
        }
        else if (c == 0xc2)
        {
            bufferOut[strlen(bufferOut)] = bufferIn[++i];
        }
        else if (c == 0xe2)
        {
            if ((bufferIn[i + 1] == 0x82) && (bufferIn[i + 2] == 0xac))
            {
                bufferOut[strlen(bufferOut)] = 0x80;
                i += 2;
            }
        }
    }
#if (STRING_MODE == USE_STRING_OBJECT)

    return String(bufferOut);

#elif (STRING_MODE == USE_CHAR_ARRAY)

    return bufferOut;

#endif // STRING_MODE
}

