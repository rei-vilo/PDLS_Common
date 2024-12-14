#include "Driver_EPD_Virtual.h"

Driver_EPD_Virtual::Driver_EPD_Virtual(eScreen_EPD_t eScreen_EPD, pins_t board)
{
    u_eScreen_EPD = eScreen_EPD;
    b_pin = board;
}

void Driver_EPD_Virtual::begin()
{
    ;
}

void Driver_EPD_Virtual::updateNormal(FRAMEBUFFER_CONST_TYPE frame,
                                      uint32_t size)
{
    ;
}

void Driver_EPD_Virtual::updateNormal(FRAMEBUFFER_CONST_TYPE frame1, FRAMEBUFFER_CONST_TYPE frame2,
                                      uint32_t size)
{
    ;
}

void Driver_EPD_Virtual::updateNormal(FRAMEBUFFER_CONST_TYPE frameM1, FRAMEBUFFER_CONST_TYPE frameM2,
                                      FRAMEBUFFER_CONST_TYPE frameS1, FRAMEBUFFER_CONST_TYPE frameS2,
                                      uint32_t size)
{
    ;
}

void Driver_EPD_Virtual::updateFast(FRAMEBUFFER_CONST_TYPE frame1, FRAMEBUFFER_CONST_TYPE frame2,
                                    uint32_t size)
{
    ;
}

void Driver_EPD_Virtual::updateFast(FRAMEBUFFER_CONST_TYPE frameM1, FRAMEBUFFER_CONST_TYPE frameM2,
                                    FRAMEBUFFER_CONST_TYPE frameS1, FRAMEBUFFER_CONST_TYPE frameS2,
                                    uint32_t size)
{
    ;
}

// void Driver_EPD_Virtual::COG_reset()
// {
//     ;
// }
//
// void Driver_EPD_Virtual::COG_getDataOTP()
// {
//     ;
// }
//
// void Driver_EPD_Virtual::COG_initial()
// {
//     ;
// }
//
// void Driver_EPD_Virtual::COG_sendImageData()
// {
//     ;
// }
//
// void Driver_EPD_Virtual::COG_update()
// {
//     ;
// }
//
// void Driver_EPD_Virtual::COG_stopDCDC()
// {
//     ;
// }

#if (TOUCH_MODE != USE_TOUCH_NONE)

void Driver_EPD_Virtual::d_getRawTouch(touch_t & touch)
{
    ;
}

bool Driver_EPD_Virtual::d_getInterruptTouch()
{
    return true;
}

#endif // TOUCH_MODE

STRING_CONST_TYPE Driver_EPD_Virtual::reference()
{
    return "";
}
