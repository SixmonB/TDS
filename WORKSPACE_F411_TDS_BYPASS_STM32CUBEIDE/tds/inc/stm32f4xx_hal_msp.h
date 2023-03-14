/*
 * stm32f4xx_hal_msp.h
 */

#ifndef INC_STM32F4XX_HAL_MSP_H_
#define INC_STM32F4XX_HAL_MSP_H_

#include "stm32f4xx_hal.h"
#include "main.h"
#include "stm32f4xx_hal_gpio_ex.h"

void HAL_MspInit(void);
void HAL_UARTCOM_MspInit(void);
void HAL_WolfsonReset_MspInit(void);
void HAL_timer_MspInit(void);
void HAL_GPIO_LED_MspInit(void);
void HAL_i2c_MspInit(void);
void HAL_i2s_MspInit(void);
void HAL_GPIO_MEASURE_MspInit(void);
void HAL_DMA_MspInit(void);


#endif /* INC_STM32F4XX_HAL_MSP_H_ */
