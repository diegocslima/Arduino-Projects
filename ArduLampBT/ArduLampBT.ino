char buf;
 
void setup()
{
  //Define o pino 13 como saida
  pinMode(13, OUTPUT);
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
     digitalWrite(13, HIGH);
     Serial.println("lampada ligada");
   }
    //Caso seja recebido o caracter D, apaga o led
     if (buf == 'D' || buf == 'd' )
    {
      digitalWrite(13, LOW);
      Serial.println("lampada desligada");
    }
  }
}
