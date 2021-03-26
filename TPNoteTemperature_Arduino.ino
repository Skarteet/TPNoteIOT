#include "DHT.h"
#define DHT11PIN 4       // define the digital I/O pin
#define DHT11TYPE DHT11     // DHT 11 
DHT dht11(DHT11PIN, DHT11TYPE);

// Temperature sur port 3
int temperatureSensor = 3;

// Led sur port 2
int led = 2;

//Setup du capteur de température et de la led
void setup() {
 Serial.begin(9600);
pinMode(led, OUTPUT);
 dht11.begin();
 pinMode(reversed, INPUT);
}

// Boucle total de 500ms -> récupération des valeurs toutes les ms
void loop() {
  // Récupère les informations d'humidité
  float humidity = dht11.readHumidity();
  
  // Récupère les informations de température
  float temperature = dht11.readTemperature();

// Affiche la température
  Serial.print(temperature);
  Serial.print(",");
// Affiche l'humidité
  Serial.println(humidity);

// Lit l'information d'inversion du clignotement
  String data = Serial.readStringUntil('\n');

  //Si inversé :
  if(data == "1"){
  //Eteint la led pendant 200ms
    digitalWrite(led, LOW);
    delay(200); 
    digitalWrite(led, HIGH);
  }
  //Sinon fonctionnement de base :
  else{
  //Allume la led pendant 200ms
    digitalWrite(led, HIGH);
    delay(200); 
    digitalWrite(led, LOW);
  }

  //Attente de 300ms avant recommencement du cycle
  delay(300);
  
}
