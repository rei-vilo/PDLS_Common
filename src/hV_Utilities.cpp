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
// Release 902: Improved power management
// Release 902: Simplified touch options
// Release 907: Increased buffer size 
//

// Library header
#include "hV_Utilities.h"
#include "stdarg.h"
#include "stdio.h"

// Buffers for formatString
#define BUFFER_LENGTH 128
char bufferIn[BUFFER_LENGTH];
char bufferOut[BUFFER_LENGTH];

STRING_TYPE formatString(const char * format, ...)
{
    char bufferWork[BUFFER_LENGTH] = {0};
    // memset(&bufferWork, 0x00, sizeof(bufferOut));

    va_list args;
    va_start(args, format);
    vsnprintf(bufferWork, (BUFFER_LENGTH - 1), format, args);
    va_end(args);

    memset(&bufferOut, 0x00, sizeof(bufferOut));
    memcpy(bufferOut, bufferWork, strlen(bufferWork));

    return String(bufferOut);
}

STRING_TYPE utf2iso(STRING_TYPE s)
{
    uint8_t c;

    s.toCharArray(bufferIn, s.length() + 1);

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

    return String(bufferOut);
}

