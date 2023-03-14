/*
 * midi.h
 *
 *  Created on: Mar 23, 2018
 *      Author: kerhoas
 */

#ifndef INC_MIDI_H_
#define INC_MIDI_H_

#include "main.h"

#define 	CHANNEL_MASK	0x0F

#define		CHANNEL_1		0x0
#define		CHANNEL_2		0x1
#define		CHANNEL_3		0x2
#define		CHANNEL_4		0x3
#define		CHANNEL_5		0x4
#define		CHANNEL_6		0x5
#define		CHANNEL_7		0x6
#define		CHANNEL_8		0x7
#define		CHANNEL_9		0x8
#define		CHANNEL_10		0x9
#define		CHANNEL_11		0xa
#define		CHANNEL_12		0xb
#define		CHANNEL_13		0xc
#define		CHANNEL_14		0xd
#define		CHANNEL_15		0xe
#define		CHANNEL_16		0xf

#define		TYPE_MASK			0xF0
#define		SYSTEM_MESSAGE		0xF0
//========================================
// 			3 BYTES MESSAGES
//========================================
// Channel Voice Messages
#define		NOTE_ON				0x90
#define		NOTE_OFF			0x80
#define 	CONTROL_CHANGE		0xB0
#define		PITCH_BEND			0xE0
#define 	AFTERTOUCH			0xA0

// System Common Messages
#define		SONG_POS_POINTER	0xF2


//========================================
// 			2 BYTES MESSAGE
//========================================
// Channel Voice Messages
#define		PROGRAM_CHANGE			0xC0
#define 	CHANNEL_PRESS_AFT		0xD0

// System Common Messages
#define		TIME_CODE_QUARTER_FRAME	0xF1
#define		SONG_SELECT				0xF3

//========================================
// 			1 BYTE MESSAGE
//========================================
// System Common Messages
#define		TUNE_REQUEST		0xF6
#define		EOF_EXCLUSIVE		0xF7

// System Real-Time Messages
#define 	TIMING_CLK			0xF8
#define		START				0xFA
#define		CONTINUE			0xFB
#define		STOP				0xFC
#define 	ACTIVE_SENSING		0xFE
#define		RESET				0xFF
//========================================

typedef struct	 {
	uint8_t channel;
	uint8_t	type;
	uint8_t data1;
	uint8_t data2;
} midi_message_Type;

midi_message_Type midi_mess;


uint8_t MIDI_receive();
uint8_t MIDI_send(uint8_t* mess , uint8_t length);
void MIDI_rcv_cb(uint8_t car);



#endif /* INC_MIDI_H_ */
