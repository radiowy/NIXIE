// TUTAZ ZBIERAM TO CO WCESNIEJ DZIALALO ALE PO POPRAWKACH 
// JUZ NIE POTREBUJÊ MOZE KIEDYŒ INDZIEJ
/*
int cyfra_1 (void)	//wyswietlanie cyfry 1 od lewej (dziesiatka godzin)
	{
		int temp;
		if (godzina <= 9)  //wy³aczanie wysw. nieaktywnego zera godziny
		 {
				delay ();
				wysw_1_off ();
				all_segmenty_off ();
				return;
		 }
			 
		if (godzina >= 24)
			godzina = 0;
		
		temp = godzina/10;	//dekoder dziesiatek
		jak_wart_cyfry(temp);
		wysw_1_on ();
		delay ();
		wysw_1_off ();
		all_segmenty_off ();
		
	}	
	
int cyfra_2 (void)	//wyswietlanie cyfry 2 od lewej (jednostka godzin)
	{
		int temp;
		if (godzina < 0)
			godzina = 0;
		if (godzina <= 10)
			temp = godzina;
		if (godzina  == 10)
			temp == 0;
			
			temp = godzina%10  ;  //dekoder jednostek
		jak_wart_cyfry(temp);
		wysw_2_on ();
		delay ();
		wysw_2_off ();
		all_segmenty_off ();
	}	

int cyfra_3 (void)	//wyswietlanie cyfry 3 od lewej (dziesiatka minut)
	{
		int temp;
		if (minuta >= 60)
			minuta = 0;
			
		temp = minuta/10;	
		
		jak_wart_cyfry(temp);
		wysw_3_on ();
		delay ();
		wysw_3_off ();
		all_segmenty_off ();	
	}	
	
int cyfra_4 (void)	//wyswietlanie cyfry 4 od lewej (jednostka minut)
	{
		int temp;
		if (minuta < 0)
			minuta = 0;
		if (minuta <= 10)
			temp = minuta;
		if (minuta == 10)
			temp = 0;
		else 
			temp = minuta%10;
		
		//jaka_wart_cyfry(temp);
		jak_wart_cyfry(temp);
		wysw_4_on ();
		delay ();
		wysw_4_off ();
		all_segmenty_off ();
	}	

//dekoder na kod BCD
u16 dek_BCD (u16 x)		
	{
		x = (x / 10 | x % 10)	;
	}
	
	//miganie wyœwietlacza w zaleznoœci od zmiennej on_digit
void w_blinking_digits (u16 temp )	
	{
		if (temp == 1) //GODZINY
			{
				cyfra_4();
				cyfra_3();
				//kropki();
				if (blink_disp <= 100) 
				{
					cyfra_2 ();
					cyfra_1 (); 
					//all_digits();
				}
			}
		
		if (temp == 2) //MINUTY
			{
				if (blink_disp <= 100) 
				{
					cyfra_4 ();
					cyfra_3 (); 
				}
				//kropki();
				cyfra_2 ();
				cyfra_1 ();
			}	
			
			if (temp == 4) //MINUTY i godziny
			{
				if (blink_disp <= 100) 
				{
					all_digits();
				}
				else
				{
					all_wysw_off ();
				}		
			}	
	}
	
	
	*/