char buf;
 
void setup()
{
  //Define o pino 12 como saida
  pinMode(12, OUTPUT);
  Serial.begin(9600);
}
 
void loop()
{
  if(Serial.available() > 0)
  { 
    buf = Serial.read();
    //Caso seja recebido o caracter L, acende o led
    if (buf == 'L'|| buf == 'l')
   {
     digitalWrite(12, LOW);
     Serial.println("lampada ligada");
   }
    //Caso seja recebido o caracter D, apaga o led
     if (buf == 'D' || buf == 'd' )
    {
      digitalWrite(12, HIGH);
      Serial.println("lampada desligada");
    }
  }
}
