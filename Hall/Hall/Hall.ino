int digitalPin = 25; //pin Digital
int analogPin = 39; //pin Anal�gico
int digitalVal;
int analogVal;

void setup()
{
 	Serial.begin(9600); // Inicia la comunicaci�n serial
 	pinMode(digitalPin, INPUT); //Se defiune el pin digital como uno de entrada
}
void loop()
{
 	digitalVal = digitalRead(digitalPin); //Lectura del pin
 	if (digitalVal == HIGH){
 			Serial.println("Se detecta un campo magnetico");
 	}
 	else{
 			Serial.println("No se esta detectando nada");
 	}
 	analogVal = analogRead(analogPin);
 	Serial.println(analogVal); //Se imprime el valor del pin anal�gico
 	delay(500); //Espera 500 milisegundos
}