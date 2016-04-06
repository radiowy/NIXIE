#include "stm8s_gpio.h"
#include "stm8s_it.h"


// cyfty wyswietlacza

int jeden (void)  //jedynka
	{
		GPIO_WriteLow(GPIOC, GPIO_PIN_2); //w��czenie segmentu "b" wy�wietlacza
		GPIO_WriteLow(GPIOC, GPIO_PIN_3); //w��czenie segmentu "c" wy�wietlacza		
		GPIO_WriteLow(GPIOA, GPIO_PIN_4);
		GPIO_WriteLow(GPIOA, GPIO_PIN_5);
		GPIO_WriteLow(GPIOA, GPIO_PIN_6);
	}

int dwa (void)  //dw�jka
	{
		GPIO_WriteLow(GPIOC, GPIO_PIN_1); //w��czenie segmentu "b" wy�wietlacza
		GPIO_WriteLow(GPIOC, GPIO_PIN_2); //w��czenie segmentu "b" wy�wietlacza		
		GPIO_WriteLow(GPIOC, GPIO_PIN_7); //w��czenie segmentu "g" wy�wietlacza
		GPIO_WriteLow(GPIOC, GPIO_PIN_5); //w��czenie segmentu "e" wy�wietlacza		
		GPIO_WriteLow(GPIOC, GPIO_PIN_4); //w��czenie segmentu "d" wy�wietlacza		
	}

int trzy (void)  //tr�jka
	{
		GPIO_WriteLow(GPIOC, GPIO_PIN_1); //w��czenie segmentu "b" wy�wietlacza
		GPIO_WriteLow(GPIOC, GPIO_PIN_2); //w��czenie segmentu "b" wy�wietlacza		
		GPIO_WriteLow(GPIOC, GPIO_PIN_7); //w��czenie segmentu "g" wy�wietlacza
		GPIO_WriteLow(GPIOC, GPIO_PIN_3); //w��czenie segmentu "c" wy�wietlacza		
		GPIO_WriteLow(GPIOC, GPIO_PIN_4); //w��czenie segmentu "d" wy�wietlacza		
	}

int cztery(void) //czw�ka
	{
		GPIO_WriteLow(GPIOC, GPIO_PIN_6);
		GPIO_WriteLow(GPIOC, GPIO_PIN_7);
		GPIO_WriteLow(GPIOC, GPIO_PIN_2);
		GPIO_WriteLow(GPIOC, GPIO_PIN_3);
	}

int piec(void) //pi�tka
	{
		GPIO_WriteLow(GPIOC, GPIO_PIN_1);
		GPIO_WriteLow(GPIOC, GPIO_PIN_6);
		GPIO_WriteLow(GPIOC, GPIO_PIN_7);
		GPIO_WriteLow(GPIOC, GPIO_PIN_3);
		GPIO_WriteLow(GPIOC, GPIO_PIN_4);
	}

int szesc(void) //sz�stka
	{
		GPIO_WriteLow(GPIOC, GPIO_PIN_1);
		GPIO_WriteLow(GPIOC, GPIO_PIN_6);
		GPIO_WriteLow(GPIOC, GPIO_PIN_5);
		GPIO_WriteLow(GPIOC, GPIO_PIN_4);
		GPIO_WriteLow(GPIOC, GPIO_PIN_3);
		GPIO_WriteLow(GPIOC, GPIO_PIN_7);
	}

int siedem(void) //si�demka
	{
		GPIO_WriteLow(GPIOC, GPIO_PIN_1);
		GPIO_WriteLow(GPIOC, GPIO_PIN_2);
		GPIO_WriteLow(GPIOC, GPIO_PIN_3);
	}

int osiem(void) //�semka
	{
		GPIO_WriteLow(GPIOC, GPIO_PIN_1);
		GPIO_WriteLow(GPIOC, GPIO_PIN_2);
		GPIO_WriteLow(GPIOC, GPIO_PIN_3);
		GPIO_WriteLow(GPIOC, GPIO_PIN_4);
		GPIO_WriteLow(GPIOC, GPIO_PIN_5);
		GPIO_WriteLow(GPIOC, GPIO_PIN_6);
		GPIO_WriteLow(GPIOC, GPIO_PIN_7);
	}

int dziewiec(void) //dziewi�tka
	{
		GPIO_WriteLow(GPIOC, GPIO_PIN_1);
		GPIO_WriteLow(GPIOC, GPIO_PIN_2);
		GPIO_WriteLow(GPIOC, GPIO_PIN_3);
		GPIO_WriteLow(GPIOC, GPIO_PIN_4);
		GPIO_WriteLow(GPIOC, GPIO_PIN_6);
		GPIO_WriteLow(GPIOC, GPIO_PIN_7);
	}

int zero(void) //zero
	{
		GPIO_WriteLow(GPIOC, GPIO_PIN_1);
		GPIO_WriteLow(GPIOC, GPIO_PIN_2);
		GPIO_WriteLow(GPIOC, GPIO_PIN_3);
		GPIO_WriteLow(GPIOC, GPIO_PIN_4);
		GPIO_WriteLow(GPIOC, GPIO_PIN_5);
		GPIO_WriteLow(GPIOC, GPIO_PIN_6);
	}

void kropka_on (void) //kropka wyswietlacza
	{
		GPIO_WriteLow(GPIOG, GPIO_PIN_0);
	}

void kropka_off (void) //kropka wyswietlacza
	{
		GPIO_WriteHigh(GPIOG, GPIO_PIN_0);
	}

	
int litera_p (void) //litera P   DOKONCZYC ++++++++
	{
		GPIO_WriteLow(GPIOG, GPIO_PIN_0);
		
		
		
	}
	
//za��czenie wy�wietlaczy

void wysw_1_on (void) //wy�wietlacz pierwszy od lewej
	{
		GPIO_WriteLow(GPIOE, GPIO_PIN_0);
	}	
void wysw_2_on (void) //wy�wietlacz drugi od lewej
	{
		GPIO_WriteLow(GPIOE, GPIO_PIN_1);
	}
void wysw_3_on (void) //wy�wietlacz trzeci od lewej
	{
		GPIO_WriteLow(GPIOE, GPIO_PIN_2);
	}
void wysw_4_on (void) //wy�wietlacz czwarty od lewej
	{
		GPIO_WriteLow(GPIOE, GPIO_PIN_3);
		GPIO_WriteLow(GPIOB, GPIO_PIN_7);	//NIXIE
	}	

void wysw_1_off (void) //wy�wietlacz pierwszy od lewej
	{
		GPIO_WriteHigh(GPIOE, GPIO_PIN_0);
		GPIO_WriteHigh(GPIOE, GPIO_PIN_6);	//NIXIE
	}
void wysw_2_off (void) //wy�wietlacz drugi od lewej
	{
		GPIO_WriteHigh(GPIOE, GPIO_PIN_1);
		GPIO_WriteHigh(GPIOE, GPIO_PIN_7);	//NIXIE
	}	
void wysw_3_off (void) //wy�wietlacz trzeci od lewej
	{
		GPIO_WriteHigh(GPIOE, GPIO_PIN_2);
		GPIO_WriteHigh(GPIOB, GPIO_PIN_6);	//NIXIE
	}
void wysw_4_off (void) //wy�wietlacz czwarty od lewej
	{
		GPIO_WriteHigh(GPIOE, GPIO_PIN_3);
		GPIO_WriteHigh(GPIOB, GPIO_PIN_7);	//NIXIE
	}

void all_wysw_off (void)
	{
		GPIO_WriteHigh(GPIOC, GPIO_PIN_5); //wy�. wszystkie wy�wietlacze NIXIE wspolne anody
		GPIO_WriteHigh(GPIOC, GPIO_PIN_6); //wy�. wszystkie wy�wietlacze NIXIE wspolne anody
		GPIO_WriteHigh(GPIOC, GPIO_PIN_7); //wy�. wszystkie wy�wietlacze NIXIE wspolne anody
		GPIO_WriteHigh(GPIOD, GPIO_PIN_0); //wy�. wszystkie wy�wietlacze NIXIE wspolne anody
	}
void all_segmenty_off (void)
	{
		GPIO_WriteHigh(GPIOC, GPIO_PIN_ALL); //wy�. wszystkie segmenty wyswietlaczy
	}