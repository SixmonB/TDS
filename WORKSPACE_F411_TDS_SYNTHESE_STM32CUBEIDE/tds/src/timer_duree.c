/*

 * TickTimer.c
 *
 *  Created on: Feb 24, 2015
 *      Author: kerhoas
 */

#include "timer_duree.h"

TIM_HandleTypeDef    TimHandle4;
TIM_HandleTypeDef    TimHandle5;


//=========================================================================
//							TIMER 4 INIT
//=========================================================================
void timer4_Init(int period)
{
	unsigned int uwPrescalerValue;
	//Compute the prescaler value to have counter clock equal to 10 KHz */
	uwPrescalerValue = (unsigned int) ((SystemCoreClock / 10000) - 1);
	TimHandle4.Instance = TIM4;
	TimHandle4.Init.Period = 10*period;
	TimHandle4.Init.Prescaler = uwPrescalerValue;
	TimHandle4.Init.ClockDivision = 0;
	TimHandle4.Init.CounterMode = TIM_COUNTERMODE_UP;
	HAL_TIM_Base_Init(&TimHandle4);
}
//=========================================================================
//							TIMER 5 INIT
//=========================================================================
void timer5_Init(int period)
{
	unsigned int uwPrescalerValue;
	//Compute the prescaler value to have counter clock equal to 10 KHz */
	uwPrescalerValue = (unsigned int) ((SystemCoreClock / 10000) - 1);
	TimHandle5.Instance = TIM5;
	TimHandle5.Init.Period = 10*period;//10*period;
	TimHandle5.Init.Prescaler = uwPrescalerValue;
	TimHandle5.Init.ClockDivision = 0;
	TimHandle5.Init.CounterMode = TIM_COUNTERMODE_UP;
	HAL_TIM_Base_Init(&TimHandle5);
}
//=========================================================================
void timer4_Start()
{
	HAL_TIM_Base_Start_IT(&TimHandle4);
}
//=========================================================================
void timer5_Start()
{
	HAL_TIM_Base_Start_IT(&TimHandle5);
}
//=========================================================================
void timer4_change_period(float period)
{
	TIM4->ARR=10000*period;
}
//=========================================================================
void timer5_change_period(float period)
{
	TIM5->ARR=10000*period;
}
//=========================================================================




