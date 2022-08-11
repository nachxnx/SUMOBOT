void MovPOB(int L1,int L2,int L3,int L4,int O1,int O2,int O3)
{
/*L1 es derecho frontal
  L2 es izquierdo frontal
  L3 es derecho posterior
  L4 es izquierdo posterior
  O1 frontal
  O2 derecho
  O3 izquierdo
  O4 posterior
  El sensor de proximidad detecta con 0 y con 1 no detecta 
  Mayor a 50 = negro
  Menor a 50 = blanco*/
int valor = 50;
if (L1>valor and L2>valor and L3>valor and L4>valor)       {   //Pista negra  
    Serial.println("a");       
    if(O1==0 and O2==1 and O3==1)
    {
      Serial.println("a1");
      Avanzar();
    }
    else if(O1==1 and O2==0 and O3==1)
    {
      Serial.println("a2");
      GiroFrontalDerecho();
    }
    else if(O1==1 and O2==1 and O3==0)
    {
      Serial.println("a3");
      GiroFrontalIzquierdo();
    }
    else
    { 
      Serial.println("a4");
      Avanzar();
    }
    //delay(500);
}
else if ( L4>valor and L3>valor and L2>valor and L1<valor) //L1 derecho frontal           
     {//frontal derecho detecta linea blanca
     // if(O1==0 or O2==0 or O3==0){
       // GiroPosteriorIzquierdo();
        //delay(80);}
      //else{
      Serial.println("b");
        Retroceder();
        delay(200);
        GiroFrontalIzquierdo();
        delay(250);//}
     }
else if ( L4>valor and L3>valor and L2<valor and L1>valor)//L2 izquierdo frontal
     {//frontal izquierdo detecta linea
      //giro a la derecha
       //if(O1==0 or O2==0 or O3==0){
        //GiroPosteriorDerecho();
        //delay(80);}
       //else{
       Serial.println("c");
        Retroceder();
        delay(200);
        GiroFrontalDerecho();
        delay(250);//}
      }
else if ( L4>valor and L3>valor and L2<valor and L1<valor)//L2 & L1
      {//frontales derecho, izquierdo
       //Retroceder 
       Serial.println("d");    
        Retroceder();
        delay(200);
        GiroFrontalDerecho();// o izquierdo
        delay(300);
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
else if ( L4>valor and L3<valor and L2>valor and L1<valor)//sensor L1 y L3 toda la derecha 
     {
        GiroFrontalIzquierdo();   
      }
else if ( L4<valor and L3>valor and L2<valor and L1>valor)//sensor L2 y L4 toda la izquierda
     {
        GiroFrontalDerecho();
     }
      
} //end MovPOB
