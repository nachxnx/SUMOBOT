
void MovSumo(int L1,int L2,int L3,int L4,int O1,int O2,int O3)
{       /*L1 es derecho frontal
        L2 es izquierdo frontal
        L3 es derecho posterior
        L4 es izquierdo posterior*/
        /*O1 frontal
          O2 derecho
          O3 izquierdo
          O4 posterior
          */
          /*El sensor de proximidad detecta con 0 y con 1 no detecta */
   int valor = 50;
    /*mayor a 50 = negro
      menor a 50 = blanco*/
      //L1 frontal derecho
      //L2 frontal izquierdo
      //L3 posterior derecho
      //L4 posterior izquierdo


   
   if (L1>valor and L2>valor and L3>valor and L4>valor )     //full negro         
      {//motor avanzando a full                  
        
      if(O1==0 and O2==1 and O3==1)
      {
        Avanzar();
      }
      else if(O1==1 and O2==0 and O3==1)
      {
        GiroFrontalDerecho();
        delay(200);
      }
       else if(O1==1 and O2==1 and O3==0)
      {
        GiroFrontalIzquierdo();
        delay(200);
      }
      else if(O1==0 and O2==0 and O3==0)
      {
        Avanzar();
      }
      else if(O1==0 and O2==0 and O3==1)
      {
       GiroFrontalDerecho();
        delay(200); 
      }
        else if(O1==0 and O2==1 and O3==0)
      {
        GiroFrontalIzquierdo();
        delay(200);
      }
      else
      {
        Avanzar();
      }
  
   }else if ( L4>valor and L3>valor and L2>valor and L1<valor) //L1               
     { //frontal derecho detecta linea blanca
      Retroceder();
      delay(400);
      GiroFrontalIzquierdo();
      delay(200);
     }
   else if ( L4>valor and L3>valor and L2<valor and L1>valor)//L2
      {//frontal izquierdo detecta linea
       //giro a la derecha
      Retroceder();
       delay(400);
       GiroFrontalDerecho();
       delay(200);
      }
   else if ( L4>valor and L3>valor and L2<valor and L1<valor)//L2 & L1
      {//frontales derecho, izquierdo
      //Retroceder     
        Retroceder();
        delay(400);
        GiroFrontalDerecho();
        delay(200);
      }
   else if( L4<valor and L3>valor and L2>valor and L1>valor) //sensor posterior izquierdo L4
      {//posterior derecho (trasero) 
      //giro a la izquierda
        Avanzar();
      }     
   else if( L4>valor and L3<valor and L2>valor and L1>valor)//sensor posterior derecho L3
     {// posterior derecho posterior izquierdo   
      Avanzar();
     }
   else if ( L4<valor and L3<valor and L2>valor and L1>valor)//sensor L3 y L4 
      {//Posteriores derecho , izquierdo
      //Avanzar frontal
        Avanzar();
      }
      
}


//==================== Funcion Seguidor de Linea =====================//

/*void LecturaSeguidores(int L1, int L2, int L3, int L4)
{
 Serial.print("Analog Reading sensor1=");
  Serial.print(L1);
  Serial.print("\n Analog Reading sensor2= ");
  Serial.print(L2);
  Serial.print("Analog Reading sensor3=");
  Serial.print(L3);
  Serial.print("\n Analog Reading sensor4= ");
  Serial.print(L4);
  delay(2000);
}*/


/*void LecturaProximidad(int L1, int L2, int L3, int L4)
{
      if(L1==0 or L2==0 or L3==0 or L4==0)
        {
          Serial.println("Obstaculo detectado ");
          Avanzar();
        }
       else
        {
          Serial.println("Libre");
          GiroFrontalDerecho();
        }
}*/
