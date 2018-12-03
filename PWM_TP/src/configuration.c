#include "configuration.h"

/*--------------------------------------------------------------------------------------------------------------*/
/*											Timer Configuration													*/
/*--------------------------------------------------------------------------------------------------------------*/

void Timer_Config(TIM_HandleTypeDef * Timer, TIM_TypeDef * timer_choice, unsigned int prescaler, unsigned int period){
	//Fonction permettant la configuration du choix du timer ainsi que sa fréqunce
	ENABLE_CLK_TIMER_CHOICE(timer_choice);		//Acivation du timer mis en paramètre
										
	Timer->Instance = timer_choice;				//Sélection du timer pour la configuration
	Timer->Init.CounterMode = TIM_COUNTERMODE_UP;
	Timer->Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	Timer->Init.Prescaler = (prescaler) - 1;
	Timer->Init.Period = (period);
	
	HAL_TIM_Base_Init(Timer);					//Initialisation du Timer configuré
}
									
void Timer_Mode_OCPWM_Config(TIM_HandleTypeDef * Timer, unsigned int mode, unsigned int polarity){
	//Fonction permettant de configurer le mode output compare ou PWM du timer
	HAL_TIM_OC_Init(Timer);				//Signifit que nous allons travailler sur le timer mis en paramètre
	TIM_OC_InitTypeDef TIM_PWM_OC;
	
	TIM_PWM_OC.OCMode = mode;			//Configure le mode du timer
	TIM_PWM_OC.OCPolarity = polarity;	//Configure la polarité
}

void Timer_PWM_OCPWM_Pulse_Channel(TIM_HandleTypeDef * Timer, unsigned int channel, unsigned int pulse){
	//Fonction permettant de gérer le temps soit de l'état haut soit de l'etat bas selon comment est configuré le timer mis en paramètre
	HAL_TIM_OC_Init(Timer);
	TIM_OC_InitTypeDef TIM_PWM_OC;
	
	TIM_PWM_OC.Pulse = pulse;
	HAL_TIM_OC_ConfigChannel(Timer,&TIM_PWM_OC, channel);
}

void Timer_Mode_IC_Config(TIM_HandleTypeDef * Timer, unsigned int polarity, unsigned int filter, unsigned int selection, unsigned int prescaler){
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

void GPIO_Configuration(GPIO_TypeDef * GPIO, unsigned int mode, unsigned int Pin, unsigned int alternate){
	//Fonction permettant la configuration des GPIOs présent sur la carte STM32
	ENABLE_CLK_GPIO(GPIO);										//Activation du port mis en paramètre(GPIO)
	
	GPIO_InitTypeDef GPIO_Config;
	
	GPIO_Config.Mode = mode;									//Configuration du mode de la GPIO avec le mode mis en paramètre
	if(mode == GPIO_MODE_AF_PP || mode == GPIO_MODE_AF_OD)		//Si le mode choisie est alternatif alors nous configurons l'alternatif via la variable mis en paramètre
		GPIO_Config.Alternate = alternate;
	//GPIO_Config.Speed = GPIO_SPEED_
	GPIO_Config.Pin = Pin;										//Activation des pins qui sont mis en paramètre
	
	HAL_GPIO_Init(GPIO,&GPIO_Config);							//Initialisation de la configuration effectué
}	

void ENABLE_CLK_GPIO(GPIO_TypeDef * GPIO){						//Permet d'activer le port voulue
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
