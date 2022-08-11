//========Funcion parada===========//
void Stop(uint8_t motor){ 
  usMotor_Status = BRAKE;
  motorGo(motor, usMotor_Status, 0);
  
}
//=========Funcion avance========//
void Forward(uint8_t motor){
  usMotor_Status = CW;
  motorGo(motor, usMotor_Status, usSpeed);
}

//===========Funcion retroceso==========//
void Reverse(uint8_t motor){
  usMotor_Status = CCW;
  motorGo(motor, usMotor_Status, usSpeed);
}

//=================funciones Movimientos del Sumo=======================//

void Avanzar()
{
  Forward(MOTOR_1);
  Forward(MOTOR_2);
}

void Retroceder()
{
   Reverse(MOTOR_2);
   Reverse(MOTOR_1);
}
void GiroPosteriorIzquierdo()
{
  Reverse(MOTOR_1);
  Stop(MOTOR_2);
 //Forward(MOTOR_2);
}
void GiroFrontalDerecho()
{
  Forward(MOTOR_2);
  //Stop(MOTOR_1);
  Reverse(MOTOR_1);
}
void GiroFrontalIzquierdo()
{
 Forward(MOTOR_1);
 //Stop(MOTOR_2);
 Reverse(MOTOR_2);
}
void GiroPosteriorDerecho()
{
  Reverse(MOTOR_2);
  Stop(MOTOR_1);
  //Forward(MOTOR_1);
}
void ParoMotores()
{
 Stop(MOTOR_1);
 Stop(MOTOR_2);
}
