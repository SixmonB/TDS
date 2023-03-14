/*
 * keyboard.h
 *
 *  Created on: Apr 3, 2018
 *      Author: kerhoas
 */

#ifndef INC_KEYBOARD_H_
#define INC_KEYBOARD_H_


#include "main.h"

#define	LENGTH_TAB_NOTES	16
uint8_t tab_notes_on[LENGTH_TAB_NOTES];
uint8_t tab_notes_off[LENGTH_TAB_NOTES];

uint8_t val_min_tab(uint8_t* tab, uint8_t Length);
uint8_t val_index_min_tab(uint8_t* tab, uint8_t Length);
void insert_val_tab(uint8_t* tab, uint8_t val, uint8_t Length);
void delete_val_tab( uint8_t* tab, uint8_t val, uint8_t Length);
uint8_t val_max_tab( uint8_t* tab, uint8_t Length);




#endif /* INC_KEYBOARD_H_ */
