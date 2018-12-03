#include "configuration.h"

void wait (uint16_t time);
TIM_HandleTypeDef TIM_Handle; //Variable contenant la configuration du timer 4(mis dans chaque fonction à cause de cela)

int main(void){
	GPIO_Configuration(GPIOD, GPIO_MODE_AF_PP, Green | Blue, GPIO_AF2_TIM4);	//Configuration des pins des Leds verte et bleu se trouvant sur le port D en mode alternatif PP, les pins prendront leurs états des sorties du timer 4
	Timer_Config(&TIM_Handle,TIM4, 16000, 2000);												//Activation et Configuration du timer 4 à la fréquence souhaitée
	Timer_Mode_OCPWM_Config(&TIM_Handle, TIM_OCMODE_PWM1, TIM_OCPOLARITY_HIGH);	//Configuration du mode du Timer 4
	Timer_PWM_OCPWM_Pulse_Channel(&TIM_Handle, TIM_CHANNEL_1, 500);			//Réglage du temps d'état bas sur le channel 1 du timer 4
	Timer_PWM_OCPWM_Pulse_Channel(&TIM_Handle, TIM_CHANNEL_4, 1500);
	HAL_TIM_OC_Start(&TIM_Handle, TIM_CHANNEL_1);					//Activation du channel 1 du timer 4
	HAL_TIM_OC_Start(&TIM_Handle, TIM_CHANNEL_4);
	for(;;){

	}
}


void wait (uint16_t time){
	for(int i = 0; i<time*4000;i++); //16MHz/4ms for 4M loops/sec => 1ms=4k loops
}
