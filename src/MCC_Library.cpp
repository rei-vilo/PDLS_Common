#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
#include "MCC_Library.h"


/*------------------------------------------------------- delay_ms -----
 |  Function delay_ms
 |
 |  Purpose:  Implements a blocking delay for a specified number of milliseconds,
 |            using the RTC Timer32 counter running at 1024 Hz.
 |
 |  Parameters: 
 |             ms (IN) -- The number of milliseconds to delay.
 |
 |  Returns:   None
 *-------------------------------------------------------------------*/

// Delay function using RTC Timer32 counter running at 1024 Hz
void delay_ms(uint32_t ms)
{
#if MICROCONTROLLER == MCU_ATSAMC21E18A
    uint32_t start = RTC_Timer32CounterGet(); // Get current RTC count
    uint32_t ticks_to_wait = (ms * 1024) / 1000; // Convert ms to ticks at 1024 Hz

    while ((RTC_Timer32CounterGet() - start) < ticks_to_wait)
    {
        // wait
    }
#endif
}



/*-------------------------------------------------------- millis -----
 |  Function millis
 |
 |  Purpose:  Returns the number of milliseconds elapsed since the RTC Timer32
 |            counter started running, based on a 1024 Hz tick rate.
 |
 |  Parameters: 
 |             None
 |
 |  Returns:   uint32_t -- Elapsed time in milliseconds.
 *-------------------------------------------------------------------*/
uint32_t millis(void)
{
#if MICROCONTROLLER == MCU_ATSAMC21E18A
    return (RTC_Timer32CounterGet() * 1000U) / 1024U;
#endif
}

void delay_us(uint32_t us)
{
#if MICROCONTROLLER == MCU_ATSAMC21E18A
    uint32_t start = TC0_Timer32bitCounterGet();
    uint32_t ticks_to_wait =
        us * (TC0_TimerFrequencyGet() / 1000000U);

    while ((TC0_Timer32bitCounterGet() - start) < ticks_to_wait)
    {
        /* Wait */
    }
#endif
}

