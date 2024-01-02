
#include "led_module.h"

#include "main.h"
static state_t State;
void init_State()
{
	State = S0;
}
void state_Machine_Update(void)
{
	switch (State)
	{
		case S0:
			//TIM2->CR1 = 0; /* stop counting */
			if (((GPIOB -> IDR) & (0b0000000000000001)) == 0)
			{
			State = S1;
			RCC->APB1ENR |= (1<<0);   /* enable TIM2 clock */
			TIM2->PSC = 7200-1;  /* PSC = 7199 */
			TIM2->ARR = 30000-1;
			TIM2->SR = 0;  /* clear the UIF flag */
			TIM2->CR1 = 1; /* up counting */
			}
//			(GPIOA -> ODR) |= (1 << 10) ;
		//	for (uint32_t i = 0; i < 65000; ++i);
			break;
		case S1:
//			(GPIOA -> ODR) |= (1 << 10) ;
			//(GPIOC -> ODR) &= ~(1 << 13) ;
			if ((TIM2 -> SR & 1) != 0) State = S2;
			if (((GPIOB -> IDR) & 1) == 1)
			{
				State = S0;
			}

//			TIM2->CR1 = 0; /* stop counting */
			break;
		case S2:
			if (((GPIOB -> IDR) & (1 << 0)) != 0) State = S3;
			break;
		case S3:
			if (((GPIOB -> IDR) & (1 << 0)) == 0)
			{
			State = S4;
			RCC->APB1ENR |= (1<<0);   /* enable TIM2 clock */
			TIM2->PSC = 7200-1;  /* PSC = 7199 */
			TIM2->ARR = 60000-1;
			TIM2->SR = 0;  /* clear the UIF flag */
			TIM2->CR1 = 1; /* up counting */
			}
			//State = S4;
			break;
		case S4:
			if ((TIM2->SR & 1) != 0) State = S5;
			if (((GPIOB -> IDR) & (1 << 0)) != 0)
			{
				State = S3;
			}

			break;
		case S5:
			if (((GPIOB -> IDR) & (1 << 0)) != 0) State = S0;
			break;
	}
	switch (State)
		{
			case S0:
				//(GPIOC -> ODR) |= (1 << 13) ;
				(GPIOA -> ODR) &= ~(1 << 10) ;
				//LED_Ctrl(LED_OFF);
				break;
			case S1:
//				(GPIOA -> ODR) |= (1 << 10) ;
				(GPIOA -> ODR) &= ~(1 << 10) ;
				//LED_Ctrl(LED_OFF);
				break;
			case S2:
				//(GPIOC -> ODR) &= ~(1 << 13) ;
				(GPIOA -> ODR) |= (1 << 10) ;
				//LED_Ctrl(LED_ON);
				break;
			case S3:
//				(GPIOC -> ODR) &= ~(1 << 13) ;
				(GPIOA -> ODR) |= (1 << 10) ;
			//	LED_Ctrl(LED_ON);
				break;
			case S4:
//				(GPIOC -> ODR) &= ~(1 << 13) ;
				(GPIOA -> ODR) |= (1 << 10) ;
				//LED_Ctrl(LED_ON);
				break;
			case S5:
				(GPIOA -> ODR) &= ~(1 << 10) ;
				//LED_Ctrl(LED_OFF);
				break;
		}
}

void LED_Ctrl(int state)
{
	if (state == LED_OFF) (GPIOA -> ODR) &= ~(1 << 10) ;
	else (GPIOA -> ODR) |= (1 << 10) ;
}
void LED_Ctrl_Init(void)
{
	LED_Ctrl(LED_OFF);
}
