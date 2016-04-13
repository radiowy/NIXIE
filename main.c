#include "stm8s.h"
#include "cyfry.h"
#include "stm8s_it.h"
#include "stm8s_gpio.h"
#include "klawiatura.h"
#include "keyb.h"
#include "wyswietlacze.h"

// ======================================================= 

#define OPOZNIENIE 2500		//wykozystane w funcji delay() do podtrzymania wyœwietlania cyfr 


//zmienna ktora cyfra wyswietlacza ma byc wyswietlana
u16 cyfra_wysw = 0;

//wykorzystana do przekazania wartoœci cyfry do wyswietlacza
u16 cyfra_we = 0;

//wykorzystana do przerwania TIM4 aby opozniæ o 10 ms 
//obs³ugê klawiatury
u16 c_keyb; 							

//wykozystana w bibliotece obs³ugi klawiatury "keyb.c" aby pobrac adres klawiszy
unsigned int adr_button = 0 ; 		//do klaw


//wykorzystana do mrugania wyswietlaczy zmieniana w przerwaniu TIM4 
//POD WARUNKIEM ze zmienna program = 1
//sprawdzana w funkcji w_blinking_digits()
// 0 - brak mrugania
u16 blink_disp = 0 ; 		

// Odpowiada za mozliwoœæ zmiany czasu 
// 1 - programowanie , 0 - brak programowania
u16 program = 0;				// 0 nie programujemy czasu, 1 programujemy czas					

// ---------------   zmienne zegarka

//zmienna aktualnego wyœwietlania   wyko¿ystana w funkcji wysw() 
//i zmieniana przez case w main
// 	0: wyswietlanie czasu, 
//	1: ustawianie godziny = mrugaja godziny,
//	2: ustawianie minut = mrugaj¹ minuty,
//	3: wyswietlanie sekund,
//	4: mruganie 4 wyswietlaczy
//	5: brak wyswietlania czegokolwiek
u16 volatile on_disp = 0 ;		   


//czas wyœwietlany
int volatile godzina = 0;		//wyswietlana godzina
int volatile minuta	=	0;		//wyswietlana minuta

//czas aktualny
int volatile	akt_g = 0;		//licznik godzin	
int volatile	akt_m = 0;		//licznik minut
int volatile	akt_s = 0;		//licznik sekund



// Petla opozniaj¹ca
void delay(void) 
	{
    u16 d;
    for (d = 0; d < OPOZNIENIE; ++d) 
		{
       nop();
		}
	}

//GIT

// =======================================================


// dodawanie wartoœci minut lub godzin w zaleznoœci 
// od zmiennej on_disp
void dodawanie ( u16 x)	
	{
	if (program == 1)	//zmiana jeœli zmienna program = 1
		{
			switch (x)
			{
				case 1:	  	//ustawienie godzin
					godzina++;
					if (godzina >= 23)
						godzina = 0;
					akt_g = godzina;
				break;
				
				case 2:			//ustawianie minut
					minuta++;
					if (minuta >= 59)
						minuta = 0;
					akt_m = minuta;	
				break;
			}
		}
	}	
	
// odejmowanie wartoœci minut lub godzin w zaleznoœci 
// od zmiennej blinking_digit
void odejmowanie ( u16 x)	//odejmowanie wartoœci minut lub godzin
	{
		if (program == 1)
		{
			switch (x)
			{
				case 1: 	  	//ustawienie godzin
				if (godzina == 0)
					godzina = 24;
				godzina--;
				akt_g = godzina;
				break;
				
				case 2:  			//ustawianie minut
				if (minuta == 0)
					minuta = 60;
				minuta--;
				akt_m = minuta;
				break;
			}
		}
	}		


//===========================================================================================================



int main(void) 	//poczatek main
{
	 	// Konfiguracja pracy zegara mikrokontrolera
		CLK_DeInit();															//Inicjalizacja ustawieñ zegarów
		CLK_HSECmd(ENABLE);												//Konfiguracja zewnêtrznego rezonatora
		CLK_SYSCLKConfig(CLK_PRESCALER_HSIDIV1);  //Konfiguracja FCPU dzielona przez 1
			
		// obs³uga LAMP NIXIE - konfiguracja sprzêtowa
		//katody LAMP NIXIE / kod BCD /	
		GPIO_DeInit(GPIOC);  	
		GPIO_Init(GPIOC, GPIO_PIN_1, GPIO_MODE_OUT_OD_HIZ_SLOW); //NIXIE_BUS_0
		GPIO_Init(GPIOC, GPIO_PIN_2, GPIO_MODE_OUT_OD_HIZ_SLOW); //NIXIE_BUS_1
		GPIO_Init(GPIOC, GPIO_PIN_3, GPIO_MODE_OUT_OD_HIZ_SLOW); //NIXIE_BUS_2
		GPIO_Init(GPIOC, GPIO_PIN_4, GPIO_MODE_OUT_OD_HIZ_SLOW); //NIXIE_BUS_3
		
		//anody LAMP NIXIE 
		GPIO_Init(GPIOC, GPIO_PIN_5,GPIO_MODE_OUT_OD_HIZ_SLOW);//inicjalizacja anody NIXIE 1 z lewej 
		GPIO_Init(GPIOC, GPIO_PIN_6,GPIO_MODE_OUT_OD_HIZ_SLOW);//inicjalizacja anody NIXIE 2 z lewej
		GPIO_Init(GPIOC, GPIO_PIN_7,GPIO_MODE_OUT_OD_HIZ_SLOW);//inicjalizacja anody NIXIE 3 z lewej
		//GPIO_DeInit(GPIOD);
		GPIO_Init(GPIOD, GPIO_PIN_0,GPIO_MODE_OUT_OD_HIZ_SLOW);//inicjalizacja anody NIXIE 4 z lewej
		
		// obs³uga klawiszy - konfiguracja sprzêtowa
		//GPIO_DeInit(GPIOB);		//klawisze
		GPIO_Init(GPIOB, GPIO_PIN_0,GPIO_MODE_IN_PU_NO_IT);	//tryb WE , PULL_UP, bez przerwania, 
		GPIO_Init(GPIOB, GPIO_PIN_1,GPIO_MODE_IN_PU_NO_IT);
		GPIO_Init(GPIOB, GPIO_PIN_2,GPIO_MODE_IN_PU_NO_IT);		
		GPIO_Init(GPIOB, GPIO_PIN_3,GPIO_MODE_IN_PU_NO_IT);
	
		//================================================================================
		// TIM2.  OBS£UGA ZEGARA tykanie 
    TIM2_DeInit();																	// Reset Tim2
    TIM2_TimeBaseInit(TIM2_PRESCALER_16384, 976 );	// Ustawienia dzielnika Tim2 
		TIM2_ITConfig(TIM2_IT_UPDATE, ENABLE);					// W³aczenie przerwania po przepe³nieniu 
    TIM2_Cmd(ENABLE);																// Uruchomienie TIM2.
		
		
		//===============================================================================
		//wyko¿ystany do generowania sygna³u co 1ms 
		//CLK_PeripheralClockConfig (CLK_PERIPHERAL_TIMER4 , ENABLE);
		TIM4_DeInit();															// Reset Tim2
		TIM4_TimeBaseInit(TIM4_PRESCALER_128, 125); // 128 and 125 == przerwanie 1mS
		TIM4_ITConfig(TIM4_IT_UPDATE, ENABLE);			// W³aczenie przerwania po przepe³nieniu 
		TIM4_Cmd(ENABLE);    												// Uruchomienie TIM4 
		
		//================================================================================
		
    enableInterrupts();	// w³¹czenie przerwan (no, really).
		
		all_wysw_off ();  //wy³¹czenie wszystkich wyœwietlaczy
		
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++	
		
		
  for(;;)			//pêtla g³ówna programu
	{
		
		delay(); 	//opoznienie pom. kolejnymi cyframi	
		wysw();		//obsluga wyswietlania cyfr
		
		
		switch( GetKeys() )  		//obsluga klawiatury
    {  
			case KEY_ENTER:
				
				if( KeysTime( ) >= 200 )	//dopiero po trzymaniu 2s klawisza
						{
							if (on_disp == 0)		  //wyswietlanie sekund pod warunkiem ze wyswietlany jest czas
								on_disp = 3;
							break;
						}
						
				if (program == 1 )
				{
					if (on_disp == 4)	//przelacza mruganie na mruganie minut
						{
							on_disp = 1;
							break;
						}
					switch (on_disp) 	//przelaczanie godziny, minuty
					{
						case 1:
							on_disp = 2;	//przelacz na minuty
						break;
						
						case 2:
							on_disp = 1;	//przelacz na godziny
						break;
					}
				}			
				else on_disp = 0;
			break;  
			
			case KEY_ESC:  
				if (program == 1)
					{ 
						on_disp = 0;		//wlaczenie trybu wyswietlania czasu 
						program = 0;		//wylaczenie trybu ustawiania czasu
						break;
					}
				on_disp = 0;
			break;  
			
			case KEY_UP:  	// zmiana wartoœci - dodawanie
				if ((program == 1) && (on_disp == 1 || on_disp == 2))
					dodawanie(on_disp);
			break;  
			
			case KEY_DOWN:  // zmiana wartoœci - odejmowanie
				if ((program == 1) && (on_disp == 1 || on_disp == 2))
					odejmowanie(on_disp);				
			break;  
			
			case KEY_ENTER | KEY_ESC:  	// WEJSCIE DO ZMIANY CZASU
				if( KeysTime( ) >= 300 )  // dalsza czêœæ zostnie wykonana dopiero gdy przyciski bêd¹ trzymane pzez 5 sekund
				{  
					ClrKeyb( KBD_LOCK );
					program = 1;				//ustawienie mo¿liwoœci zmiany czasu
					on_disp = 4;				//tryb wyswietlania mrugania 4 wyswietlaczy
				}
			break;      
		}   //koniec switcha
		
	}			//koniec petli glownej
	
}				//koniec main