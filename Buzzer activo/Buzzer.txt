//Declarando variable del buzzer en el pin 2
int buzzer = 2;

void setup (){
	//Definiendo el pin mode en el pine 2
	pinMode(buzzer,OUTPUT);
}

void loop(){
	tone(buzzer,7000);
	//Duración del tono 2 seg.
	delay(2000);
	//Deetener sonido
	noTone(buzzer);
	//Duración de silencio de 3 seg.
	delay(3000);
}