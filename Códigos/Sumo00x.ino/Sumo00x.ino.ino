//Definición de motores
#define BRAKE 0            //Freno
#define CW    1            //ClockWise (Rotación horaria)
#define CCW   2            //CounterClockWise (Rotación Antihoraria)
#define CS_THRESHOLD 15    //Corriente de Seguridad

//MOTOR (1)
#define MOTOR_A1_PIN 22   //IN A Pin
#define MOTOR_B1_PIN 23   //IN B Pin
#define PWM_MOTOR_1 2     //PWM Pin
#define CURRENT_SEN_1 A1  //CS Pin
#define EN1_PIN A0        //Enable Pin
#define MOTOR_1 0

//MOTOR (2)
#define MOTOR_A2_PIN 24   //IN A Pin
#define MOTOR_B2_PIN 25   //IN B Pin
#define PWM_MOTOR_2 3     //PWM Pin
#define CURRENT_SEN_2 A3  //CS Pin
#define EN2_PIN A2        //Enable Pin
#define MOTOR_2 0


short usSpeed = 150;      //Velocidad por defecto
unsigned short usMotor_Status = BRAKE;  //Estado Motor

void setup() {
  Serial.begin(9600);
  //    MOTOR (1) IZQUIERDO
  pinMode(MOTOR_A1_PIN, OUTPUT);
  pinMode(MOTOR_B1_PIN, OUTPUT);
  pinMode(PWM_MOTOR_1, OUTPUT);
  pinMode(CURRENT_SEN_1, OUTPUT);
  pinMode(EN_PIN_1, OUTPUT);
       
  //    MOTOR (2) DERECHO
  pinMode(MOTOR_A2_PIN, OUTPUT);
  pinMode(MOTOR_B2_PIN, OUTPUT);
  pinMode(PWM_MOTOR_2, OUTPUT);
  pinMode(CURRENT_SEN_2, OUTPUT);
  pinMode(EN_PIN_2, OUTPUT);
        
}

void loop() {
  // put your main code here, to run repeatedly:

}
