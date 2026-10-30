#include <stdio.h>
#include "esp_system.h"
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
    printf("hello world!\n");
    vTaskDelay(10 * 1000 / portTICK_PERIOD_MS);
    esp_restart();
}
