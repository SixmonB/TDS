#include "stm32f4xx_hal_msp.h"


//=================================================================
#define USART2_IRQ_PRIO 	9
#define I2C1_ER_IRQ_PRIO 	2
#define I2C1_EV_IRQ_PRIO 	11
#define SPI2_IRQ_PRIO		5
#define TIMER4_IRQ_PRIO		3
#define TIMER5_IRQ_PRIO		4
//=================================================================

void HAL_MspInit(void)
{

		HAL_MspDeInit();

	  __GPIOA_CLK_ENABLE();
	  __GPIOB_CLK_ENABLE();
	  __GPIOC_CLK_ENABLE();

	  HAL_UARTCOM_MspInit();
	  HAL_WolfsonReset_MspInit();
	  HAL_timer_MspInit();
	  HAL_GPIO_LED_MspInit();
	  HAL_GPIO_MEASURE_MspInit();
	  HAL_i2c_MspInit();
	  HAL_i2s_MspInit();
#if FIR_DMA_CMSIS_F32 || FIR_DMA_CMSIS_Q15
	  HAL_DMA_MspInit();
#endif
}

void HAL_DMA_MspInit()
{
	__DMA1_CLK_ENABLE();

	  HAL_NVIC_SetPriority(DMA1_Stream3_IRQn, 6, 0);
	  HAL_NVIC_EnableIRQ(DMA1_Stream3_IRQn);
	  HAL_NVIC_SetPriority(DMA1_Stream4_IRQn, 7, 0);
	  HAL_NVIC_EnableIRQ(DMA1_Stream4_IRQn);

}
/******************************************************************
			Mesure temps d'exécution
PC0
*******************************************************************/
void HAL_GPIO_MEASURE_MspInit()
{
	  GPIO_InitTypeDef  GPIO_InitStruct;

	  GPIO_InitStruct.Pin = GPIO_PIN_0;
	  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	  GPIO_InitStruct.Pull = GPIO_PULLUP;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FAST;

	  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
}
/******************************************************************
			Reset WOLFSON
PC5
*******************************************************************/
void HAL_WolfsonReset_MspInit()
{

	  GPIO_InitTypeDef  GPIO_InitStruct;

	  GPIO_InitStruct.Pin = GPIO_PIN_5;
	  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	  GPIO_InitStruct.Pull = GPIO_PULLUP;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FAST;

	  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
}
/******************************************************************
			USART2 : ST-LINK virtual Port
 TX --> PA2
 RX --> PA3
*******************************************************************/
void HAL_UARTCOM_MspInit(void)
{
  GPIO_InitTypeDef  GPIO_InitStruct;

  __GPIOA_CLK_ENABLE();
  __USART2_CLK_ENABLE();

  GPIO_InitStruct.Pin       = GPIO_PIN_2 | GPIO_PIN_3;
  GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull      = GPIO_PULLUP;
  GPIO_InitStruct.Speed     = GPIO_SPEED_LOW;	//GPIO_SPEED_FAST;
  GPIO_InitStruct.Alternate =  GPIO_AF7_USART2;

  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  HAL_NVIC_SetPriority(USART2_IRQn, USART2_IRQ_PRIO, 0); //9
  HAL_NVIC_EnableIRQ(USART2_IRQn);
}
//******************************************************************
//			GPIO LED PA5
//******************************************************************
void HAL_GPIO_LED_MspInit(void)
{
	  GPIO_InitTypeDef  GPIO_InitStruct;

/* Configure PA05 IO in output push-pull mode to drive external LED */
	  GPIO_InitStruct.Pin = GPIO_PIN_5;
	  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	  GPIO_InitStruct.Pull = GPIO_PULLUP;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FAST;

	  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}
/******************************************************************
			I2C - 1
I2C1_SCL	-->	PB8
I2C1_SDA	--> PB9
******************************************************************/
void HAL_i2c_MspInit(void)
{
	  GPIO_InitTypeDef  GPIO_InitStruct;
	  //-----------------------------------------------------------
	  // 						I2C1
	  //-----------------------------------------------------------
	  __I2C1_CLK_ENABLE();

	  GPIO_InitStruct.Pin = GPIO_PIN_8 | GPIO_PIN_9;
	  GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
	  GPIO_InitStruct.Pull = GPIO_NOPULL;
	  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
	  GPIO_InitStruct.Alternate =   GPIO_AF4_I2C1 ; // hal_gpio_ex.h

	  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  	  HAL_NVIC_SetPriority(I2C1_ER_IRQn, I2C1_ER_IRQ_PRIO, 0);
  	  HAL_NVIC_EnableIRQ(I2C1_ER_IRQn);
  	  HAL_NVIC_SetPriority(I2C1_EV_IRQn, I2C1_EV_IRQ_PRIO, 0);
  	  HAL_NVIC_EnableIRQ(I2C1_EV_IRQn);
}
/******************************************************************
			TIMER
******************************************************************/
void HAL_timer_MspInit(void)
{
	__TIM4_CLK_ENABLE();

	HAL_NVIC_SetPriority(TIM4_IRQn, TIMER4_IRQ_PRIO, 0);	//3
	HAL_NVIC_EnableIRQ(TIM4_IRQn);

	__TIM5_CLK_ENABLE();

 	 HAL_NVIC_SetPriority(TIM5_IRQn, TIMER5_IRQ_PRIO, 0);	//4
	 HAL_NVIC_EnableIRQ(TIM5_IRQn);
}
/******************************************************************
			I2S
WS		-->		PB12						(AF SPI2)
CK		-->		PB10 (initialement PB13)	(AF SPI2)
SD		-->		PC3		(AF SPI2)
SDext	-->		PC2		(AF SPI3)

I2S --> SPI2
I2Sext --> I2S2ext
******************************************************************/
void HAL_i2s_MspInit(void)
{
	  GPIO_InitTypeDef  GPIO_InitStruct;

	  __GPIOB_CLK_ENABLE();
	  __GPIOC_CLK_ENABLE();
	  __SPI2_CLK_ENABLE();
	  __SPI3_CLK_ENABLE();

	  GPIO_InitStruct.Pin = GPIO_PIN_12;
	  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;		//GPIO_MODE_AF_PP;
	  GPIO_InitStruct.Pull = GPIO_NOPULL;			//GPIO_PULLUP;
	  GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
	  GPIO_InitStruct.Alternate =   GPIO_AF5_SPI2 ; // hal_gpio_ex.h
	  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	  GPIO_InitStruct.Pin = GPIO_PIN_10;
	  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;		//GPIO_MODE_AF_PP;
	  GPIO_InitStruct.Pull = GPIO_NOPULL;			//GPIO_PULLUP;
	  GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
	  GPIO_InitStruct.Alternate =   GPIO_AF5_SPI2 ; // hal_gpio_ex.h
	  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	  GPIO_InitStruct.Pin = GPIO_PIN_3;
	  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;		//GPIO_MODE_AF_PP;
	  GPIO_InitStruct.Pull = GPIO_NOPULL;			//GPIO_PULLUP;
	  GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
	  GPIO_InitStruct.Alternate =   GPIO_AF5_SPI2 ; // hal_gpio_ex.h
	  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	  GPIO_InitStruct.Pin = GPIO_PIN_2;
	  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;//GPIO_MODE_AF_PP;
	  GPIO_InitStruct.Pull = GPIO_NOPULL;//GPIO_PULLUP;
	  GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
	  GPIO_InitStruct.Alternate =  GPIO_AF6_I2S2ext;// GPIO_AF6_I2S2ext ; // hal_gpio_ex.h
	  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);


#if IO_METHOD==IO_METHOD_INTR
	  HAL_NVIC_SetPriority(SPI2_IRQn, SPI2_IRQ_PRIO, 0);
	  HAL_NVIC_EnableIRQ(SPI2_IRQn);
#endif

}
//=======================================================================

void HAL_MspDeInit(void)
{
	  HAL_NVIC_DisableIRQ(SPI2_IRQn);
	  HAL_NVIC_DisableIRQ(DMA1_Stream3_IRQn);
	  HAL_NVIC_DisableIRQ(DMA1_Stream4_IRQn);

}
