/*
 * stm32_wm5102_init.c
 *
 *  Created on: 21 juin 2016
 *      Author: kerhoas
 */

#include "stm32_wm5102_init.h"
#include "stm32f4xx_hal_msp.h"
#include "drv_i2c.h"
#define BUFSIZE 100



//extern I2S_HandleTypeDef i2s2_Handle;
// extern uint16_t buf_i2s[2];

DMA_std_InitTypeDef DMA_InitStructure;

uint16_t pingIN[BUFSIZE], pingOUT[BUFSIZE], pongIN[BUFSIZE], pongOUT[BUFSIZE];


//======================================================================

typedef struct BITVAL    // used in function prbs()
{
 unsigned short b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1;
 unsigned short b7:1, b8:1, b9:1, b10:1, b11:1, b12:1,b13:1;
 unsigned short dweebie:2; //Fills the 2 bit hole - bits 14-15
} bitval;

typedef union SHIFT_REG
{
 unsigned short regval;
 bitval bt;
} shift_reg;
int fb = 1;                        // feedback variable
shift_reg sreg = {0xFFFF};         // shift register

//======================================================================

short prbs(void) 			       //gen pseudo-random sequence {-1,1}
{
  int prnseq;
  if(sreg.bt.b0)
	prnseq = -NOISELEVEL;		           //scaled negative noise level
  else
	prnseq = NOISELEVEL;		           //scaled positive noise level
  fb =(sreg.bt.b0)^(sreg.bt.b1);   //XOR bits 0,1
  fb^=(sreg.bt.b11)^(sreg.bt.b13); //with bits 11,13 -> fb
  sreg.regval<<=1;
  sreg.bt.b0=fb;			       //close feedback path
  return prnseq;			       //return noise sequence value
}

//======================================================================

uint16_t pingIN[BUFSIZE], pingOUT[BUFSIZE], pongIN[BUFSIZE], pongOUT[BUFSIZE];

__IO uint8_t OutputDev = 0;

//__IO uint32_t CODECTimeout = CODEC_LONG_TIMEOUT;

//=======================================================================

uint32_t Codec_WriteRegister(uint32_t RegisterAddr, uint16_t RegisterValue)
{
	i2c1_WriteReg32Word16((W5102_ADDR_0<<1), RegisterAddr, RegisterValue);
	return 0;
}

//=======================================================================
//======================================================================

void configure_codec(uint16_t fs, int select_input)
{

	Codec_WriteRegister(0x0000, 0x0000);   // reset codec
	HAL_Delay(100);                    // may or may not need delay here

	Codec_WriteRegister(0x0019, 0x0001);   // patch codec (supplied by Wolfson)
	Codec_WriteRegister(0x0080, 0x0003);
	Codec_WriteRegister(0x0081, 0xE022);
	Codec_WriteRegister(0x0410, 0x6080);
	Codec_WriteRegister(0x0418, 0xa080);
	Codec_WriteRegister(0x0420, 0xa080);
	Codec_WriteRegister(0x0428, 0xE000);
	Codec_WriteRegister(0x0443, 0xDC1A);
	Codec_WriteRegister(0x04B0, 0x0066);
	Codec_WriteRegister(0x0458, 0x000B);
	Codec_WriteRegister(0x0212, 0x0000);
	Codec_WriteRegister(0x0171, 0x0000);
	Codec_WriteRegister(0x035E, 0x000C);
	Codec_WriteRegister(0x02D4, 0x0000);
	Codec_WriteRegister(0x0080, 0x0000);  // end of patch

	HAL_Delay(20);

	Codec_WriteRegister(0x192, 0x8008);   // FLL2 12.000 MHz MCLK1 -> 24.576 MHz SYSCLK
	Codec_WriteRegister(0x193, 0x0018);   // could make this part of a switch in order
	Codec_WriteRegister(0x194, 0x007D);   // to allow 44.1kHz-related sample rates
	Codec_WriteRegister(0x195, 0x0008);
	Codec_WriteRegister(0x196, 0x0000);
	Codec_WriteRegister(0x191, 0x0001);

	HAL_Delay(20);                 // may or may not be needed

	Codec_WriteRegister(0x101, 0x0245);   // clock set up as SYSCLK = 24.576 MHz, src FLL2, SYSCLK_FRAC = 0
	                                      // SYSCLK enabled
//------------------------------------------------------------------------
	switch(fs) // set sample rate 1 - currently only 48kHz-related sample rates allowed
	{
		case FS_8000_HZ:
			Codec_WriteRegister(0x102, 0x11);
			Codec_WriteRegister(0x580, 0x26);
		  break;
		case FS_12000_HZ:
			Codec_WriteRegister(0x102, 0x01);
			Codec_WriteRegister(0x580, 0x27);
		  break;
		case FS_16000_HZ:
			Codec_WriteRegister(0x102, 0x12);
			Codec_WriteRegister(0x580, 0x28);
		  break;
		case FS_24000_HZ:
			Codec_WriteRegister(0x102, 0x02);
			Codec_WriteRegister(0x580, 0x29);
		  break;
		case FS_32000_HZ:
			Codec_WriteRegister(0x102, 0x13);
			Codec_WriteRegister(0x580, 0x2A);
		  break;
		case FS_48000_HZ:
			Codec_WriteRegister(0x102, 0x03);
			Codec_WriteRegister(0x580, 0x2B);
		  break;
		default:
			Codec_WriteRegister(0x102, 0x11); // default is 8kHz sample rate
			Codec_WriteRegister(0x580, 0x26);
		  break;
	}
	//------------------------------------------------------------------------
	Codec_WriteRegister(0x458, 0x0009);   // output noise gate enabled, threshold -84dB (important??)

	Codec_WriteRegister(0x200, 0x0001);   // not used prior to 20 March but I think necessary for CP2/LDO2 - analog inputs
                                        // Wolfson example write 0x0007 but bit 0 is CP2_ENA
	Codec_WriteRegister(0x210, 0x00D5);   // LDO1 control 0x00D5 -> LDO1 enabled, normal, 1V2

	Codec_WriteRegister(0x584, 0x0002);   // AIF3 I2S format
	Codec_WriteRegister(0x582, 0x0005);   // AIF3 LRCLK master - this takes LRC high, reliably I hope...
	HAL_Delay(20);
	I2S_Cmd(SPI2, ENABLE); //i2s2_Enable();// __HAL_I2S_ENABLE(&);// !!!!!!!!!!!!!!!!!!!!!!!!!!//I2S_Cmd(SPI2, ENABLE);                // ...because it's necessary for correct startup of STM32F4
	I2S_Cmd(I2S2ext, ENABLE); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!//I2S_Cmd(I2S2ext, ENABLE);             // I2S interface (STM32F4 I2S module MUST be enabled while
	HAL_Delay(20);                    // LRC is high - as per October 2013 errata)

	Codec_WriteRegister(0x587, 0x1010);   // AIF3 TX WL and SLOT_LEN both 16-bit
	Codec_WriteRegister(0x588, 0x1010);   // AIF3 RX WL and SLOT_LEN both 16-bit
	Codec_WriteRegister(0x59A, 0x0003);   // enable AIF3 RX channels (L and R)
	Codec_WriteRegister(0x599, 0x0003);   // enable AIF3 TX channels (L and R)
	Codec_WriteRegister(0x585, 0x0020);   // AIF3 32 BCLK cycles per LRC TX frame
	Codec_WriteRegister(0x586, 0x0020);   // AIF3 32 BCLK cycles per LRC RX frame

                                      // LINE OUT and HP OUT enabled in parallel
	Codec_WriteRegister(0x690, 0x0030); // OUT2L (LINE OUT) mixer input is AIF3 RX1 (from I2S) 30
	Codec_WriteRegister(0x691, 0x0080); // associated volume is 0dB

	Codec_WriteRegister(0x698, 0x0031); // OUT2R (LINE OUT) mixer input is AIF3 RX2 (from I2S) 31
	Codec_WriteRegister(0x699, 0x0080); // associated volume is 0dB

 	Codec_WriteRegister(0x680, 0x0030); // OUT1L (HP OUT) mixer input is AIF3 RX1 (from I2S)
 	Codec_WriteRegister(0x681, 0x0080); // associated volume is 0dB

 	Codec_WriteRegister(0x688, 0x0031); // OUT1R (HP OUT) mixer input is AIF3 RX2 (from I2S)
 	Codec_WriteRegister(0x689, 0x0080); // associated volume is 0dB

// route LHPFs to AIF3TX
 	Codec_WriteRegister(0x0780, 0x0060); // AIF3TX mixer from LHPF1 60
	Codec_WriteRegister(0x0788, 0x0061); // AIF3TX mixer from LHPF2 61
	Codec_WriteRegister(0x0781, 0x0080); // AIF3TX mixer gain 0dB
	Codec_WriteRegister(0x0789, 0x0080); // AIF3TX mixer gain 0dB

	Codec_WriteRegister(0x0EC0, 0x0003); // LHPF1 HPF enabled
	Codec_WriteRegister(0x0EC1, 0xF09e); // LHPF1 cutoff frequency in Hz depends on fs
	Codec_WriteRegister(0x0EC4, 0x0003); // LHPF2 HPF enabled
	Codec_WriteRegister(0x0EC5, 0xF09E); // LHPF2 cutoff frequency in Hz depends on fs

	Codec_WriteRegister(0x0901, 0x0080); // LHPF1 mixer source 1 gain 0dB
	Codec_WriteRegister(0x0909, 0x0080); // LHPF2 mixer source 1 gain 0dB
	//------------------------------------------------------------------------
switch(select_input)
{
	case WM5102_LINE_IN:
		Codec_WriteRegister(0x0900, 0x0014); // LHPF1 mixer from IN3 (LINE IN)
		Codec_WriteRegister(0x0908, 0x0015); // LHPF2 mixer from IN3
		Codec_WriteRegister(0x0300, 0x0030); // enable IN3L and IN3R 0030 LINE IN
		Codec_WriteRegister(0x0320, 0x2290); // IN3L PGA gain +8.0dB LINE IN (potential divider comp.)
		Codec_WriteRegister(0x0321, 0x0280); // IN3L ADC volume 0dB LINE IN
		Codec_WriteRegister(0x0324, 0x0090); // IN3R PGA gain +8.0dB LINE IN (potential divider comp.)
		Codec_WriteRegister(0x0325, 0x0280); // IN3R ADC volume 0dB LINE IN
		break;
	case WM5102_DMIC_IN:
		Codec_WriteRegister(0x0900, 0x0012); // LHPF1 mixer from IN2 (DMIC IN)
		Codec_WriteRegister(0x0908, 0x0013); // LHPF2 mixer from IN2
		Codec_WriteRegister(0x0300, 0x000C); // enable IN2L and IN2R 000C DMIC IN
		Codec_WriteRegister(0x0318, 0x3480); // IN2 DMIC IN IN2L PGA vol 0dB
		Codec_WriteRegister(0x031D, 0x0280); // IN2R ADC volume 0dB DMIC IN
		Codec_WriteRegister(0x0319, 0x0280); // IN2L ADC volume 0dB DMIC IN
		Codec_WriteRegister(0x0219, 0x01A7); // MICBIAS2 enable DMIC IN
		break;
	case WM5102_MIC_IN:
		Codec_WriteRegister(0x0900, 0x0010); // LHPF1 mixer from IN1 (MIC IN)
		Codec_WriteRegister(0x0908, 0x0011); // LHPF2 mixer from IN1
		Codec_WriteRegister(0x0300, 0x0003); // enable IN1L and IN1R 0003 MIC IN
		Codec_WriteRegister(0x0310, 0x2A80); // IN1L PGA vol 0dB MIC IN
		Codec_WriteRegister(0x0314, 0x0080); // IN1R PGA volume 0dB MIC IN
		Codec_WriteRegister(0x0311, 0x0280); // IN1L ADC volume 0dB MIC IN
		Codec_WriteRegister(0x0315, 0x0280); // IN1R ADC volume 0dB DMIC IN
		Codec_WriteRegister(0x0218, 0x01A7); // MICBIAS1 enable MIC IN
		break;
	default:
		Codec_WriteRegister(0x0900, 0x0014); // LHPF1 mixer from IN3 (LINE IN)
	  	Codec_WriteRegister(0x0908, 0x0015); // LHPF2 mixer from IN3
	  	Codec_WriteRegister(0x0300, 0x0030); // enable IN3L and IN3R 0030 LINE IN
	  	Codec_WriteRegister(0x0320, 0x2290); // IN3L PGA gain +8.0dB LINE IN (potential divider comp.)
	  	Codec_WriteRegister(0x0321, 0x0280); // IN3L ADC volume 0dB LINE IN
	  	Codec_WriteRegister(0x0324, 0x0090); // IN3R PGA gain +8.0dB LINE IN (potential divider comp.)
	  	Codec_WriteRegister(0x0325, 0x0280); // IN3R ADC volume 0dB LINE IN
	  	break;
}

		Codec_WriteRegister(0x419, 0x0280); // DAC 2 volume L 0dB (LINE OUT)
		Codec_WriteRegister(0x41D, 0x0280); // DAC 2 volume R 0dB (LINE OUT)
		Codec_WriteRegister(0x411, 0x0280); // DAC 1 volume L 0dB (HP OUT)
		Codec_WriteRegister(0x415, 0x0280); // DAC 1 volume R 0dB (HP OUT)

		Codec_WriteRegister(0x400, 0x000F); // enable outputs OUT2L, OUT2R, OUT1L, OUT1R

}


void stm32_wm5102_init(uint16_t fs, int select_input, int io_method)
{
	//GPIO_SetBits(GPIOC, GPIO_Pin_5); // pi board reset high

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, 0);
	HAL_Delay(500);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, 1);

	configure_codec(fs, select_input);



//------------------------------------------------------
switch(io_method)
{
case IO_METHOD_INTR:
	// do we need to do this?
	SPI_I2S_ClearFlag(SPI2, I2S_FLAG_CHSIDE);
	SPI_I2S_ClearFlag(I2S2ext, I2S_FLAG_CHSIDE);

	// enable the Rx buffer not empty interrupt
	SPI_I2S_ITConfig(SPI2, SPI_I2S_IT_RXNE, ENABLE);




			break;
case IO_METHOD_DMA:
	  __HAL_RCC_DMA1_CLK_ENABLE();

		//RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1, ENABLE);
		DMA_Cmd(DMA1_Stream3,DISABLE);
		DMA_DeInit(DMA1_Stream3);

		DMA_InitStructure.DMA_Channel = DMA_Channel_0;                           // correct channel
		DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;                   // apparently we don't need FIFO ?
		DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;                  // yes
		DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;      // we need 16-bit
		DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;                          // yes (although forced by double-buffer)
		DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;         // no incr on I2S address
		DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;                  // yes
		DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(SPI2_BASE + 0x0C);        // ck address of I2S2
		DMA_InitStructure.DMA_Priority = DMA_Priority_High;                      // yes
		DMA_InitStructure.DMA_BufferSize = BUFSIZE;                              // needs to be 2x no. of sample instants
		DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;        // don't want burst
		DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;        // don't want burst
		DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;            // yes?
		DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord; // should be 16-bit?
		DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t) pingIN;            // do we need type casting?

		DMA_Init(DMA1_Stream3,&DMA_InitStructure);

		DMA_DoubleBufferModeConfig(DMA1_Stream3, (uint32_t) pongIN, DMA_Memory_0);
		DMA_DoubleBufferModeCmd(DMA1_Stream3, ENABLE);
		DMA_InitStructure.DMA_Channel = DMA_Channel_2;                           // correct channel
		DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;                   // apparently we don't need FIFO ?
		DMA_InitStructure.DMA_DIR = DMA_DIR_MemoryToPeripheral;                  // yes
		DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;      // we need 16-bit
		DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;                          // yes (although forced by double-buffer)
		DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;         // no incr on I2S address
		DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;                  // yes
		DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(I2S2ext_BASE + 0x0C);        // check address of I2S2_ext
		DMA_InitStructure.DMA_Priority = DMA_Priority_High;                      // yes
		DMA_InitStructure.DMA_BufferSize = BUFSIZE;                              // needs to be 2x no. of sample instants
		DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;        // don't want burst
		DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;            // yes?
		DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord; // should be 16-bit?
		DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t) pingOUT;            // do we need type casting?

		DMA_Init(DMA1_Stream4,&DMA_InitStructure);

		DMA_DoubleBufferModeConfig(DMA1_Stream4, (uint32_t) pongOUT, DMA_Memory_0);
		DMA_DoubleBufferModeCmd(DMA1_Stream4, ENABLE);

		DMA_ITConfig(DMA1_Stream3, DMA_IT_TC, ENABLE);
		DMA_ITConfig(DMA1_Stream4, DMA_IT_TC, ENABLE);

		SPI_I2S_DMACmd(I2Sx, SPI_I2S_DMAReq_Rx, ENABLE);
		DMA_Cmd(DMA1_Stream3,ENABLE);
		SPI_I2S_DMACmd(I2Sxext, SPI_I2S_DMAReq_Tx, ENABLE);
		DMA_Cmd(DMA1_Stream4,ENABLE);



			break;
default:	break;
}



}





