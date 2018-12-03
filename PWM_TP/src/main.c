#include "configuration.h"

void wait (uint16_t time);
TIM_HandleTypeDef TIM_Handle;

int main(void){
	GPIO_Configuration(GPIOA, GPIO_MODE_INPUT, Button_Pin,0);
	GPIO_Configuration(GPIOD, GPIO_MODE_AF_PP, Green | Orange | Red | Blue, GPIO_AF2_TIM4);
	Timer_Config(&TIM_Handle,TIM4, 16000, 2000);
	Timer_Mode_OCPWM_Config(&TIM_Handle, TIM_OCMODE_PWM2, TIM_OCPOLARITY_HIGH);
	Timer_PWM_OCPWM_Pulse_Channel(&TIM_Handle, TIM_CHANNEL_1, 500);
	Timer_PWM_OCPWM_Pulse_Channel(&TIM_Handle, TIM_CHANNEL_4, 1500);
	HAL_TIM_OC_Start(&TIM_Handle, TIM_CHANNEL_1);
	HAL_TIM_OC_Start(&TIM_Handle, TIM_CHANNEL_4);
	for(;;){

	}
}


void wait (uint16_t time){
	for(int i = 0; i<time*4000;i++); //16MHz/4ms for 4M loops/sec => 1ms=4k loops
}
