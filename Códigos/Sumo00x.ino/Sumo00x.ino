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

//Definición de sensores
#define S2 8
#define S1 7      //Infrarrojo - Pin digital
//const int S2 = 8; //Seguidor de linea - Pin Digital

void setup() {
  Serial.begin(9600);
  //    MOTOR (1) IZQUIERDO
  pinMode(MOTOR_A1_PIN, OUTPUT);
  pinMode(MOTOR_B1_PIN, OUTPUT);
  pinMode(PWM_MOTOR_1, OUTPUT);
  pinMode(CURRENT_SEN_1, OUTPUT);
  pinMode(EN1_PIN, OUTPUT);       
  //    MOTOR (2) DERECHO
  pinMode(MOTOR_A2_PIN, OUTPUT);
  pinMode(MOTOR_B2_PIN, OUTPUT);
  pinMode(PWM_MOTOR_2, OUTPUT);
  pinMode(CURRENT_SEN_2, OUTPUT);
  pinMode(EN2_PIN, OUTPUT);

  //    INFRARROJO E18-D80NK
  pinMode(S1,INPUT_PULLUP);
  //    SEGUIDOR
  pinMode(S2,INPUT);
}

void loop() {
  int L1 = digitalRead(S1);
  int L2 = digitalRead(S2);
  if (L1==0 || L2==0){
    Serial.println("Obstaculo detectado");
    Forward(MOTOR_1);
    Forward(MOTOR_2);
  }else{
    Serial.println("Libre");
    digitalWrite(S2,LOW);
    Stop(MOTOR_1);
    Stop(MOTOR_2);
  }
}

//Funcion de parada
void Stop(uint8_t motor){ 
  usMotor_Status = BRAKE;
  motorGo(motor, usMotor_Status, 0);
}

//Funcion de avance
void Forward(uint8_t motor){
  usMotor_Status = CW;
  motorGo(motor, usMotor_Status, usSpeed);
}

//Funcion Motor anda
/*Funcion que controla las variables
motor(0 o 1), direccion (cw o ccw) y pwm (0 a 255)*/
void motorGo(uint8_t motor, uint8_t direccion, uint8_t pwm){
  if(motor == MOTOR_1){
    Serial.println("entra aca");
    if(direccion == CW){
      digitalWrite(MOTOR_A1_PIN, LOW); 
      digitalWrite(MOTOR_B1_PIN, HIGH);
    }else if(direccion == CCW){
      digitalWrite(MOTOR_A1_PIN, HIGH);
      digitalWrite(MOTOR_B1_PIN, LOW);      
    }else{
      digitalWrite(MOTOR_A1_PIN, LOW);
      digitalWrite(MOTOR_B1_PIN, LOW);            
    }
    analogWrite(PWM_MOTOR_1, pwm); 
  }else{
    if(direccion == CW){
      digitalWrite(MOTOR_A2_PIN, LOW); 
      digitalWrite(MOTOR_B2_PIN, HIGH);
    }else if(direccion == CCW){
      digitalWrite(MOTOR_A2_PIN, HIGH);
      digitalWrite(MOTOR_B2_PIN, LOW);      
    }else{
      digitalWrite(MOTOR_A2_PIN, LOW);
      digitalWrite(MOTOR_B2_PIN, LOW);            
    }
    analogWrite(PWM_MOTOR_2, pwm); 
  }
}
