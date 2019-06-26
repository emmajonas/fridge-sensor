
//include adafruit io and wifi document

#include "config.h"

//include the DHT22 sensor for temperature

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

//data pin for temp sensor is pin 2

#define DATA_PIN 2

DHT_Unified dht(DATA_PIN, DHT22);

//connect to adafruit io feed "temperature"

AdafruitIO_Feed *temperature = io.feed("temperature");

const int tempPin = 2;     // temperature sensor pin
const int ledPin =  16;    // led pin


int tempState;         // variable for reading temperature status

void setup() {

  //print to serial monitor
  
  Serial.begin(115200);

  while(! Serial);

  //begin reading temp sensor
  
  dht.begin();

  Serial.print("Connecting to Adafruit IO");
  io.connect();

  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.println(io.statusText());

  //led is output
  pinMode(ledPin, OUTPUT);
  // tempPin is input
  pinMode(tempPin, INPUT);
}

void loop() {

  //connect to adafruit io
 io.run();

  //create temperature as an event
   sensors_event_t event;
  dht.temperature().getEvent(&event);

  float celsius = event.temperature;

  tempState = digitalRead(tempPin);

  //print to serial monitor the temperature in celsius
  
   Serial.print("celsius: ");
  Serial.print(celsius);
  Serial.println("C");

  //save temperature to adafruit io
 temperature->save(celsius);

  delay(1000);

  // check if temperature is above 7 degrees, if yes, led flashes
  if (celsius > 7) {
    
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin,LOW);
    delay(200);
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin,LOW);
    delay(200);
    
  } else if(celsius < -1){  //check if temperature is below -1 degrees, if yes, led turns on
    
    digitalWrite(ledPin, HIGH);
    
  } else {  //else, led is off when temperature is ideal
    
  digitalWrite(ledPin, LOW);
 
  }
}
