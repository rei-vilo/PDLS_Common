/* 
 * File:   functions.h
 * Author: swalia
 *
 * Created on August 11, 2026, 9:21 AM
 */

#ifndef FUNCTIONS_H
#define	FUNCTIONS_H

#ifdef	__cplusplus
extern "C" {
#endif


enum Level {
  LOW = 0,
  HIGH = 1
};

enum MicrocontrollerList
{
    MCU_ATSAMC21E18A = 0,
    MCU_ATSAMC21E17A,
    MCU_ATSAMC21G18A,
    MCU_ATSAMC21G17A
    // Add more MCUs here
};

#define MICROCONTROLLER MCU_ATSAMC21E18A

//Arduino Bit Compatibility Funtions
#define bitRead(value, bit)   (((value) >> (bit)) & 0x01)
#define bitSet(value, bit)    ((value) |= (1UL << (bit)))
#define bitClear(value, bit)  ((value) &= ~(1UL << (bit)))

#ifdef	__cplusplus
}
#endif

#endif	/* FUNCTIONS_H */

