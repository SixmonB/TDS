/*
 * drv_uart.h
 */

#ifndef SRC_DRV_DRV_UART_H_
#define SRC_DRV_DRV_UART_H_

#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>




void uart2_Init(void);
void uart6_Init(void);

void term_printf(const char* fmt, ...);
void term_printf_stlink(const char* fmt, ...);
void term_printf_zigbee(const char* fmt, ...);

UART_HandleTypeDef Uart2Handle;
UART_HandleTypeDef Uart6Handle;


#endif /* SRC_DRV_DRV_UART_H_ */
