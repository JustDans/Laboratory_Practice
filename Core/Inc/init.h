#include <stdint.h>
#include "../../CMSIS/Devices/stm32f4xx.h"
#include "../../CMSIS/Devices/stm32f429xx.h"

#define SET_BIT_CUSTOM(REG,BIT)            (REG|=BIT)

#define GPIOB_MODER_CUSTOM                 *(uint32_t*)(0x40020400UL+0x00UL)
#define GPIOB_OSPEEDR_CUSTOM               *(uint32_t*)(0x40020400UL+0x08UL)

#define GPIOB_MODER_PB8_OUT_CUSTOM         0x01UL<<16UL
#define GPIOB_OPSEEDR_PB8_MID_CUSTOM       0x01UL<<16UL

// #define RCC_GPIO_EN (*(uint32_t*)(0x40023800UL+0x30UL)) 

// #define RCC_GPIOB_EN 0x02UL
// #define RCC_GPIOC_EN 0x04UL
    
// #define GPIOB_MODER (*(uint32_t*)(0x40020400UL+0x00UL))
// #define GPIOB_OTYPER (*(uint32_t*)(0x40020400UL+0x04UL))
// #define GPIOB_OSPEEDR (*(uint32_t*)(0x40020400UL+0x08UL))
// #define GPIOB_PUPDR (*(uint32_t*)(0x40020400UL+0x0CUL))
// #define GPIOB_BSRR (*(uint32_t*)(0x40020400UL+0x18))

// #define GPIOC_IDR (*(uint32_t*)(0x40020800UL+0x10UL))

// #define GPIOB_MODE_PIN7_OUT 0x00004000UL
// #define GPIOB_OTYPE_PIN7_PP 0x00000000UL
// #define GPIOB_OSPEED_PIN7_MID 0x00004000UL
// #define GPIOB_PUPDR_PIN7_NOPUPDR 0x00000000UL
// #define GPIOB_BSRR_PIN7_SET 0x00000080UL
// #define GPIOB_BSRR_PIN7_RESET 0x00800000UL

// #define GPIOC_IDR_PIN13 0x00002000UL

// #define READ_BIT(REG,BIT) (REG&BIT)
// #define SET_BIT(REG,BIT) (REG|=BIT)

void GPIO_Ini(void);