#include "klawiatura.h"

int any_key =  0;

void klaw(void)
	{
	
		if (GPIO_ReadInputData(GPIOB) != 255) //sprawdzenie czy jakikolwiek sklawisz jest wciœniêty
			any_key++;
		if (any_key >= 30)										//zapobieganie odbijaniu styków
			{
				if ((GPIO_ReadInputPin(GPIOB, GPIO_PIN_0)) == RESET )  // sprawdzenie czy wcisniety klawisz na WE6
					{
						godzina++;
					}
				
				any_key = 0;
				
				if ((GPIO_ReadInputPin(GPIOB, GPIO_PIN_1)) == RESET )  // sprawdzenie czy wcisniety klawisz na WE7
					{
						minuta++;
					}
				
				any_key = 0;
			}
	}
