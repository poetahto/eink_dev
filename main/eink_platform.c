// Unity build (include all *.c files)
#include "eink.c"

// System headers
#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h" // must be before other freertos headers
#include "freertos/task.h"

// Local header
#include "eink.h"

#define PIN_SCK   12
#define PIN_MOSI  11
#define PIN_RES   10
#define PIN_DC    13
#define PIN_CS    14
#define PIN_BUSY  9      
#define PIN_LIGHT 19

#define MASK_10000000 0x80

////////////////////////////////////////////////////////////////////////////////
// SPI 
//

// NOTE(poe): Wikipedia calls this "bit-flinging" or something. Search "CS Pin"
internal void SYS_SendByteOverBus(u8 value)
{
    // A low CS level tells the other device to start listening
    gpio_set_level(PIN_CS, 0);

    // Write bits one at a time.
    for (u8 i = 0; i < 8; i++)
    {
        gpio_set_level(PIN_SCK, 0); // TODO(poe): What does this do again?

        if (value & MASK_10000000)
        {
            gpio_set_level(PIN_MOSI, 1);
        }
        else
        {
            gpio_set_level(PIN_MOSI, 0);
        }

        gpio_set_level(PIN_SCK, 1);
        value = (value << 1);
    }

    // A high CS level tells the other device the transmission is done
    gpio_set_level(PIN_CS, 1);
}

internal void SYS_SendBusCommand(u8 command)
{
    gpio_set_level(PIN_DC, 0);
    SYS_SendByteOverBus(command);
    gpio_set_level(PIN_DC, 1);
}

internal void SYS_SendBusData(u8 data)
{
    gpio_set_level(PIN_DC, 1);
    SYS_SendByteOverBus(command);
    gpio_set_level(PIN_DC, 1);
}

////////////////////////////////////////////////////////////////////////////////
// Platform-specific API
//

void SYS_Log(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    putc('\n', stdout);
    va_end(args);
}

void SYS_Delay(u16 ms)
{
    vTaskDelay(ms / portTICK_PERIOD_MS);
}

void SYS_SetLightActive(bool isActive)
{
    gpio_set_level(PIN_LIGHT, isActive);
}

////////////////////////////////////////////////////////////////////////////////
// Entrypoint
//

void app_main(void)
{
    gpio_set_direction(PIN_LIGHT, GPIO_MODE_OUTPUT);
    gpio_set_direction(PIN_SCK,   GPIO_MODE_OUTPUT);
    gpio_set_direction(PIN_MOSI,  GPIO_MODE_OUTPUT);
    gpio_set_direction(PIN_RES,   GPIO_MODE_OUTPUT);
    gpio_set_direction(PIN_DC,    GPIO_MODE_OUTPUT);
    gpio_set_direction(PIN_CS,    GPIO_MODE_OUTPUT);
    gpio_set_direction(PIN_BUSY,  GPIO_MODE_INPUT);

    EI_Init();

    while (1)
    {
        EI_Update();
    }
}
