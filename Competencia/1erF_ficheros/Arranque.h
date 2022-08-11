#include <Arduino.h>
//==========Definición de motores=============//
//============================================//
#define BRAKE 0            //======Freno======//
#define CW    1            //==============ClockWise (Rotación horaria)=========================//
#define CCW   2            //==============CounterClockWise (Rotación Antihoraria)==============//
  //===============Corriente de Seguridad==============================//

//======MOTOR (1) DERECHO=======//
#define MOTOR_A1_PIN 22   //===IN A Pin=====//
#define MOTOR_B1_PIN 23   //===IN B Pin=====//
#define PWM_MOTOR_1 2     //===PWM Pin======//
#define CURRENT_SEN_1 A1  //===CS Pin=======//
#define EN1_PIN A0        //===Enable Pin===//
#define MOTOR_1 0

//======MOTOR (2) IZQUIERDO=======//
#define MOTOR_A2_PIN 24   //====IN A Pin====//
#define MOTOR_B2_PIN 25   //====IN B Pin====//
#define PWM_MOTOR_2 3     //====PWM Pin=====//
#define CURRENT_SEN_2 A3  //====CS Pin======//
#define EN2_PIN A2        //====Enable Pin==//
#define MOTOR_2 1
short usSpeed = 190;    //========= Velocidad por defecto ==============//
short usSpeedMax=190;
unsigned short usMotor_Status = BRAKE;//=========Estado Motor= frenado=======//
//=========Definición de sensores===========//
//===============Infrarrojos================//
#define S1 26      //======Frontal Pin digital====//
#define S2 27      //======Derecha Pin digital
#define S3 28      //======Izquierda Pin digital
#define S8 30       //======Trasero Pin digital
//=============Seguidores de Linea================//
const int S4 = A4; //Frontal Derecho - Pin Analog
const int S5 = A5; //Frontal Izquierdo  - Pin Ananlog
const int S6 = A6; //Posterior Derecho - Pin Analog
const int S7 = A7; //Posterior Izquierdo - Pin Analog
//==========PULSADOR==========//
int const Pulsador = 47; 
//========LED DE ENCENDIDO===========//
int const LED = 46;
//====BOTONES DE ESTRATEGIAS====//
int const Et1 = 51;
int const Et2 = 50;
int const Et3 = 49;
int const Et4 = 48;
//===================================//
int valor,valor_anterior,estado;
#include "MotorGo.h"
#include "MotorControl.h"
#include "MovSUMO_.h"
#include "MovPOB.h"
void setup_Arranque()
{ 
  //========== MOTOR (1) IZQUIERDO==========//
  pinMode(MOTOR_A1_PIN, OUTPUT);
  pinMode(MOTOR_B1_PIN, OUTPUT);
  pinMode(PWM_MOTOR_1, OUTPUT);
  pinMode(CURRENT_SEN_1, OUTPUT);
  pinMode(EN1_PIN, OUTPUT);      
  //===========MOTOR (2) DERECHO============//
  pinMode(MOTOR_A2_PIN, OUTPUT);
  pinMode(MOTOR_B2_PIN, OUTPUT);
  pinMode(PWM_MOTOR_2, OUTPUT);
  pinMode(CURRENT_SEN_2, OUTPUT);
  pinMode(EN2_PIN, OUTPUT);
  //============INFRARROJO E18-D80NK=========//
  pinMode(S1,INPUT);
  pinMode(S2,INPUT);
  pinMode(S3,INPUT);  
  //============SEGUIDOR DE LINEA==========//
  pinMode(S4,INPUT);//frontal derecho
  pinMode(S5,INPUT);//freontal izquierdo
  pinMode(S6,INPUT);//posterior derecho
  pinMode(S7,INPUT);//posterior izquierdo
  //========PULSADOR Y LED DE ENCENDIDO/APAGADO=============//
  pinMode(Pulsador,INPUT);
  pinMode(LED,OUTPUT);
  //======PIN ESTRATEGIA======//
  pinMode(Et1,INPUT);
  pinMode(Et2,INPUT);
  pinMode(Et3,INPUT);
  pinMode(Et4,INPUT);
}
