//***********************************************************************
// Plik: keyb.h 
//
// Zaawansowana obs³uga przycisków i klawiatur 
// Wersja:    1.0
// Licencja:  GPL v2
// Autor:     Deucalion  
// Email:     deucalion#wp.pl
// Szczegó³y: http://mikrokontrolery.blogspot.com/2011/04/jezyk-c-biblioteka-obsluga-klawiatury.html
//
//***********************************************************************

#include "stm8s_gpio.h"

#ifndef keyb_h
#define keyb_h

extern unsigned int x;

#define KEY_PORT GPIOB 				//(GPIO_ReadInputData(GPIOB))
#define KEY0  1  //((GPIO_ReadInputData(GPIOB)) << 1 )
#define KEY1  2  //((GPIO_ReadInputData(GPIOB)) << 2 )
#define KEY2  4  //((GPIO_ReadInputData(GPIOB)) << 3 )//( 1 << PD6 )
#define KEY3  8  //((GPIO_ReadInputData(GPIOB)) << 4 )//( 1 << PD7 )

#define KEY_ENTER  KEY0
#define KEY_ESC    KEY1
#define KEY_UP     KEY2
#define KEY_DOWN   KEY3
#define ANYKEY     (KEY0 | KEY1 | KEY2 | KEY3)
#define KEY_MASK   (KEY0 | KEY1 | KEY2 | KEY3)

#define KBD_LOCK     1
#define KBD_NOLOCK   0

#define KBD_DEFAULT_ART   ((void *)0)

void ClrKeyb( int lock );

unsigned int GetKeys( void );

unsigned int KeysTime( void );

unsigned int IsKeyPressed( unsigned int mask );

unsigned int IsKey( unsigned int mask );

void KeybLock( void );

void KeybSetAutoRepeatTimes( unsigned short * AutoRepeatTab );

void KeybProc( void );

#endif
