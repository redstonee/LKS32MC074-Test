#include "config.h"
#include "gate_driver.hpp"
#include "lks32mc07x_lib.h"
#include "system_lks32mc07x.h"
#include "Serial.hpp"
int main(void)
{
    GPIO_InitTypeDef gis;
    GPIO_StructInit(&gis);
    gis.GPIO_Mode = GPIO_Mode_OUT;

    gis.GPIO_Pin = GPIO_Pin_0;
    GPIO_Init(GPIO1, &gis);

    gis.GPIO_Pin = EXT_AL_PIN;
    GPIO_Init(EXT_AL_PORT, &gis);

    gis.GPIO_Pin = GPIO_Pin_15;
    gis.GPIO_Mode = GPIO_Mode_IN;
    gis.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIO0, &gis);

    GPIO_PinAFConfig(GPIO0, GPIO_PinSource_15, AF4_UART);
    GPIO_PinAFConfig(GPIO1, GPIO_PinSource_0, AF4_UART);

    HWSerial Serial(UART0, 115200);
    char fuckStr[] = "Fuck The World!";

    while (1)
    {
        static uint8_t fuckCnt = 0;
        GPIO_SetBits(EXT_AL_PORT, EXT_AL_PIN);
        Serial.print(fuckStr);
        Serial.println(fuckCnt++);
        delay1ms(1000);
        // FirmwareDelay(0xffff);
        GPIO_ResetBits(EXT_AL_PORT, EXT_AL_PIN);
        delay1ms(1000);
        // FirmwareDelay(0xffff);
    }
}
