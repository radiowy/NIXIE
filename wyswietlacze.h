#ifndef wyswietlacze_h
#define wyswietlacze_h

#include "stm8s_gpio.h"
#include "cyfry.h"



void jak_wart_cyfry ();
void wysw(void);
void kropki (void);
void w_blinking_digits (u16 temp );
void all_digits (void);
u16 miuty_L (u16 );

//TYLKO DEKLARACJE Z PLIKU main.c !!!

extern void delay(void);
extern u16 volatile on_disp;			//zmienna aktualnego wyœwietlania   1:wyswietlanie godziny 
extern u16 volatile status_led; 	//status wyswietlania ledów
extern int volatile godzina;			//wyswietlana godzina
extern int volatile minuta;				//wyswietlana minuta
extern u16 blink_disp;
extern u16 blinking_digit;	
extern u16 program ;
extern u16 cyfra_wysw;
extern int volatile	akt_s;							//licznik sekund

#define BLINK_ON 200

#endif
