#ifndef MAP_H
#define MAP_H

#define OFF_DUTY 5
#define LIMIT_DUTY 10

#include "main.h"

// Dichiarazioni delle variabili globali
extern float MaxDuty, MinDuty;   // Limiti per il ciclo di lavoro PWM

// Funzioni
void setPwm(float pwm1, float pwm2, float pwm3, float pwm4); //Imposta i duty cycle dei motori sui registri CCR del timer
void ESC_Calibrate();
void stopMotors();

#endif // MAP_H
