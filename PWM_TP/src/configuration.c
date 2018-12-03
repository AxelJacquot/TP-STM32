#include "configuration.h"

/*--------------------------------------------------------------------------------------------------------------*/
/*											Timer Configuration													*/
/*--------------------------------------------------------------------------------------------------------------*/

void Timer_Config(TIM_HandleTypeDef * Timer, TIM_TypeDef * timer_choice, uint16_t prescaler, uint16_t period){
										
	ENABLE_CLK_TIMER_CHOICE(timer_choice);
										
	Timer->Instance = timer_choice;
	Timer->Init.CounterMode = TIM_COUNTERMODE_UP;
	Timer->Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	Timer->Init.Prescaler = (prescaler) - 1;
	Timer->Init.Period = (period);
	
	HAL_TIM_Base_Init(Timer);
}
									
void Timer_Mode_OCPWM_Config(TIM_HandleTypeDef * Timer, uint16_t mode, uint16_t polarity){
	HAL_TIM_OC_Init(Timer);
	TIM_OC_InitTypeDef TIM_PWM_OC;
	
	TIM_PWM_OC.OCMode = mode;
	TIM_PWM_OC.OCPolarity = polarity;		
	TIM_PWM_OC.OCFastMode = TIM_OCFAST_DISABLE;
}

void Timer_PWM_OCPWM_Pulse_Channel(TIM_HandleTypeDef * Timer, uint16_t channel, uint16_t pulse){
	HAL_TIM_OC_Init(Timer);
	TIM_OC_InitTypeDef TIM_PWM_OC;
	
	TIM_PWM_OC.Pulse = pulse;
	HAL_TIM_OC_ConfigChannel(Timer,&TIM_PWM_OC, channel);
}

void Timer_Mode_IC_Config(TIM_HandleTypeDef * Timer, uint16_t polarity, uint16_t filter, uint16_t selection, uint16_t prescaler){
	HAL_TIM_IC_Init(Timer);
	TIM_IC_InitTypeDef TIM_IC;
	
	TIM_IC.ICPolarity = polarity;
	TIM_IC.ICFilter = filter;
	TIM_IC.ICSelection = selection;
	TIM_IC.ICPrescaler = prescaler;
}

void ENABLE_CLK_TIMER_CHOICE(TIM_TypeDef * timer){
	if(timer == TIM1)
			__HAL_RCC_TIM1_CLK_ENABLE();
	else if(timer == TIM2)
			__HAL_RCC_TIM2_CLK_ENABLE();
	else if(timer == TIM3)
			__HAL_RCC_TIM3_CLK_ENABLE();
	else if(timer == TIM4)
			__HAL_RCC_TIM4_CLK_ENABLE();
	else if(timer == TIM5)
			__HAL_RCC_TIM5_CLK_ENABLE();
	else if(timer == TIM6)
			__HAL_RCC_TIM6_CLK_ENABLE();
	else if(timer == TIM7)
			__HAL_RCC_TIM7_CLK_ENABLE();
	else if(timer == TIM8)
			__HAL_RCC_TIM8_CLK_ENABLE();
	else if(timer == TIM9)
			__HAL_RCC_TIM9_CLK_ENABLE();
	else if(timer == TIM10)
			__HAL_RCC_TIM10_CLK_ENABLE();
	else if(timer == TIM11)
			__HAL_RCC_TIM11_CLK_ENABLE();
	else if(timer == TIM12)
			__HAL_RCC_TIM12_CLK_ENABLE();
	else if(timer == TIM13)
			__HAL_RCC_TIM13_CLK_ENABLE();
	else if(timer == TIM14)
			__HAL_RCC_TIM14_CLK_ENABLE();
}

/*--------------------------------------------------------------------------------------------------------------*/
/*									GPIO Configuration															*/
/*--------------------------------------------------------------------------------------------------------------*/

void GPIO_Configuration(GPIO_TypeDef * GPIO, uint16_t mode, uint16_t Pin, uint16_t alternate){
	
	ENABLE_CLK_GPIO(GPIO);
	
	GPIO_InitTypeDef GPIO_Config;
	
	GPIO_Config.Mode = mode;
	if(mode == GPIO_MODE_AF_PP || mode == GPIO_MODE_AF_OD)
		GPIO_Config.Alternate = alternate;
	GPIO_Config.Pin = Pin;
	
	HAL_GPIO_Init(GPIO,&GPIO_Config);
}	

void ENABLE_CLK_GPIO(GPIO_TypeDef * GPIO){
	if(GPIO == GPIOA)
		__HAL_RCC_GPIOA_CLK_ENABLE();
	else if(GPIO == GPIOB)
		__HAL_RCC_GPIOB_CLK_ENABLE();
	else if(GPIO == GPIOC)
		__HAL_RCC_GPIOC_CLK_ENABLE();
	else if(GPIO == GPIOD)
		__HAL_RCC_GPIOD_CLK_ENABLE();
	else if(GPIO == GPIOE)
		__HAL_RCC_GPIOE_CLK_ENABLE();
	else if(GPIO == GPIOF)
		__HAL_RCC_GPIOF_CLK_ENABLE();
	else if(GPIO == GPIOG)
		__HAL_RCC_GPIOG_CLK_ENABLE();
	else if(GPIO == GPIOH)
		__HAL_RCC_GPIOH_CLK_ENABLE();
}
