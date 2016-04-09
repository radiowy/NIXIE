#include "wyswietlacze.h"

#define LED_SEGMENTY	0x500a		//port do ktorego sa podpiete segmenty wyswietlacza

//wylacza wszystkie anody lamp
void all_wysw_off (void)
	{
		GPIO_WriteHigh(GPIOC, GPIO_PIN_5); //wy-. wszystkie wywietlacze NIXIE wspolne anody
		GPIO_WriteHigh(GPIOC, GPIO_PIN_6); //wy-. wszystkie wywietlacze NIXIE wspolne anody
		GPIO_WriteHigh(GPIOC, GPIO_PIN_7); //wy-. wszystkie wywietlacze NIXIE wspolne anody
		GPIO_WriteHigh(GPIOD, GPIO_PIN_0); //wy-. wszystkie wywietlacze NIXIE wspolne anody
	}


//tablica zawierajaca cyfry dla LED
const u16 cyfry[] = { 
			0x80,		//cyfra 0 
			0xf2,		//cyfra 1
			0x48,		//cyfra 2
			0x60,		//cyfra 3
			0x32,		//cyfra 4
			0x24,		//cyfra 5
			0x04,		//cyfra 6
			0xf0,		//cyfra 7
			0x00,		//cyfra 8
			0x20,		//cyfra 9
			0x01,		//kropka PORTG
			};

//tablica w której sa przechowywane cyfry dla lamp
volatile u16 dane_w [4];

	
//w zaleznosci od zmiennej wpisuje do rejestru segmentow (GPIOC)
void jak_wart_cyfry (u16 z)  
	{
		switch (z)
		{
			case 0:
					//8 NIXIE
					GPIO_WriteLow(GPIOC, GPIO_PIN_1);
					GPIO_WriteLow(GPIOC, GPIO_PIN_2);
					GPIO_WriteLow(GPIOC, GPIO_PIN_3);
					GPIO_WriteLow(GPIOC, GPIO_PIN_4);
			break;
			
			case 1:
					//1 NIXIE
					GPIO_WriteHigh(GPIOC, GPIO_PIN_1);
					GPIO_WriteLow(GPIOC, GPIO_PIN_2);
					GPIO_WriteLow(GPIOC, GPIO_PIN_3);
					GPIO_WriteLow(GPIOC, GPIO_PIN_4);

			break;
			
			case 2:
					//2 NIXIE
					GPIO_WriteLow(GPIOC, GPIO_PIN_1);
					GPIO_WriteHigh(GPIOC, GPIO_PIN_2);
					GPIO_WriteLow(GPIOC, GPIO_PIN_3);
					GPIO_WriteLow(GPIOC, GPIO_PIN_4);
				
			break;
			
			case 3:
					//3 NIXIE
					GPIO_WriteHigh(GPIOC, GPIO_PIN_1);
					GPIO_WriteHigh(GPIOC, GPIO_PIN_2);
					GPIO_WriteLow(GPIOC, GPIO_PIN_3);
					GPIO_WriteLow(GPIOC, GPIO_PIN_4);
			break;
			
			case 4:
					//4 NIXIE
					GPIO_WriteLow(GPIOC, GPIO_PIN_1);
					GPIO_WriteLow(GPIOC, GPIO_PIN_2);
					GPIO_WriteHigh(GPIOC, GPIO_PIN_3);
					GPIO_WriteLow(GPIOC, GPIO_PIN_4);
			break;
			
			case 5:
					//5 NIXIE
					GPIO_WriteHigh(GPIOC, GPIO_PIN_1);
					GPIO_WriteLow(GPIOC, GPIO_PIN_2);
					GPIO_WriteHigh(GPIOC, GPIO_PIN_3);
					GPIO_WriteLow(GPIOC, GPIO_PIN_4);
			break;
			
			case 6:
					//6 NIXIE
					GPIO_WriteLow(GPIOC, GPIO_PIN_1);
					GPIO_WriteHigh(GPIOC, GPIO_PIN_2);
					GPIO_WriteHigh(GPIOC, GPIO_PIN_3);
					GPIO_WriteLow(GPIOC, GPIO_PIN_4);
			break;
			
			case 7:
					//7 NIXIE
					GPIO_WriteHigh(GPIOC, GPIO_PIN_1);
					GPIO_WriteHigh(GPIOC, GPIO_PIN_2);
					GPIO_WriteHigh(GPIOC, GPIO_PIN_3);
					GPIO_WriteLow(GPIOC, GPIO_PIN_4);
			break;
			
			case 8:
					//8 NIXIE
					GPIO_WriteLow(GPIOC, GPIO_PIN_1);
					GPIO_WriteLow(GPIOC, GPIO_PIN_2);
					GPIO_WriteLow(GPIOC, GPIO_PIN_3);
					GPIO_WriteHigh(GPIOC, GPIO_PIN_4);
			break;
			
			case 9:
					//8 NIXIE
					GPIO_WriteHigh(GPIOC, GPIO_PIN_1);
					GPIO_WriteLow(GPIOC, GPIO_PIN_2);
					GPIO_WriteLow(GPIOC, GPIO_PIN_3);
					GPIO_WriteHigh(GPIOC, GPIO_PIN_4);
			break;
			
		}
	}


void kropki (void)
	{
		
			if (dot == 0)
				GPIO_WriteLow(GPIOG, GPIO_PIN_0);		//wlaczone kropki
			if (dot == 1)
				GPIO_WriteHigh(GPIOG, GPIO_PIN_0);  //wy³¹czone kropki
				
	}		
		

void wysw (void)  //wyswietlanie cyfr 1-4 
	{
		//all_wysw_off ();		//wylaczenie wszystkich wyswietaczy
		
		switch (on_disp)	//w zaleznisci od stanu zmiennej zniana sposobu wyswietlania
		{
			case 3:
				dane_w[0]	= minuta/10;	
				dane_w[1]	=	minuta%10;
				dane_w[2] = akt_s/10;
				dane_w[3] = akt_s%10;
			break;
			
			case 5:		//tutaj nic nie powinno byc na LEDach
			break;
			
			default:
				dane_w[0] = godzina/10 ;	//wpisanie tutaj dziesiatek godzin -- max 3
				dane_w[1] = godzina%10;		//wpisanie tutaj jednostek godzin
				dane_w[2] = minuta/10;		//wpisanie tutaj dziesiatek minut  -- max 9
				dane_w[3] = minuta%10;		//wpisanie tutah jednostek minut
			break;
			//case
		}
		
		jak_wart_cyfry (dane_w[cyfra_wysw]); // tutaj do portu segmentow wyswietlacza wpisane zostalo to co czeba
		
		// za³¹czanie wyswietlaczy zalezne od zmiennej cyfra_wysw
		switch (cyfra_wysw)
		{
			case 0:
				if (dane_w[0] > 0 || on_disp != 0) //wy³¹czanie niepotrzebnego zera w trybie wyœwietlania godzin
					{
						if (on_disp == 1 || on_disp == 4)	//tutaj jest realizowanie mruganie wyswietlacza podczas ustawiania godzin
							{
								if (blink_disp <= 100)
									GPIO_WriteLow(GPIOC, GPIO_PIN_5);
								break;
							}
						GPIO_WriteLow(GPIOC, GPIO_PIN_5);	//NIXIE w³¹czona 1 od lewej
					}
			break;
			
			case 1:
				if (on_disp == 1|| on_disp == 4)	//tutaj jest realizowanie mruganie wyswietlacza podczas ustawiania godzin
					{
						if (blink_disp <= 100)
							GPIO_WriteLow(GPIOC, GPIO_PIN_6);
						break;
					}
				else
					GPIO_WriteLow(GPIOC, GPIO_PIN_6);	//NIXIE w³¹czona 2 od lewej
				
				if (on_disp == (0))
					kropki();														//wyswietl kropki
			break;
			
			case 2:			
				if (on_disp == 2 || on_disp == 4 )		//tutaj jest realizowanie mruganie wyswietlacza podczas ustawiania minut
					{
						if (blink_disp <= 100)
							GPIO_WriteLow(GPIOC, GPIO_PIN_7);
							
						break;
					}
				else
					GPIO_WriteLow(GPIOC, GPIO_PIN_7);		//NIXIE w³¹czona 3 od lewej
			break;
			
			case 3:
				if (on_disp == 2 || on_disp == 4)			//tutaj jest realizowanie mruganie wyswietlacza podczas ustawiania minut
					{
						if (blink_disp <= 100)
							GPIO_WriteLow(GPIOD, GPIO_PIN_0);
						break;
					}
				else
					GPIO_WriteLow(GPIOD, GPIO_PIN_0);		//NIXIE w³¹czona 4 od lewej
			break;
		}
		
-		cyfra_wysw++;
		
		if (cyfra_wysw > 3)
			cyfra_wysw = 0;
			
		delay(); 					//opoznienie wylaczenia cyfry
		
		all_wysw_off ();	//wylaczenie wszystkich lamp ANOD
		
		//nic na NIXIE
					GPIO_WriteHigh(GPIOC, GPIO_PIN_1);
					GPIO_WriteHigh(GPIOC, GPIO_PIN_2);
					GPIO_WriteHigh(GPIOC, GPIO_PIN_3);
					GPIO_WriteHigh(GPIOC, GPIO_PIN_4);
	}


	
