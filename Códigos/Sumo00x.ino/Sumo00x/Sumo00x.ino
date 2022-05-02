
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
#define MOTOR_2 1


short usSpeed = 150;      //Velocidad por defecto
unsigned short usMotor_Status = BRAKE;  //Estado Motor

//Definición de sensores
//Infrarrojos
#define S1 26      //Frontal Pin digital
#define S2 27      //Derecha Pin digital
#define S3 28      //Izquierda Pin digital
//Seguidores de Linea
const int S4 = A4; //Frontal Derecho - Pin Digital
const int S5 = 30; //Frontal Izquierdo - Pin Digital
const int S6 = 31; //Posterior Derecho - Pin Digital
const int S7 = 32; //Posterior Izquierdo - Pin Digital

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
  pinMode(S4,INPUT);
}

void loop() {
  //Habilita motores
  digitalWrite(EN1_PIN, HIGH);
  digitalWrite(EN2_PIN, HIGH);
  //Lectura de sensores
  int L1 = digitalRead(S1);
  
  int L4 = analogRead(S4);
  if (L1==0 && (L4>700)){
    Serial.println("En pista");
    Forward(MOTOR_2);
    Reverse(MOTOR_1);
  }else if (L4<700){
    Serial.println("Al borde");
    Stop(MOTOR_1);
    Stop(MOTOR_2);
  }
}

//Funcion parada
void Stop(uint8_t motor){ 
  usMotor_Status = BRAKE;
  motorGo(motor, usMotor_Status, 0);
}

//Funcion avance
void Forward(uint8_t motor){
  usMotor_Status = CW;
  motorGo(motor, usMotor_Status, usSpeed);
}

//Funcion retroceso
void Reverse(uint8_t motor){
  usMotor_Status = CCW;
  motorGo(motor, usMotor_Status, usSpeed);
}
  
//Funcion Motor anda
/*Funcion que controla las variables
motor(0 o 1), direccion (cw o ccw) y pwm (0 a 255)*/
void motorGo(uint8_t motor, uint8_t direccion, uint8_t pwm){
  if(motor == MOTOR_2){
    Serial.println("Motor 2");
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
  }else if(motor == MOTOR_1){
    Serial.println("Motor 1");
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
