/*
 * stm21_wm5102_init.h
 *
 *  Created on: 21 juin 2016
 *      Author: kerhoas
 */

#ifndef INC_STM32_WM5102_INIT_H_
#define INC_STM32_WM5102_INIT_H_

#include "stm32f4xx_std_spi.h"
#include "stm32f4xx_std_dma.h"

#define WM5102_MIC_IN 0
#define WM5102_LINE_IN 1
#define WM5102_DMIC_IN 2

#define IO_METHOD_INTR 0
#define IO_METHOD_DMA 1
#define IO_METHOD_POLL 2

#define NOISELEVEL 8000

#define W5102_ADDR_0 					0x1a

//#define BUFSIZE 512
#define PING 1
#define PONG 0

#define FS_8000_HZ 0x11
//#define FS_11025_HZ 0x09
#define FS_12000_HZ 0x01
#define FS_16000_HZ 0x12
//#define FS_22050_HZ 0x0A
#define FS_24000_HZ 0x02
#define FS_32000_HZ 0x13
//#define FS_44100_HZ 0x0B
#define FS_48000_HZ 0x03

//==================================================================

//==================================================================
short prbs(void);
void stm32_wm5102_init(uint16_t fs, int select_input, int io_method);


#endif /* INC_STM32_WM5102_INIT_H_ */
