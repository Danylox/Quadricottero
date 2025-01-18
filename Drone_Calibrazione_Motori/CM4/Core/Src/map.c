#include "map.h"

float MaxDuty = 6.6;   // Valore massimo del ciclo di lavoro (PWM)
float MinDuty = 4.75;     // Valore minimo del ciclo di lavoro (PWM)

//Funzione che dati i duty cycle per ogni canale del timer associa i 4 rispettivi valori ai registri CCR per creare i segnali PWM
void setPwm(float pwm1, float pwm2, float pwm3, float pwm4)
{
	//pwmX è un duty cycle in percentuale
	pwm1 = pwm1 > MaxDuty ? MaxDuty : pwm1 < MinDuty ? MinDuty : pwm1; //Condizione con operatore ternario
	pwm2 = pwm2 > MaxDuty ? MaxDuty : pwm2 < MinDuty ? MinDuty : pwm2;
	pwm3 = pwm3 > MaxDuty ? MaxDuty : pwm3 < MinDuty ? MinDuty : pwm3;
	pwm4 = pwm4 > MaxDuty ? MaxDuty : pwm4 < MinDuty ? MinDuty : pwm4;

	TIM3->CCR1 = (uint32_t)(TIM3->ARR * pwm1/100); //avgMotor1;
	TIM3->CCR2 = (uint32_t)(TIM3->ARR * pwm2/100); //avgMotor2;
	TIM3->CCR3 = (uint32_t)(TIM3->ARR * pwm3/100); //avgMotor3;
	TIM3->CCR4 = (uint32_t)(TIM3->ARR * pwm4/100); //avgMotor4;
}

void ESC_Calibrate()
{
	TIM3->CCR1 = (uint32_t) (TIM3->ARR * LIMIT_DUTY / 100);
	TIM3->CCR2 = (uint32_t) (TIM3->ARR * LIMIT_DUTY / 100);
	TIM3->CCR3 = (uint32_t) (TIM3->ARR * LIMIT_DUTY / 100);
	TIM3->CCR4 = (uint32_t) (TIM3->ARR * LIMIT_DUTY / 100);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET); //Led verde
	HAL_Delay(3000);
	TIM3->CCR1 = (uint32_t) (TIM3->ARR * OFF_DUTY / 100);
	TIM3->CCR2 = (uint32_t) (TIM3->ARR * OFF_DUTY / 100);
	TIM3->CCR3 = (uint32_t) (TIM3->ARR * OFF_DUTY / 100);
	TIM3->CCR4 = (uint32_t) (TIM3->ARR * OFF_DUTY / 100);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_SET); //Led giallo
}

void stopMotors()
{
    TIM3->CCR1 = 0;
    TIM3->CCR2 = 0;
    TIM3->CCR3 = 0;
    TIM3->CCR4 = 0;
}
