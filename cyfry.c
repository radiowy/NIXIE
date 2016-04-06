#include "stm8s_gpio.h"
#include "stm8s_it.h"


// cyfty wyswietlacza

int jeden (void)  //jedynka
	{
		GPIO_WriteLow(GPIOC, GPIO_PIN_2); //w³¹czenie segmentu "b" wyœwietlacza
		GPIO_WriteLow(GPIOC, GPIO_PIN_3); //w³¹czenie segmentu "c" wyœwietlacza		
		GPIO_WriteLow(GPIOA, GPIO_PIN_4);
		GPIO_WriteLow(GPIOA, GPIO_PIN_5);
		GPIO_WriteLow(GPIOA, GPIO_PIN_6);
	}

int dwa (void)  //dwójka
	{
		GPIO_WriteLow(GPIOC, GPIO_PIN_1); //w³¹czenie segmentu "b" wyœwietlacza
		GPIO_WriteLow(GPIOC, GPIO_PIN_2); //w³¹czenie segmentu "b" wyœwietlacza		
		GPIO_WriteLow(GPIOC, GPIO_PIN_7); //w³¹czenie segmentu "g" wyœwietlacza
		GPIO_WriteLow(GPIOC, GPIO_PIN_5); //w³¹czenie segmentu "e" wyœwietlacza		
		GPIO_WriteLow(GPIOC, GPIO_PIN_4); //w³¹czenie segmentu "d" wyœwietlacza		
	}

int trzy (void)  //trójka
	{
		GPIO_WriteLow(GPIOC, GPIO_PIN_1); //w³¹czenie segmentu "b" wyœwietlacza
		GPIO_WriteLow(GPIOC, GPIO_PIN_2); //w³¹czenie segmentu "b" wyœwietlacza		
		GPIO_WriteLow(GPIOC, GPIO_PIN_7); //w³¹czenie segmentu "g" wyœwietlacza
		GPIO_WriteLow(GPIOC, GPIO_PIN_3); //w³¹czenie segmentu "c" wyœwietlacza		
		GPIO_WriteLow(GPIOC, GPIO_PIN_4); //w³¹czenie segmentu "d" wyœwietlacza		
	}

int cztery(void) //czwóka
	{
		GPIO_WriteLow(GPIOC, GPIO_PIN_6);
		GPIO_WriteLow(GPIOC, GPIO_PIN_7);
		GPIO_WriteLow(GPIOC, GPIO_PIN_2);
		GPIO_WriteLow(GPIOC, GPIO_PIN_3);
	}

int piec(void) //pi¹tka
	{
		GPIO_WriteLow(GPIOC, GPIO_PIN_1);
		GPIO_WriteLow(GPIOC, GPIO_PIN_6);
		GPIO_WriteLow(GPIOC, GPIO_PIN_7);
		GPIO_WriteLow(GPIOC, GPIO_PIN_3);
		GPIO_WriteLow(GPIOC, GPIO_PIN_4);
	}

int szesc(void) //szóstka
	{
		GPIO_WriteLow(GPIOC, GPIO_PIN_1);
		GPIO_WriteLow(GPIOC, GPIO_PIN_6);
		GPIO_WriteLow(GPIOC, GPIO_PIN_5);
		GPIO_WriteLow(GPIOC, GPIO_PIN_4);
		GPIO_WriteLow(GPIOC, GPIO_PIN_3);
		GPIO_WriteLow(GPIOC, GPIO_PIN_7);
	}

int siedem(void) //siódemka
	{
		GPIO_WriteLow(GPIOC, GPIO_PIN_1);
		GPIO_WriteLow(GPIOC, GPIO_PIN_2);
		GPIO_WriteLow(GPIOC, GPIO_PIN_3);
	}

int osiem(void) //ósemka
	{
		GPIO_WriteLow(GPIOC, GPIO_PIN_1);
		GPIO_WriteLow(GPIOC, GPIO_PIN_2);
		GPIO_WriteLow(GPIOC, GPIO_PIN_3);
		GPIO_WriteLow(GPIOC, GPIO_PIN_4);
		GPIO_WriteLow(GPIOC, GPIO_PIN_5);
		GPIO_WriteLow(GPIOC, GPIO_PIN_6);
		GPIO_WriteLow(GPIOC, GPIO_PIN_7);
	}

int dziewiec(void) //dziewi¹tka
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
	
//za³¹czenie wyœwietlaczy

void wysw_1_on (void) //wyœwietlacz pierwszy od lewej
	{
		GPIO_WriteLow(GPIOE, GPIO_PIN_0);
	}	
void wysw_2_on (void) //wyœwietlacz drugi od lewej
	{
		GPIO_WriteLow(GPIOE, GPIO_PIN_1);
	}
void wysw_3_on (void) //wyœwietlacz trzeci od lewej
	{
		GPIO_WriteLow(GPIOE, GPIO_PIN_2);
	}
void wysw_4_on (void) //wyœwietlacz czwarty od lewej
	{
		GPIO_WriteLow(GPIOE, GPIO_PIN_3);
		GPIO_WriteLow(GPIOB, GPIO_PIN_7);	//NIXIE
	}	

void wysw_1_off (void) //wyœwietlacz pierwszy od lewej
	{
		GPIO_WriteHigh(GPIOE, GPIO_PIN_0);
		GPIO_WriteHigh(GPIOE, GPIO_PIN_6);	//NIXIE
	}
void wysw_2_off (void) //wyœwietlacz drugi od lewej
	{
		GPIO_WriteHigh(GPIOE, GPIO_PIN_1);
		GPIO_WriteHigh(GPIOE, GPIO_PIN_7);	//NIXIE
	}	
void wysw_3_off (void) //wyœwietlacz trzeci od lewej
	{
		GPIO_WriteHigh(GPIOE, GPIO_PIN_2);
		GPIO_WriteHigh(GPIOB, GPIO_PIN_6);	//NIXIE
	}
void wysw_4_off (void) //wyœwietlacz czwarty od lewej
	{
		GPIO_WriteHigh(GPIOE, GPIO_PIN_3);
		GPIO_WriteHigh(GPIOB, GPIO_PIN_7);	//NIXIE
	}

void all_wysw_off (void)
	{
		GPIO_WriteHigh(GPIOC, GPIO_PIN_5); //wy³. wszystkie wyœwietlacze NIXIE wspolne anody
		GPIO_WriteHigh(GPIOC, GPIO_PIN_6); //wy³. wszystkie wyœwietlacze NIXIE wspolne anody
		GPIO_WriteHigh(GPIOC, GPIO_PIN_7); //wy³. wszystkie wyœwietlacze NIXIE wspolne anody
		GPIO_WriteHigh(GPIOD, GPIO_PIN_0); //wy³. wszystkie wyœwietlacze NIXIE wspolne anody
	}
void all_segmenty_off (void)
	{
		GPIO_WriteHigh(GPIOC, GPIO_PIN_ALL); //wy³. wszystkie segmenty wyswietlaczy
	}