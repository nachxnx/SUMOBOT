
#include "Arranque.h"
int count=-1;
void setup() {
Serial.begin(9600) ;
setup_Arranque();
}

void loop() 
{  
  //===================Habilitacion de  Motores==================//
  digitalWrite(EN1_PIN, HIGH);
  digitalWrite(EN2_PIN, HIGH);
  //==============lecturas infrarrojos==================//
  int O1 = digitalRead(S1);//frontal
  int O2 = digitalRead(S2);//derecha
  int O3 = digitalRead(S3);//izquierda
  //==============lecturas seguidor de linea=============//
  int L4 = analogRead(S4);//derecha frontal
  int L5 = analogRead(S5);//izquierda frontal
  int L6 = analogRead(S6);//derecha posterior
  int L7 = analogRead(S7);//izquierda posterior
  //=====LECTURA ESTRATEGIAS====//
  int E1=digitalRead(Et1);
  int E2=digitalRead(Et2);
  int E3=digitalRead(Et3);
  int E4=digitalRead(Et4);
  //=====LECTURA PULSADOR====//
  valor=digitalRead(Pulsador);
  if((valor == HIGH) && (valor_anterior==LOW) ){
    estado=1-estado;
    count=count+1;
    if(count%2 == 0){
     Serial.print("Inicia secuencia 5 seg");
     //=======SECUENCIA DE INICIO 5 S =============//
     digitalWrite(LED,HIGH);
     delay(5000);
     digitalWrite(LED,LOW);
     if(E1==1) //frente-frente
      {     
           Avanzar();
      }
     if(E2==0) //atras-atras
      {
          GiroFrontalDerecho();
          delay(550);
        
      }
     if(E3==0) //derecha-derecha
      {
           
              GiroFrontalDerecho();
              delay(300);
           
      }
     if(E4==0) //izquierda-izquierda
      {
             
             GiroFrontalIzquierdo();
             delay(300);        
      }
      
     
      
  }}
  valor_anterior = valor;
  //Serial.print(estado);
  if( estado == 1 )
  {   Serial.println("Encendido");
      MovPOB(L4,L5,L6,L7,O1,O2,O3);

  }
  else
  {    
      Serial.println("Parado");
      ParoMotores(); //MOTORES APAGADOS estado = 0
      Serial.println("S LINEA");
      Serial.println( L4 );
      Serial.println( L5 );
      Serial.println( L6 );
      Serial.println( L7 );
      Serial.println("ESTRATEGIAS");
      Serial.println( E1 );
      Serial.println( E2 );
      Serial.println( E3 );
      Serial.println( E4 );
      Serial.println("OPONENTES");      
      Serial.println( O1 );
      Serial.println( O2 );
      Serial.println( O3 );      
      //delay(300);  
  }
}
