#ifndef EINK_H
#define EINK_H

#include <stdint.h>
#include <stdbool.h>

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;

typedef int8_t  s8;
typedef int16_t s16;
typedef int32_t s32;

#define global static
#define internal static
#define local_persist static

// Platform-specific code

void SYS_Log(const char *format, ...);
void SYS_Delay(u16 ms);
void SYS_SetLightActive(bool isActive);

// Cross-platform logic

void EI_Init(void);
void EI_Update(void);

#endif // EINK_H
