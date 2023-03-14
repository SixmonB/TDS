/*
 * keyboard.c
 *
 *  Created on: Apr 3, 2018
 *      Author: kerhoas
 */

#include "keyboard.h"

//========================================================================
uint8_t val_min_tab(uint8_t* tab, uint8_t Length)
{
	int i=0;
	uint8_t val_min=0;

	val_min = tab[0];
	for(i=1 ; i< Length-1; i++)
	{
		if (tab[i]<val_min)
		{	val_min = tab[i]; }
	}
	return val_min;
}
//========================================================================
uint8_t val_index_min_tab(uint8_t* tab, uint8_t Length)
{
	int i=0;
	uint8_t val_min=0;
	uint8_t index = 0;

	val_min = tab[0];
	for(i=1 ; i< Length-1; i++)
	{
		if (tab[i]<val_min)
		{	val_min = tab[i]; index = i; }
	}
	return index;
}
//========================================================================
void insert_val_tab(uint8_t* tab, uint8_t val, uint8_t Length)
{
	tab[val_index_min_tab(tab, Length)] = val;
}
//========================================================================
void delete_val_tab( uint8_t* tab, uint8_t val, uint8_t Length)
{
	int i;
	for(i=0 ; i< Length-1; i++)
	{
		if (tab[i] == val)
		{	tab[i] = 0; }
	}
}
//========================================================================
uint8_t val_max_tab( uint8_t* tab, uint8_t Length)
{
	int i=0;
	uint8_t val_max=0;

	val_max = tab[0];
	for(i=1 ; i< Length-1; i++)
	{
		if (tab[i]>val_max)
		{	val_max = tab[i]; }
	}
	return val_max;
}
//========================================================================
