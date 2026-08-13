///
/// @file hV_List_Boards.h
/// @brief List of boards for Pervasive Displays Library Suite - Basic edition
///
/// @details Project Pervasive Displays Library Suite
/// @n Based on highView technology
///
/// @n Content
/// * 2- List of pre-configured boards
///     * 2.1 Recommended boards for EPDK-266 and EPDK-Touch, EXT3 and EXT3.1
///     * 2.2 Other boards for EXT3
///     * 2.3 Recommended boards for EPDK-Matter and EXT4
///     * 2.4 Other boards for EXT4
///     * 2.5 Recommended boards for Viewer
///     * 2.6 Deprecated boards
///
/// @date 21 Apr 2026
/// @version 1005
///
/// @copyright (c) Pervasive Displays Inc., 2021-2026
/// @copyright (c) Etigues, 2010-2026
/// @copyright All rights reserved
/// @copyright For exclusive use with Pervasive Displays screens
///
/// * Basic edition: for hobbyists and for basic usage
/// @n Creative Commons Attribution-ShareAlike 4.0 International (CC BY-SA 4.0)
/// @see https://creativecommons.org/licenses/by-sa/4.0/
///
/// @n Consider the Evaluation or Commercial editions for professionals or organisations and for commercial usage
///
/// * Evaluation edition: for professionals or organisations, evaluation only, no commercial usage
/// @n All rights reserved
///
/// * Commercial edition: for professionals or organisations, commercial usage
/// @n All rights reserved
///
/// * Viewer edition: for professionals or organisations
/// @n All rights reserved
///
/// * Documentation
/// @n All rights reserved
///

// SDK
#include "stdint.h"

// Options
#include "hV_List_Options.h"
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
#include "MCC_Library.h"

#if (hV_LIST_OPTIONS_RELEASE < 1000)
#error Required hV_LIST_OPTIONS_ERELEASE 1000
#endif // hV_LIST_OPTIONS_RELEASE

#ifndef hV_LIST_BOARDS_RELEASE
///
/// @brief Release
///
#define hV_LIST_BOARDS_RELEASE 1005

///
/// @brief Not connected pin
///
#define NOT_CONNECTED (PORT_PIN)0xff

///
/// @brief EXT board configuration structure
/// @note
/// * Pins 1 to 10 except pin 8 are common to all EXT boards
/// * Other pins are specific to each EXT board, optional or external
///
struct pins_t
{
    uint8_t scope; ///< BOARD_EXT3 or BOARD_EXT4

    // Common
    // ///< All EXT* pin 1 Black -> +3.3V
    // ///< All EXT* pin 2 Brown -> SPI SCK
    PORT_PIN panelBusy; ///< All EXT* pin 3 Red
    PORT_PIN panelDC; ///< All EXT3 pin 4 Orange
    PORT_PIN panelReset; ///< All EXT3 pin 5 Yellow
    // ///< All EXT* pin 6 Green -> SPI MISO
    // ///< All EXT* pin 7 Blue -> SPI MOSI
    PORT_PIN flashCS; ///< All EXT* except EXT3.2 pin 8 Violet
    PORT_PIN panelCS; ///< All EXT* pin 9 Grey
    // ///< All EXT* pin 10 White -> GROUND
    // End of Common

    // EXT3, EXT3.1 and EXT3-Touch, EXT4 specific
    PORT_PIN panelCSS; ///< EXT3 and EXT3.1 pin 12 Grey2
    PORT_PIN flashCSS; ///< EXT3 pin 20 or EXT3.1 pin 11 Black2
    // ///< EXT3-Touch pin 1 Brown -> I2C SDA
    // ///< EXT3-Touch pin 2 Black -> I2C SCL
    PORT_PIN touchInt; ///< EXT3-Touch pin 3 Red
    PORT_PIN touchReset; ///< EXT3-Touch pin 4 Orange
    PORT_PIN panelPower; ///< Optional EXT3.2 and EXT4 power circuit
    // End of EXT3, EXT3.1 and EXT3-Touch specific

    // External SD-card
    PORT_PIN cardCS; ///< External SD-card board
    PORT_PIN cardDetect; ///< External SD-card board
    // End of External SD-card

    // EXT4 specific
    PORT_PIN button; ///< EXT4 pin 12 Grey
    PORT_PIN ledData; ///< EXT4 pin 13 Violet WS2813C
    // ///< EXT4 pin 14 Blue -> I2C SDA
    // ///< EXT4 pin 15 Green -> I2C SCL
    // ///< EXT4 pin 16 Yellow, see above
    PORT_PIN nfcFD; ///< EXT4 pin 17 Orange NFC NT3H2111_2211 !Field detect, I2C address = 0x55
    PORT_PIN imuInt1; ///< EXT4 pin 18 Red LIS2DH12 !INT2, I2C address = 0x19
    PORT_PIN imuInt2; ///< EXT4 pin 19 Brown LIS2DH12 !INT1, I2C address = 0x19
    PORT_PIN weatherInt; ///< EXT4 pin 20 Black HDC2080 !INT, I2C address = 0x40
    // End of EXT4 specific
};

///
/// @brief Synonym for pins_t
///
#define Board_EXT pins_t
///
/// @name List of EXT boards
///
/// @{
#define BOARD_EXT2 0x20 ///< EXT2 board
#define BOARD_EXT3 0x30 ///< EXT3, EXT3.1 and EXT3.2 boards
#define BOARD_EXT4 0x40 ///< EXT4 board
/// @}

const pins_t ATSAMC21E18A =
{
    .scope = BOARD_EXT3, ///< Extension boards EXT3, EXT3.1, EXT3.2

    ///< All EXT* pin 1 Black -> +3.3V
    ///< All EXT* pin 2 Brown -> SPI SCK GPIO14
    .panelBusy = DISPLAY_BUSY_PIN, ///< All EXT* pin 3 Red -> D0/GPIO2
    .panelDC = DISPLAY_DC_PIN, ///< All EXT* pin 4 Orange -> D1/GPIO3
    .panelReset = DISPLAY_RESET_PIN, ///< All EXT* pin 5 Yellow -> D2/GPIO4
    ///< All EXT* pin 6 Green -> SPI MISO GPIO12
    ///< All EXT* pin 7 Blue -> SPI MOSI GPIO13
    .flashCS = NOT_CONNECTED, ///< All EXT* except EXT3.2 pin 8 Violet -> D3/GPIO5
    .panelCS = NOT_CONNECTED, ///< All EXT* pin 9 Grey -> D4/GPIO6
    .panelCSS = NOT_CONNECTED, ///< EXT3 and EXT3.1 pin 12 Grey2 -> GPIO4
    .flashCSS = NOT_CONNECTED, ///< EXT3 pin 20 or EXT3.1 pin 11 Black2 -> GPIO0
    ///< All EXT* pin 10 White -> GROUND
    ///< EXT3-Touch pin 1 Brown -> I2C SDA GPIO21
    ///< EXT3-Touch pin 2 Black -> I2C SCL GPIO22
    .touchInt = NOT_CONNECTED, ///< EXT3-Touch pin 3 Red -> GPIO10
    .touchReset = NOT_CONNECTED, ///< EXT3-Touch pin 4 Orange -> GPIO9
    .panelPower = NOT_CONNECTED, ///< Optional power circuit
    .cardCS = NOT_CONNECTED, ///< External SD-card board
    .cardDetect = NOT_CONNECTED, ///< External SD-card board

    // EXT4 specific
    .button = NOT_CONNECTED, ///< EXT4 pin 12 Grey
    .ledData = NOT_CONNECTED, ///< EXT4 pin 13 Violet WS2813C
    .nfcFD = NOT_CONNECTED, ///< EXT4 pin 17 Orange NFC NT3H2111_2211 !Field detect, I2C address = 0x55
    .imuInt1 = NOT_CONNECTED, ///< EXT4 pin 18 Red LIS2DH12 !INT2, I2C address = 0x19
    .imuInt2 = NOT_CONNECTED, ///< EXT4 pin 19 Brown LIS2DH12 !INT1, I2C address = 0x19
    .weatherInt = NOT_CONNECTED // EXT4 pin 20 Black HDC2080 !INT, I2C address = 0x40
};

const pins_t ProductIndicatorDisplay = ATSAMC21E18A;



#endif // hV_LIST_BOARDS_RELEASE

