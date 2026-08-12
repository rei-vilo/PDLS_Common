//
// hV_HAL_Peripherals.cpp
// Library C++ code
// ----------------------------------
//
// Details Light hardware abstraction layer for peripherals
// Project highView Library Suite
//
// Created by Rei Vilo, 08 Jan 2024
//
// Copyright (c) Etigues, 2010-2026
// Licence All rights reserved
// For exclusive use with Pervasive Displays screens
//
// * Basic edition: for hobbyists and for basic usage
// Creative Commons Attribution-ShareAlike 4.0 International (CC BY-SA 4.0)
//
// * Evaluation edition: for professionals or organisations, evaluation only, no commercial usage
// All rights reserved
//
// * Commercial edition: for professionals or organisations, commercial usage
// All rights reserved
//
// Release 800: Added 3-wire SPI
// Release 801: Added SPI configuration
// Release 803: Improved stability
// Release 804: Improved power management
// Release 805: Improved stability
// Release 900: Shared peripherals
// Release 907: Added patches for ESP32 platform
// Release 908: Fixed SPI settings for ESP32 platform
// Release 909: Added I2C device availability check
// Release 911: Added delay on I²C write and read transfer
// Release 911: Added overtime check on I²C write and read transfer
// Release 922: Improved 3-wire SPI stability
// Release 922: Ported to C
// Release 1000: Updated to PDLS release 1000
// Release 1001: Added delay on I²C write and read transfer
//

// Library header
#include "hV_HAL_Peripherals.h"
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
#include "functions.h"

//
// === General section
//

#ifndef SPI_CLOCK_MAX
#define SPI_CLOCK_MAX 16000000
#endif

void hV_HAL_begin() {
    //hV_HAL_Serial.begin(115200);
    //hV_HAL_Serial_crlf();
    //hV_HAL_log(LEVEL_INFO, "Begin");

    //This section is to setup SPI3 which we dont have. 
}

void hV_HAL_exit(uint8_t code) {
    //hV_HAL_log(LEVEL_INFO, "Exit with code %i", code);
    //hV_HAL_Serial_crlf();
    while (true) {
        hV_HAL_delayMilliseconds(1000);
    }
}
//
// === End of General section
//

//
// === GPIO section
//

void hV_HAL_GPIO_begin() {
    ;
}

void hV_HAL_GPIO_undefine(uint8_t pin) {

}

void hV_HAL_GPIO_waitFor(PORT_PIN pin, uint8_t state) {
    while (hV_HAL_GPIO_get(pin) != state) {
        hV_HAL_delayMilliseconds(32); // non-blocking
    }
}
//
// === End of GPIO section
//

//
// === 3-wire SPI section
//

bool flagSPI3 = false;

void hV_HAL_SPI3_begin()
{
    // MCC has already configured the SPI peripheral.
    flagSPI3 = true;
}

void hV_HAL_SPI3_end()
{
    if (flagSPI3 != false)
    {
        // MCC SPI peripheral remains configured.
        // Add a de-initialization call here if required.
        flagSPI3 = false;
    }
}

void hV_HAL_SPI3_define(uint8_t pinClock, uint8_t pinData)
{
    // Not required when using hardware SPI.
    //
    // The clock/data pins are configured by MCC through
    // the SERCOM peripheral pin configuration.
}

uint8_t hV_HAL_SPI3_read()
{
    uint8_t txData = 0xFF;
    uint8_t rxData = 0;

    SERCOM2_SPI_WriteRead(&txData, 1, &rxData, 1);

    while (SERCOM2_SPI_IsBusy())
    {
        SYS_Tasks();
    }

    return rxData;
}

void hV_HAL_SPI3_write(uint8_t value)
{
    uint8_t rxData = 0;

    SERCOM2_SPI_WriteRead(&value, 1, &rxData, 1);

    while (SERCOM2_SPI_IsBusy())
    {
        SYS_Tasks();
    }
}
//
// === End of 3-wire SPI section
//

//
// === SPI section
//
bool flagSPI = false; // Some SPI implementations require unique initialisation

void hV_HAL_SPI_begin(uint32_t speed) {
    /* Since MCC already configured SPI we can leave this empty for now. 
     * If we want in the future we can use #ifdef then use SERCOMX_SPI_TransferSetup 
     * to manually configure our peripheral in this function*/  
    
    flagSPI = true;
    }


void hV_HAL_SPI_end() {
    if (flagSPI != false) {
        //SPI.end();
        flagSPI = false;
    }
}


uint8_t hV_HAL_SPI_transfer(uint8_t data)
{
    uint8_t rxData = 0;

    SERCOM2_SPI_WriteRead(&data, 1, &rxData, 1);

    while (SERCOM2_SPI_IsBusy())
    {
        SYS_Tasks();
    }

    return rxData;
}

//
// === End of SPI section
//

//
// === Serial section
//

void hV_HAL_Serial_printf(const char * format, ...) {

}

void hV_HAL_Serial_crlf() {

}
//
// === End of Serial section
//

//
// === Log system
//

void hV_HAL_log(uint16_t level, const char * format, ...) {

}
//
// === End of Log system
//

//
// === Miscellaneous section
//

long hV_HAL_map(long x, long in_min, long in_max, long out_min, long out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
//
// === End of Miscellaneous section
//

