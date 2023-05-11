const int sensorPin = 13;
void setup()
{
   Serial.begin(115200);
   pinMode(sensorPin, INPUT);
}
void loop()
{
   int fuego = digitalRead(sensorPin);
   if (fuego == HIGH)
   {
      Serial.println("Fuego detectado");
   }
   delay(1000);
}
