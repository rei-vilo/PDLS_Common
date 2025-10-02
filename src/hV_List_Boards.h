///
/// @file hV_List_Boards.h
/// @brief List of boards for Pervasive Displays Library Suite - Basic edition
///
/// @details Project Pervasive Displays Library Suite
/// @n Based on highView technology
///
/// @n Content
/// * 2- List of pre-configured boards
///     * 2.1 Recommended boards
///     * 2.2 Other boards
///     * 2.3 Deprecated boards
///
/// @date 21 Feb 2025
/// @version 904
///
/// @copyright (c) Etigues, 2010-2025
/// @copyright (c) Pervasive Displays Inc., 2021-2025
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

#if (hV_LIST_OPTIONS_RELEASE < 902)
#error Required hV_LIST_OPTIONS_ERELEASE 900
#endif // hV_LIST_OPTIONS_RELEASE

#ifndef hV_LIST_BOARDS_RELEASE
///
/// @brief Release
///
#define hV_LIST_BOARDS_RELEASE 902

///
/// @brief Not connected pin
///
#define NOT_CONNECTED (uint8_t)0xff

#if (USE_EXT_BOARD == BOARD_EXT3)

///
/// @brief EXT3 board configuration structure
/// @note
/// * Pins 1 to 10 are common to all EXT boards
/// * Other pins are specific to each EXT board, optional or external
///
struct pins_t
{
    // Shared
    // Common
    // ///< EXT3 and EXT3.1 pin 1 Black -> +3.3V
    // ///< EXT3 and EXT3.1 pin 2 Brown -> SPI SCK
    uint8_t panelBusy; ///< EXT3 and EXT3.1 pin 3 Red
    uint8_t panelDC; ///< EXT3 and EXT3.1 pin 4 Orange
    uint8_t panelReset; ///< EXT3 and EXT3.1 pin 5 Yellow
    // ///< EXT3 and EXT3.1 pin 6 Green -> SPI MISO
    // ///< EXT3 and EXT3.1 pin 7 Blue -> SPI MOSI
    uint8_t flashCS; ///< EXT3 and EXT3.1 pin 8 Violet
    uint8_t panelCS; ///< EXT3 and EXT3.1 pin 9 Grey
    // ///< EXT3 and EXT3.1 pin 10 White -> GROUND
    // End of Common

    // EXT3, EXT3.1 and EXT3-Touch, EXT4 specific
    uint8_t panelCSS; ///< EXT3 and EXT3.1 pin 12 Grey2
    uint8_t flashCSS; ///< EXT3 pin 20 or EXT3.1 pin 11 Black2
    // ///< EXT3-Touch pin 1 Brown -> I2C SDA
    // ///< EXT3-Touch pin 2 Black -> I2C SCL
    uint8_t touchInt; ///< EXT3-Touch pin 3 Red
    uint8_t touchReset; ///< EXT3-Touch pin 4 Orange
    uint8_t panelPower; ///< Optional power circuit
    // End of EXT3, EXT3.1 and EXT3-Touch specific

    // External SD-card
    uint8_t cardCS; ///< External SD-card board
    uint8_t cardDetect; ///< External SD-card board
    // End of External SD-card
    // End of Shared
};

///
/// @name 2.1 Recommended boards
/// @{

///
/// @brief Arduino Nano Matter with Silicon Labs MGM240P, tested
/// @note Numbers refer to pins
/// @note Recommended board
///
const pins_t boardArduinoNanoMatter =
{
    .panelBusy = 10, ///< EXT3 and EXT3.1 pin 3 Red -> D10
    .panelDC = 9, ///< EXT3 and EXT3.1 pin 4 Orange -> D9
    .panelReset = 8, ///< EXT3 and EXT3.1 pin 5 Yellow -> D8
    .flashCS = 7, ///< EXT3 and EXT3.1 pin 8 Violet -> D7
    .panelCS = 6, ///< EXT3 and EXT3.1 pin 9 Grey -> D6
    .panelCSS = NOT_CONNECTED, ///< EXT3 and EXT3.1 pin 12 Grey2
    .flashCSS = NOT_CONNECTED, ///< EXT3 pin 20 or EXT3.1 pin 11 Black2
    .touchInt = NOT_CONNECTED, ///< EXT3-Touch pin 3 Red
    .touchReset = NOT_CONNECTED, ///< EXT3-Touch pin 4 Orange
    .panelPower = 2, ///< EXT4 pin 20 White power circuit -> D2
    .cardCS = NOT_CONNECTED, ///< External SD-card board
    .cardDetect = NOT_CONNECTED, ///< External SD-card board
};

///
/// @brief Raspberry Pi Pico and Pico W with default RP2040 configuration, tested
/// @note Numbers refer to GPIOs, not pins
/// @see https://github.com/earlephilhower/arduino-pico
/// @note Recommended board
///
const pins_t boardRaspberryPiPico_RP2040 =
{
    .panelBusy = 13, ///< EXT3 and EXT3.1 pin 3 Red -> GP13
    .panelDC = 12, ///< EXT3 and EXT3.1 pin 4 Orange -> GP12
    .panelReset = 11, ///< EXT3 and EXT3.1 pin 5 Yellow -> GP11
    .flashCS = 10, ///< EXT3 and EXT3.1 pin 8 Violet -> GP10
    .panelCS = 17, ///< EXT3 and EXT3.1 pin 9 Grey -> GP17
    .panelCSS = 14, ///< EXT3 and EXT3.1 pin 12 Grey2 -> GP14
    .flashCSS = 15, ///< EXT3 pin 20 or EXT3.1 pin 11 Black2 -> GP15
    .touchInt = 2, ///< EXT3-Touch pin 3 Red -> GP2
    .touchReset = 3, ///< EXT3-Touch pin 4 Orange -> GP3
    .panelPower = NOT_CONNECTED, ///< Optional power circuit
    .cardCS = NOT_CONNECTED, ///< External SD-card board
    .cardDetect = NOT_CONNECTED, ///< External SD-card board
};

///
/// @brief Raspberry Pi Pico 2 default RP2350 configuration, tested
/// @note Numbers refer to GPIOs, not pins
/// @see https://github.com/earlephilhower/arduino-pico
/// @note Recommended board
///
const pins_t boardRaspberryPiPico2_RP2350 = boardRaspberryPiPico_RP2040;

///
/// @brief Adafruit Feather nRF52840 configuration, tested
/// @note Recommended board
///
const pins_t boardFeatherNRF52840 =
{
    .panelBusy = 13, ///< EXT3 and EXT3.1 pin 3 Red -> D13 GPIO13
    .panelDC = 12, ///< EXT3 and EXT3.1 pin 4 Orange -> D12 GPIO12
    .panelReset = 11, ///< EXT3 and EXT3.1 pin 5 Yellow -> D11 GPIO11
    .flashCS = 10, ///< EXT3 and EXT3.1 pin 8 Violet -> D10 GPIO10
    .panelCS = 9, ///< EXT3 and EXT3.1 pin 9 Grey -> D9 GPIO9
    .panelCSS = NOT_CONNECTED, ///< EXT3 and EXT3.1 pin 12 Grey2
    .flashCSS = NOT_CONNECTED, ///< EXT3 pin 20 or EXT3.1 pin 11 Black2
    .touchInt = 5, ///< EXT3-Touch pin 3 Red -> D5 GPIO5
    .touchReset = 6, ///< EXT3-Touch pin 4 Orange -> D6 GPIO6
    .panelPower = NOT_CONNECTED, ///< Optional power circuit
    .cardCS = NOT_CONNECTED, ///< External SD-card board
    .cardDetect = NOT_CONNECTED, ///< External SD-card board
};

///
/// @brief Espressif ESP32-DevKitC
/// @note Numbers refer to GPIOs not pins
/// @note Recommended board
/// @warning Specific SPI port with SCK=14 MISO=12 MOSI=13
///
const pins_t boardESP32DevKitC =
{
    .panelBusy = 27, ///< EXT3 and EXT3.1 pin 3 Red -> GPIO27
    .panelDC = 26, ///< EXT3 and EXT3.1 pin 4 Orange -> GPIO26
    .panelReset = 25, ///< EXT3 and EXT3.1 pin 5 Yellow -> GPIO25
    .flashCS = 33, ///< EXT3 and EXT3.1 pin 8 Violet -> GPIO33
    .panelCS = 32, ///< EXT3 and EXT3.1 pin 9 Grey -> GPIO32
    .panelCSS = 4, ///< EXT3 and EXT3.1 pin 12 Grey2 -> GPIO4
    .flashCSS = 0, ///< EXT3 pin 20 or EXT3.1 pin 11 Black2 -> GPIO0
    .touchInt = 10, ///< EXT3-Touch pin 3 Red -> GPIO10
    .touchReset = 9, ///< EXT3-Touch pin 4 Orange -> GPIO9
    .panelPower = NOT_CONNECTED, ///< Optional power circuit
    .cardCS = NOT_CONNECTED, ///< External SD-card board
    .cardDetect = NOT_CONNECTED, ///< External SD-card board
};

/// @}

///
/// @name 2.2 Other boards
/// @{

/// @}

///
/// @brief Particle Photon 2 board
/// @note Board contributed by user, not officially tested
///
const pins_t boardParticlePhoton2 =
{
    // ///< EXT3.1 pin 1 Black -> +3.3V
    // ///< EXT3.1 pin 2 Brown -> SPI SCK
    .panelBusy = 5, ///< EXT3.1 pin 3 Red -> D5
    .panelDC = 4, ///< EXT3.1 pin 4 Orange -> D4
    .panelReset = 3, ///< EXT3.1 pin 5 Yellow -> D3
    // ///< EXT3.1 pin 6 Green -> SPI MISO
    // ///< EXT3.1 pin 7 Blue -> SPI MOSI
    .flashCS = 2, ///< EXT3.1 pin 8 Violet -> D2
    .panelCS = 18, ///< EXT3.1 pin 9 Grey -> SS
    // ///< EXT3.1 pin 10 White -> GROUND
    .panelCSS = NOT_CONNECTED, ///< EXT3.1 pin 12 Grey2
    .flashCSS = NOT_CONNECTED, ///< EXT3.1 pin 11 Black2
    .touchInt = NOT_CONNECTED, ///< EXT3-Touch pin 3 Red
    .touchReset = NOT_CONNECTED, ///< EXT3-Touch pin 4 Orange
    .panelPower = NOT_CONNECTED, ///< Optional power circuit
    .cardCS = NOT_CONNECTED, ///< External SD-card board
    .cardDetect = NOT_CONNECTED, ///< External SD-card board
};

///
/// @name 2.3 Deprecated boards
/// @{

/// @}

#elif (USE_EXT_BOARD == BOARD_EXT4)

///
/// @brief EXT4 board configuration structure
/// @note
/// * Pins 1 to 10 are common to all EXT boards
/// * Pins 11 to 20 are specific to EXT4 board
/// * Other pins are optional or external
/// @warning Only valid with EXT4 board
///
struct pins_t
{
    // Shared
    // Common
    // ///< EXT3/EXT3-1/EXT4 pin 1 Black -> +3.3V
    // ///< EXT3/EXT3-1/EXT4 pin 2 Brown -> SPI SCK
    uint8_t panelBusy; ///< EXT3/EXT3-1/EXT4 pin 3 Red
    uint8_t panelDC; ///< EXT3/EXT3-1/EXT4 pin 4 Orange
    uint8_t panelReset; ///< EXT3/EXT3-1/EXT4 pin 5 Yellow
    // ///< EXT3/EXT3-1/EXT4 pin 6 Green -> SPI MISO
    // ///< EXT3/EXT3-1/EXT4 pin 7 Blue -> SPI MOSI
    uint8_t flashCS; ///< EXT3/EXT3-1/EXT4 pin 8 Violet
    uint8_t panelCS; ///< EXT3/EXT3-1/EXT4 pin 9 Grey
    // ///< EXT3/EXT3-1/EXT4 pin 10 White -> GROUND
    // End of Common

    // EXT3, EXT3.1 and EXT3-Touch, EXT4 specific
    uint8_t panelCSS; ///< EXT4 not available
    uint8_t flashCSS; ///< EXT4 pin 16 Yellow
    // ///< EXT4 pin 14 Blue -> I2C SDA
    // ///< EXT4 pin 15 Green -> I2C SCL
    uint8_t touchInt; ///< EXT4 not available
    uint8_t touchReset; ///< EXT4 not available
    uint8_t panelPower; ///< EXT4 pin 11 White
    // End of EXT3, EXT3.1 and EXT3-Touch specific

    // SD-card
    uint8_t cardCS; ///< External SD-card board
    uint8_t cardDetect; ///< External SD-card board
    // End of SD-card
    // End of Shared

    // EXT4 specific
    uint8_t button; ///< EXT4 pin 12 Grey
    uint8_t ledData; ///< EXT4 pin 13 Violet WS2813C
    // ///< EXT4 pin 14 Blue -> I2C SDA
    // ///< EXT4 pin 15 Green -> I2C SCL
    // ///< EXT4 pin 16 Yellow, see above
    uint8_t nfcFD; ///< EXT4 pin 17 Orange NFC NT3H2111_2211 !Field detect, I2C address = 0x55
    uint8_t imuInt1; ///< EXT4 pin 18 Red LIS2DH12 !INT2, I2C address = 0x19
    uint8_t imuInt2; ///< EXT4 pin 19 Brown LIS2DH12 !INT1, I2C address = 0x19
    uint8_t weatherInt; ///< EXT4 pin 20 Black HDC2080 !INT, I2C address = 0x40
    // End of EXT4 specific
};

///
/// @name 2.1 Recommended boards
/// @{

///
/// @brief Arduino Nano Matter with Silicon Labs MGM240P, tested
/// @details Variant of boardArduinoNanoMatter with panelPower, button and LED for EXT4
/// @note Numbers refer to pins
/// @note Recommended board
///
const pins_t boardArduinoNanoMatter =
{
    .panelBusy = 10, ///< EXT3 and EXT3-1 pin 3 Red -> D10
    .panelDC = 9, ///< EXT3 and EXT3-1 pin 4 Orange -> D9
    .panelReset = 8, ///< EXT3 and EXT3-1 pin 5 Yellow -> D8
    .flashCS = 7, ///< EXT3 and EXT3-1 pin 8 Violet -> D7
    .panelCS = 6, ///< EXT3 and EXT3-1 pin 9 Grey -> D6

    .panelCSS = NOT_CONNECTED, ///< EXT4 not available
    .flashCSS = 5, ///< EXT3 pin 20 or EXT3-1 pin 11 Black2 -> D5
    .touchInt = NOT_CONNECTED, ///< EXT3-Touch pin 3 Red
    .touchReset = NOT_CONNECTED, ///< EXT3-Touch pin 4 Orange
    .panelPower = 2, ///< EXT4 pin 20 White -> D2
    .cardCS = NOT_CONNECTED, ///< External SD-card board
    .cardDetect = NOT_CONNECTED, ///< External SD-card board

    // EXT4 specific
    .button = 3, // EXT4 pin 12 Grey -> D3
    .ledData = 4, // EXT4 pin 13 Violet WS2813C -> D4
    // ///< EXT4 pin 14 Blue -> I2C SDA
    // ///< EXT4 pin 15 Green -> I2C SCL
    // ///< EXT4 pin 16 Yellow, see above
    .nfcFD = 17, // EXT4 pin 17 Orange NFC NT3H2111_2211 !Field detect, I2C address = 0x55 -> A3
    .imuInt1 = 16, // EXT4 pin 18 Red LIS2DH12 !INT1, I2C address = 0x19 -> A2
    .imuInt2 = 15, // EXT4 pin 19 Brown LIS2DH12 !INT2, I2C address = 0x19 -> A1
    .weatherInt = 14, // EXT4 pin 20 Black HDC2080 !INT, I2C address = 0x40 -> A0
    // End of EXT4 specific
};

///
/// @brief Silicon Labs EFR32xG24 Explorer Kit (xG24-EK2703A) configuration, tested
/// @details Variant of boardSiLabsBG24Explorer with panelPower, button and LED for EXT4
/// @note Numbers refer to pins
/// @note Recommended board
///
const pins_t boardSiLabsBG24Explorer =
{
    .panelBusy = 4, ///< EXT3 and EXT3-1 pin 3 Red -> PC03 D4 4
    .panelDC = 5, ///< EXT3 and EXT3-1 pin 4 Orange -> PC06 D5 5
    .panelReset = 6, ///< EXT3 and EXT3-1 pin 5 Yellow -> PB00 D6 6
    .flashCS = NOT_CONNECTED, ///< EXT3 and EXT3-1 pin 8 Violet
    .panelCS = 13, ///< EXT3 and EXT3-1 pin 9 Grey -> PB03 A6 13
    .panelCSS = NOT_CONNECTED, ///< EXT4 not available
    .flashCSS = NOT_CONNECTED, ///< EXT3 pin 20 or EXT3-1 pin 11 Black2
    .touchInt = NOT_CONNECTED, ///< EXT4 not available
    .touchReset = NOT_CONNECTED, ///< EXT4 not available
    .panelPower = 14, ///< EXT4 pin 20 White -> PB04 A7 14
    .cardCS = NOT_CONNECTED, ///< External SD-card board
    .cardDetect = NOT_CONNECTED, ///< External SD-card board

    // EXT4 specific
    .button = 11, // EXT4 pin 12 Grey -> PB01 A4 11
    .ledData = 12, // EXT4 pin 13 Violet WS2813C -> PB02 A5 12
    // ///< EXT4 pin 14 Blue -> I2C SDA
    // ///< EXT4 pin 15 Green -> I2C SCL
    // ///< EXT4 pin 16 Yellow, see above
    .nfcFD = NOT_CONNECTED, // EXT4 pin 17 Orange NFC NT3H2111_2211 !Field detect, I2C address = 0x55
    .imuInt1 = NOT_CONNECTED, // EXT4 pin 18 Red LIS2DH12 !INT1, I2C address = 0x19
    .imuInt2 = NOT_CONNECTED, // EXT4 pin 19 Brown LIS2DH12 !INT2, I2C address = 0x19
    .weatherInt = NOT_CONNECTED // EXT4 pin 20 Black HDC2080 !INT, I2C address = 0x40
    // End of EXT4 specific
};

///
/// @brief Raspberry Pi Pico and Pico W with default RP2040 configuration, tested
/// @details Variant of boardRaspberryPiPico_RP2040 with panelPower, button and LED for EXT4
/// @note Numbers refer to GPIOs, not pins
/// @see https://github.com/earlephilhower/arduino-pico
/// @note Recommended board
///
const pins_t boardRaspberryPiPico_RP2040 =
{
    .panelBusy = 13, ///< EXT3 and EXT3-1 pin 3 Red -> GP13
    .panelDC = 12, ///< EXT3 and EXT3-1 pin 4 Orange -> GP12
    .panelReset = 11, ///< EXT3 and EXT3-1 pin 5 Yellow -> GP11
    .flashCS = 10, ///< EXT3 and EXT3-1 pin 8 Violet -> GP10

    .panelCS = 17, ///< EXT4 pin 9 Grey -> GP17
    .panelCSS = NOT_CONNECTED, ///< EXT4 not available
    .flashCSS = 6, ///< EXT4 pin 20 Black2 -> GP6
    .touchInt = NOT_CONNECTED, ///< EXT4 not available
    .touchReset = NOT_CONNECTED, ///< EXT4 not available
    .panelPower = 14, ///< EXT4 pin 20 White -> GP14
    .cardCS = NOT_CONNECTED, ///< External SD-card board
    .cardDetect = NOT_CONNECTED, ///< External SD-card board

    // EXT4 specific
    .button = 15, // EXT4 pin 12 Grey -> GP15
    .ledData = 2, // EXT4 pin 13 Violet WS2813C -> GP2
    // ///< EXT4 pin 14 Blue -> I2C SDA
    // ///< EXT4 pin 15 Green -> I2C SCL
    // ///< EXT4 pin 16 Yellow, see above
    .nfcFD = 7, // EXT4 pin 17 Orange NFC NT3H2111_2211 !Field detect, I2C address = 0x55 -> GP7
    .imuInt1 = 8, // EXT4 pin 18 Red LIS2DH12 !INT2, I2C address = 0x19 -> GP8
    .imuInt2 = 9, // EXT4 pin 19 Brown LIS2DH12 !INT1, I2C address = 0x19 -> GP9
    .weatherInt = 3 // EXT4 pin 20 Black HDC2080 !INT, I2C address = 0x40 -> GP3
    // End of EXT4 specific
};

/// @}

///
/// @name 2.2 Other boards
/// @{

/// @}

///
/// @name 2.3 Deprecated boards
/// @{

/// @}

#endif // USE_EXT_BOARD

#endif // hV_LIST_BOARDS_RELEASE

