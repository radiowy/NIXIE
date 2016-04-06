#ifndef klawiatura_h
#define klawiatura_h

#include "stm8s_gpio.h"

void klaw(void);

//TYLKO DEKLARACJE ZMIENNYCH Z PLIKU main.c !!!
extern u16 volatile on_disp;			//zmienna aktualnego wy�wietlania   1:wyswietlanie godziny 
extern u16 volatile status_led; 	//status wyswietlania led�w
extern int volatile godzina;		  //wyswietlana godzina
extern int volatile minuta;	    	//wyswietlana minuta

#endif
