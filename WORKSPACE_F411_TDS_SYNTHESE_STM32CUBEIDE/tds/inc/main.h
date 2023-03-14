
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H


/* Includes ------------------------------------------------------------------*/

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

#include "stm32f4xx_nucleo.h"
#include "stm32f411xe.h"
#include "stm32f4xx_hal.h"
#include "config.h"

#include "drv_uart.h"
#include "drv_i2c.h"
#include "drv_spi.h"
#include "drv_i2s.h"

#include "SystemClock.h"
#include "timer_duree.h"

#include "stm32_wm5102_init.h"



#include "midi.h"




#define I2Sxext	I2S2ext
#define	I2Sx	SPI2




#endif /* __MAIN_H */


