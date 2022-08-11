//===============Funcion MotorGo====================//
/*Funcion que controla las variables
motor(0 o 1), direccion (cw o ccw) y pwm (0 a 255)*/
void motorGo(uint8_t motor, uint8_t direccion, uint8_t pwm){
  if(motor == MOTOR_2){
   //Serial.println("Motor 2");
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
   // Serial.println("Motor 1");
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
