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
#include <stdarg.h>




uint8_t rec_buf2[NB_CAR_TO_RECEIVE];
uint8_t rec_buf6[NB_CAR_TO_RECEIVE];
uint8_t rec_buf[NB_CAR_TO_RECEIVE];



void uart2_Init(void);
void uart6_Init(void);

void term_printf(const char* fmt, ...);

void num2str(char *s, unsigned int number, unsigned int base, unsigned int size, int sp);
unsigned int str2num(char *s, unsigned base);

UART_HandleTypeDef Uart2Handle;
UART_HandleTypeDef Uart6Handle;

void uart6_init_buffer();
uint8_t uart6_datas_available();
uint8_t uart6_read();
void uart6_flush_buffer();
void uart6_write(char* toprint, int size);





#endif /* SRC_DRV_DRV_UART_H_ */
