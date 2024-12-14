///
/// @file hV_Utilities.h
/// @brief Utilities for Pervasive Displays Library Suite - Basic edition
///
/// @details Project Pervasive Displays Library Suite
/// @n Based on highView technology
///
/// @author Rei Vilo
/// @date 21 Nov 2024
/// @version 900
///
/// @copyright (c) Rei Vilo, 2010-2024
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

#if (hV_HAL_PERIPHERALS_RELEASE < 900)
#error Required hV_HAL_PERIPHERALS_RELEASE 900
#endif // hV_HAL_PERIPHERALS_RELEASE

// Boards
#include "hV_List_Boards.h"

#if (hV_LIST_BOARDS_RELEASE < 900)
#error Required hV_LIST_BOARDS_RELEASE 900
#endif // hV_LIST_BOARDS_RELEASE

// Types
#include "hV_List_Types.h"

#if (hV_LIST_TYPES_RELEASE < 900)
#error Required hV_LIST_TYPES_RELEASE 900
#endif // hV_LIST_TYPES_RELEASE

// Constants
#include "hV_List_Constants.h"

#if (hV_LIST_CONSTANTS_RELEASE < 900)
#error Required hV_LIST_CONSTANTS_RELEASE 900
#endif // hV_LIST_CONSTANTS_RELEASE

#ifndef hV_UTILITIES_RELEASE
///
/// @brief Library release number
///
#define hV_UTILITIES_RELEASE 900

///
/// @name Orientation constants
/// @{
///
#define ORIENTATION_PORTRAIT 6 ///< portrait or vertical, higher than large
#define ORIENTATION_LANDSCAPE 7 ///< landscape or horizontal, larger than high
/// @}
///

///
/// @brief Structure for touch
///
struct touch_t
{
    uint16_t x; ///< x coordinate
    uint16_t y; ///< y coordinate
    uint16_t z; ///< z coordinate = pressure
    uint16_t t; ///< event if available, otherwise 0
};

///
/// @name Text format functions
/// @brief Utilities to format float, 64-bit unsigned integer, hexadecimal and period into string
/// @{

///
/// @brief UTF-8 to ISO-8859-1 Converter
/// @param s UTF-8 string, input
/// @return ISO-8859-1 string, output
///
/// @see The Unicode Consortium. The Unicode Standard, Version 6.2.0,
/// (Mountain View, CA: The Unicode Consortium, 2012. ISBN 978-1-936213-07-8)
/// http://www.unicode.org/versions/Unicode6.2.0/
///
STRING_TYPE utf2iso(STRING_TYPE s);

///
/// @brief Format string or char array
/// @details Based on vsprint
/// @param format format with standard codes
/// @param ... list of values
/// @return string or character array with values formatted
/// @note All inputs are const char *, use c_str() on Arduino strings
/// @see http://www.cplusplus.com/reference/cstdio/printf/?kw=printf for codes
///
STRING_TYPE formatString(const char * format, ...);

/// @}

///
/// @name Miscellaneous functions
/// @brief Swap and miscellaneous functions
///
/// @{

// ///
// /// @brief Swap number
// /// @param x first number
// /// @param y second number
// ///
// /// @note Macro more robust than template for some platforms
// ///
// /// @code
// /// template <typename T> T
// /// swap(T &x, T &y)
// /// {
// ///     T w = x;
// ///     x = y;
// ///     y = w;
// /// }
// /// @endcode
// ///
// /// @note `__typeof__` recommended over `typeof`
// ///
// #define swap(x, y) do { __typeof__(x) WORK = x; x = y; y = WORK; } while (0)

///
/// @brief Check value in range
/// @param value value to check
/// @param valueMin range minimum
/// @param valueMax range maximum
/// @return value within range
/// @note Assuming valueMin < valueMax
/// * if value < valueMin, return valueMin
/// * if value > valueMax, return valueMax
/// Otherwise, if valueMin > valueMax, valueMin and valueMax are swapped
///
uint16_t checkRange(uint16_t value, uint16_t valueMin, uint16_t valueMax);
/// @}

#endif // hV_UTILITIES_RELEASE
