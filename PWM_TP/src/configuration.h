#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_


#include "stm32f4xx_hal.h"

#define LED_Port	GPIOD
#define Green			GPIO_PIN_12
#define Orange		GPIO_PIN_13
#define Red				GPIO_PIN_14
#define Blue 			GPIO_PIN_15
#define Button_Pin	GPIO_PIN_0
#define TIMER4		4
#define Led_all		Green | Orange | Red | Blue


void Timer_Mode_OCPWM_Config(TIM_HandleTypeDef * Timer, uint16_t mode, uint16_t polarity);
void Timer_PWM_OCPWM_Pulse_Channel(TIM_HandleTypeDef * Timer, uint16_t channel, uint16_t pulse);
void ENABLE_CLK_TIMER_CHOICE(TIM_TypeDef * timer);
void Timer_Config(TIM_HandleTypeDef * Timer, TIM_TypeDef * timer_choice, uint16_t prescaler, uint16_t period);
void Timer_Mode_IC_Config(TIM_HandleTypeDef * Timer, uint16_t polarity, uint16_t filter, uint16_t selection, uint16_t prescaler);
void ENABLE_CLK_GPIO(GPIO_TypeDef * GPIO);
void GPIO_Configuration(GPIO_TypeDef * GPIO, uint16_t mode, uint16_t Pin, uint16_t alternate);




#endif
