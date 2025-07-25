///
/// @file hV_Board.h
/// @brief Driver for Pervasive Displays EXT3, EXT3.1 and EXT3-Touch boards - Basic edition
///
/// @details Project Pervasive Displays Library Suite
/// @n Based on highView technology
///
/// * Edition: Advanced
///
/// @author Rei Vilo
/// @date 21 Feb 2025
/// @version 906
///
/// @copyright (c) Rei Vilo, 2010-2025
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
#include "hV_HAL_Peripherals.h"

#if (hV_HAL_PERIPHERALS_RELEASE < 902)
#error Required hV_HAL_PERIPHERALS_RELEASE 902
#endif // hV_HAL_PERIPHERALS_RELEASE

// Boards
#include "hV_List_Boards.h"

#if (hV_LIST_BOARDS_RELEASE < 902)
#error Required hV_LIST_BOARDS_RELEASE 902
#endif // hV_LIST_BOARDS_RELEASE

// Constants
#include "hV_List_Constants.h"

#if (hV_LIST_CONSTANTS_RELEASE < 902)
#error Required hV_LIST_CONSTANTS_RELEASE 902
#endif // hV_LIST_CONSTANTS_RELEASE

#ifndef hV_BOARD_RELEASE
///
/// @brief Library release number
///
#define hV_BOARD_RELEASE 902

// Objects
//
///
/// @brief Class for Pervasive Displays EXT3, EXT3.1 and EXT3-Touch, EXT4 extension boards
/// @details Functions for board
/// * GPIO
/// * SPI for LCD and external Flash and SRAM memory
/// * I2C for touch and haptic feedback
///
class hV_Board
{
  public:

    ///
    /// @brief Constructor
    ///
    hV_Board();

  protected:

    /// @cond NOT_PUBLIC
    ///
    /// @brief Initialisation
    /// @param board board configuration
    /// @param family screen family, default = FAMILY_SMALL
    /// @param delayCS delay for /CS, default = 50 ms
    /// @note Typical values are
    /// + FAMILY_SMALL and 0 ms
    /// + FAMILY_MEDIUM and 50 ms
    /// + FAMILY_LARGE and 50 ms
    ///
    void b_begin(pins_t board, uint8_t family = FAMILY_SMALL, uint16_t delayCS = 50);

    ///
    /// @brief General reset
    /// @param ms1 delay for power stabilisation, ms
    /// @param ms2 delay after RESET HIGH, ms
    /// @param ms3 delay after RESET LOW, ms
    /// @param ms4 delay after RESET HIGH, ms
    /// @param ms5 delay after CS_PIN and CSS_PIN HIGH, ms
    ///
    void b_reset(uint32_t ms1, uint32_t ms2, uint32_t ms3, uint32_t ms4, uint32_t ms5);

    ///
    /// @brief Send fixed value through SPI
    /// @param index register
    /// @param data data, one byte covers 8 pixels
    /// @param len number of bytes
    /// @note Valid for all except large screens
    ///
    void b_sendIndexFixed(uint8_t index, uint8_t data, uint32_t len);

    ///
    /// @brief Send fixed value through SPI
    /// @param index register
    /// @param data data, one byte covers 8 pixels
    /// @param len number of bytes
    /// @param select default = PANEL_CS_BOTH, otherwise PANEL_CS_MASTER or PANEL_CS_SLAVE
    /// @note Valid only for 9.7 and 12.20" screens
    ///
    void b_sendIndexFixedSelect(uint8_t index, uint8_t data, uint32_t len, uint8_t select = PANEL_CS_BOTH);

    ///
    /// @brief Send data through SPI
    /// @param index register
    /// @param data data
    /// @param size number of bytes
    /// @note On large screens, b_sendIndexData() sends to both sub-panels
    ///
    void b_sendIndexData(uint8_t index, const uint8_t * data, uint32_t size);

    ///
    /// @brief Send data through SPI to selected half of large screen
    /// @param index register
    /// @param data data
    /// @param size number of bytes
    /// @param select default = PANEL_CS_BOTH, otherwise PANEL_CS_MASTER or PANEL_CS_SLAVE
    /// @note Valid only for 9.7 and 12.20" screens
    ///
    void b_sendIndexDataSelect(uint8_t index, const uint8_t * data, uint32_t size, uint8_t select = PANEL_CS_BOTH);

    ///
    /// @brief Wait for ready
    /// @details Wait for panelBusy signal to reach state
    /// @note Signal is busy until reaching state
    /// @param state to reach HIGH = default, LOW
    ///
    void b_waitBusy(bool state = HIGH);

    ///
    /// @brief Send a command
    /// @param command command
    /// @note panelDC is kept high, to be changed manually after
    ///
    void b_sendCommand8(uint8_t command);

    ///
    /// @brief Send a command and ane byte of data
    /// @param command command
    /// @param data uint8_t data
    /// @note panelDC is kept high, to be changed manually after
    ///
    void b_sendCommandData8(uint8_t command, uint8_t data);

    ///
    /// @brief Send a command and one byte of data to selected half of large screen
    /// @param command command
    /// @param data uint8_t data
    /// @param select default = PANEL_CS_BOTH, otherwise PANEL_CS_MASTER or PANEL_CS_SLAVE
    /// @note panelDC is kept high, to be changed manually after
    ///
    void b_sendCommandDataSelect8(uint8_t command, uint8_t data, uint8_t select = PANEL_CS_BOTH);

    ///
    /// @brief Suspend GPIOs
    /// @details Turn off and set low all GPIOs
    ///
    void b_suspend();

    ///
    /// @brief Resume GPIOs
    /// @details Turn on and configure all GPIOs
    ///
    void b_resume();

    pins_t b_pin;
    uint16_t b_delayCS = 50; // ms
    uint8_t b_family;
    uint8_t b_fsmPowerScreen = FSM_OFF;

  private:

    /// @brief Select one half of large screens
    /// @param select default = PANEL_CS_BOTH, otherwise PANEL_CS_MASTER or PANEL_CS_SLAVE
    /// @note Valid only for 9.69 and 11.98" screens
    ///
    void b_select(uint8_t select = PANEL_CS_BOTH);

    /// @endcond
};

#endif // hV_BOARD_RELEASE

