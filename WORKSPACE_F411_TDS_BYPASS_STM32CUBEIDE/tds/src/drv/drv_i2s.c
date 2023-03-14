/*
 * drv_i2s.c
 *
 *  Created on: 21 juin 2016
 *      Author: kerhoas
 */


#include "drv_i2s.h"


extern uint16_t buf_i2s[2];

I2S_InitTypeDef I2S_InitStructure;

void i2s2_Init(void)
{
	  I2S_Cmd(SPI2, DISABLE);
	  I2S_Cmd(I2S2ext, DISABLE);

	  I2S_InitStructure.I2S_Standard = I2S_Standard_Phillips;
	  I2S_InitStructure.I2S_DataFormat = I2S_DataFormat_16b;
	  I2S_InitStructure.I2S_CPOL = I2S_CPOL_High;
	  I2S_InitStructure.I2S_Mode = I2S_Mode_SlaveRx;

	  I2S_Init(SPI2, &I2S_InitStructure);

	  I2S_FullDuplexConfig(I2S2ext, &I2S_InitStructure); // enable the I2Sx_ext peripheral for Full Duplex mode */


}




//https://my.st.com/public/STe2ecommunities/mcu/Lists/STM32Discovery/Flat.aspx?RootFolder=%2Fpublic%2FSTe2ecommunities%2Fmcu%2FLists%2FSTM32Discovery%2FI%C2%B2S%20on%20STM32F411&FolderCTID=0x01200200770978C69A1141439FE559EB459D75800084C20D8867EAD444A5987D47BE638E0F&currentviews=97
//https://my.st.com/public/STe2ecommunities/mcu/Lists/cortex_mx_stm32/Flat.aspx?RootFolder=https://my.st.com/public/STe2ecommunities/mcu/Lists/cortex_mx_stm32/STM32F427VIT%20I2S%20strange%20desync%20problem&FolderCTID=0x01200200770978C69A1141439FE559EB459D7580009C4E14902C3CDE46A77F0FFD06506F5B&currentviews=340
//https://my.st.com/public/STe2ecommunities/mcu/Lists/STM32Java/Flat.aspx?RootFolder=https%3a%2f%2fmy%2est%2ecom%2fpublic%2fSTe2ecommunities%2fmcu%2fLists%2fSTM32Java%2fHAL%20STM32F427%20Full%20Duplex%20I2S%20problems%20communicating%20with%20Audio%20Codec&FolderCTID=0x01200200770978C69A1141439FE559EB459D758000F9A0E3A95BA69146A17C2E80209ADC21&currentviews=703
// http://www.design-software.de/system/attachments/attached_binaries/000/000/058/original/090_i2s.c?1432329659
/*void i2s2_Init(void)
{

	i2s2_Handle.Instance = SPI2;

//	  __HAL_I2S_DISABLE(&i2s2_Handle);


	  //i2s2_Handle.Init.AudioFreq   = 48000;
	  i2s2_Handle.Init.Mode        = I2S_MODE_SLAVE_RX;//!!!!I2S_MODE_SLAVE_RX;
	  i2s2_Handle.Init.Standard    = I2S_STANDARD_PHILIPS;
	  i2s2_Handle.Init.DataFormat  = I2S_DATAFORMAT_16B;
	  i2s2_Handle.Init.MCLKOutput  = I2S_MCLKOUTPUT_DISABLE;


	i2s2_Handle.Init.AudioFreq = I2S_AUDIOFREQ_48K;
	  i2s2_Handle.Init.ClockSource = I2S_CLOCK_PLL;
	  i2s2_Handle.Init.CPOL        = I2S_CPOL_HIGH; /// !!!!!!!!!! CPOL_HIGH




	  i2s2_Handle.Init.FullDuplexMode = I2S_FULLDUPLEXMODE_ENABLE;

	//i2s2_Handle.Init


	  HAL_I2S_Init(&i2s2_Handle);
	  HAL_I2S_Init(I2SxEXT(i2s2_Handle.Instance));


	//  i2s2_Enable();

	  __HAL_I2S_DISABLE(&i2s2_Handle);

	  __HAL_I2S_CLEAR_OVRFLAG(&i2s2_Handle);
	  __HAL_I2S_CLEAR_UDRFLAG(&i2s2_Handle);


	  	//  __HAL_I2S_CLEAR_FLAG(&i2s2_Handle,I2S_FLAG_TXE);


	 // __HAL_I2S_ENABLE_IT(&i2s2_Handle, I2S_IT_TXE);
	 // __HAL_I2S_ENABLE_IT(&i2s2_Handle, I2S_IT_ERR);

	 // __HAL_SPI_ENABLE_IT(&i2s2_Handle, SPI_IT_RXNE);






}


void i2s2_Enable(void)
{
	__HAL_I2S_ENABLE(&i2s2_Handle);

}
*/
