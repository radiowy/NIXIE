//++++++++++++++++ TIM2 TUTAJ OBS£UGA ZEGARKA ++++++++++++++++++++++++++++
//tutaj zegarek sobie liczy
INTERRUPT_HANDLER(TIM2_UPD_OVF_BRK_IRQHandler, 13)  
{
  if (akt_s < 0) akt_s = 0;									//zabezpieczenia liczb ujemnych 
	if (akt_m < 0 | akt_m == 60) akt_m = 0;	  //podczas regulacji 
	if (akt_g < 0 | akt_g == 60) akt_g = 0;		//w ty³
			
	akt_s++;
	if (akt_s == 60)
		{
			akt_s = 0;
			akt_m++;
			minuta = akt_m;
		}
	if (akt_m == 60)
		{
			akt_m = 0;
			akt_g++;
			minuta = akt_m;
			godzina = akt_g;
		}
	if (akt_g == 24)
		{
			akt_g = 0;
			godzina = akt_g;
		}
	TIM2_ClearITPendingBit(TIM2_IT_UPDATE);		//kasowanie flagi przepe³nienia
}

//++++++++++++++++ TIM4 co 1 ms ++++++++++++++++++++++++++++
// do obs³ugi klawiatury i wyœwietlania
INTERRUPT_HANDLER(TIM4_UPD_OVF_IRQHandler, 23)
{
  c_keyb++;
	c_dot++;
	c_wysw++;
	
  if (c_keyb == 10)	//sprawdzanie czy jest opoznienie = 10ms
    {
			KeybProc();   //wywo³¹nie funkcji obs³ugi klawiatury nie moja biblioteka
			c_keyb=0;			//skasowanie licznika 
    }
	
	//w³¹czanie-wy³¹czanie kropek sekundnika
	if (c_dot <= 500)	
		dot = 1;		//w³¹czenie kropek
	if (c_dot > 500)
		dot = 0;		//wy³¹czenie kropek
	if (c_dot == 1000)
		c_dot = 0;	
	
		
	if ((on_disp == 1)|| (on_disp == 2) || (on_disp == 4)  )  //sprawdzanie czy blinkac cyframi
		blink_disp++;
	
	if (blink_disp == 300)	
    {
			blink_disp = 0;			//nie blinkaæ 
		}
			
	TIM4_ClearITPendingBit(TIM4_IT_UPDATE);  //kasowanie flagi przepe³nienia
}
