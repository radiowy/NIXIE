#include "sekunda.h"
#include "wyswietlacze.h"
#include "cyfry.h"

void sekunda (void)  //jedna sekunda
	{
		//cyfra_1();
		{
			jak_wart_cyfry(akt_s % 10);
			wysw_4_on ();
			delay ();
			all_wysw_off ();
			all_segmenty_off ();
		}	
	
		{
			jak_wart_cyfry(akt_s/10);
			wysw_3_on ();
			delay ();
			all_wysw_off ();
			all_segmenty_off ();
		}	
		//cyfra_2();
	}

