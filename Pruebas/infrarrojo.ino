#define ACTION 9
#define SENSOR 2


void setup(){
Serial.begin(9600);
pinMode(SENSOR,INPUT_PULLUP);
pinMode(ACTION,OUTPUT);
}
void loop(){
int L = digitalRead(SENSOR);
if(L==0)
{
Serial.println("Obstaculo detectado");
digitalWrite(ACTION,HIGH);
}
else
{
  Serial.println("Libre");
  digitalWrite(ACTION,LOW);
}
delay(500);
}
