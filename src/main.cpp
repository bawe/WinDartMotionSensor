#include <Arduino.h>



// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int outNextPlayerPin = 12;

const int Remain1DartPin = 8;
const int GameOnPin = 7;
//int val = 0; // variable to store the value read

const int delaymilisec = 10000;
const int switchmilisec = 750;

// Ultraschall
long duration;
int distance;

int ultraschwelle = 60;
unsigned long lastPirTrigger;
unsigned long noTriggerInterval = 2000;

bool bRemain1Dart = false;
bool bGameOn = false;

bool bSendDone = false;
bool bSendToDo = false;


int UltraschallMessen() {
	/* Ultraschall */
	// trigPin frei machen
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);
	// trigPin an für 10 micro secs
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	// Lesen des Echo Pins
	duration = pulseIn(echoPin, HIGH);
	// Berechnung der Entfernung
	distance = duration*0.034/2;
	// Delay
	delay(100);
	// Entfernung zurückgeben
	return distance;
}

/*
void NextPlayer(){
			pinMode(outNextPlayerPin, OUTPUT);
			digitalWrite(outNextPlayerPin, LOW);   // set the LED off
			delay(switchmilisec);               // for switchmilisec ms
			digitalWrite(outNextPlayerPin, HIGH);   // set the LED on
			pinMode(outNextPlayerPin, INPUT);
}
*/

void CheckRemain1Dart(){
	if(bRemain1Dart != !digitalRead(Remain1DartPin)){
		delay(100);
		bRemain1Dart = !bRemain1Dart;
		Serial.print("bRemain1Dart: ");
		Serial.println(bRemain1Dart);

		// neue runde
		if (bRemain1Dart){
			bSendDone = false;
			bSendToDo = false;
		}

		// alle Pfeile geworfen - kurz warten bis diese sich beruhigt haben
		if (!bRemain1Dart){
			delay(1500);
		}
	}
}

void CheckGameOn(){
	if(bGameOn != !digitalRead(GameOnPin)){
		delay(100);
		bGameOn = !bGameOn;
		Serial.print("bGameOn: ");
		Serial.println(bGameOn);
	}
}


void setup() {
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
	//pinMode(outNextPlayerPin, INPUT);  // Set the outNextPlayerPin as an Output
	//digitalWrite(outNextPlayerPin, HIGH);   // set the LED on

	pinMode(Remain1DartPin, INPUT); // Sets the Remain1DartPin as an Input
	digitalWrite(Remain1DartPin, HIGH); 
	pinMode(GameOnPin, INPUT); // Sets the GameOnPin as an Input
	digitalWrite(GameOnPin, HIGH); 

    Serial.begin(9600); // Starts the serial communication
	Serial.println("started");
}


void loop() {
	CheckRemain1Dart();
	CheckGameOn();
	if (!bRemain1Dart && bGameOn) {

		// Schwelle wurde unterschritten und sobald die schwelle nicht mehr unterschritten ist wird gesendet 
		if (UltraschallMessen() < ultraschwelle) {
			lastPirTrigger = millis();
			bSendToDo = true;
			delay(10);
		} 

		// Schwelle wurde noTriggerInterval lang nicht mehr unterschritten und senden bSendToDo ist vorgemerkt
		if(!bSendDone && bSendToDo && millis() - lastPirTrigger > noTriggerInterval){
			Serial.println("NextPlayer");
			bSendDone = true;
			bSendToDo = false;
			//NextPlayer();
		}
	}

}
