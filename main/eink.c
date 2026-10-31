#include "eink.h"

static bool gIsLightActive;

void EI_Init(void)
{
    gIsLightActive = false;
}

void EI_Update(void)
{
    if (gIsLightActive)
    {
        SYS_Log("Turned off light");
        gIsLightActive = false;
        SYS_SetLightActive(false);
    }
    else
    {
        SYS_Log("Turned on light");
        gIsLightActive = true;
        SYS_SetLightActive(true);
    }

    SYS_Delay(5 * 1000);
}

