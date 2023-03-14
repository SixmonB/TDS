/*
 * config.h
 */

#ifndef INC_CONFIG_H_
#define INC_CONFIG_H_

//========================================================
// USART : CHOIX DE LA LIAISON SERIE
// USART2 : USART_STLINK
// USART6 : USART_MIDI
//========================================================
#define	USE_USART_STLINK 1			// A Commenter pour utiliser stlink dans term_printf !! faire une clean
#define NB_CAR_TO_RECEIVE		1		// nombre de caractères à recevoir pour déclencher une interruption
#define USART2_BAUDRATE			115200
#define USART6_BAUDRATE			31250
//========================================================
//					LIAISON I2C
//========================================================
#define I2C1_CLOCKSPEED			60000
#define I2C2_CLOCKSPEED			60000


#endif /* INC_CONFIG_H_ */

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
