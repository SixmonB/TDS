/*
 * TickTimer.h
 */

#ifndef INC_TICKTIMER_H_
#define INC_TICKTIMER_H_

#include "main.h"

void timer4_Init(int period);
void timer5_Init(int period);
void timer4_Start();
void timer5_Start();
void timer4_change_period(float period);
void timer5_change_period(float period);





#endif /* INC_TICKTIMER_H_ */
