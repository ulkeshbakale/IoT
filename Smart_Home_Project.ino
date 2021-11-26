#include "LedControlMS.h"

// LIGHT DETECTION

int LDR = A0 ;
int led = 13;

// GAS DETECTION
int sensorThres = 350;
int smoke = A1;
int buzzer = 2;

// ULTRASONIC SENSOR

const int trigPin = 3;
const int echoPin = 4;
int led1 = 5;
long  duration;
int distance;

//IR SENSOR
int IR = 6;
int led2 = 7;
int val;
int count;

//TEMP DETECTION
int value;
int tempPin = A3;
//int led3 = ;
char result[8];
#define NBR_MTX 1 //number of matrices attached is one
LedControl lc = LedControl(12, 11, 10, NBR_MTX); //


void setup() {

  // LIGHT DETECTION
  pinMode (led, OUTPUT);
  pinMode (LDR, INPUT);

  // GAS DETECTION
  pinMode (buzzer, OUTPUT);
  pinMode (smoke, INPUT);

  // ULTRASONIC SENSOR
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
  pinMode (led, OUTPUT);

  //IR SENSOR
  pinMode (IR, INPUT);
  pinMode (led, OUTPUT);

  //TEMP DETECTION

  pinMode(tempPin, INPUT);
  pinMode(led, OUTPUT);

  
    Serial.begin(9600);

  }

  void loop() {
    // LIGHT DETECTION
    LDR = analogRead(A0);

    if (LDR >= 50)
    {
      digitalWrite (led, LOW);
      Serial.println ("Light OFF");
      delay (1000);
    }
    else
    { digitalWrite ( led, HIGH);
      Serial.println ("Light ON");
      delay (1000);
    }

    // GAS DETECTION

    int analogSensor = analogRead(smoke);
    Serial.print("GAS: ");
    Serial.println(analogSensor);
    if (analogSensor > sensorThres)
    {

      tone (buzzer, 5000, 00);
      delay (1000);
    }
    else
    {

      noTone (buzzer);
      delay (1000);
    }

    // ULTRASONIC SENSOR
    digitalWrite (trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite (trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite (trigPin, LOW);

    // Read the echo pin , returns the sound wave travel in micrseconds
    duration = pulseIn(echoPin, HIGH);

    //Calculation the distance
    distance = duration * 0.034 / 2;

    Serial.print ("Distance :  " + String(distance));
    Serial.println (" cm");
    if (distance < 10)
    {
      digitalWrite (led1, HIGH);
      delay (1000);
    }
    else
    {
      digitalWrite (led1, LOW);
      delay (1000);
    }

    //IR SENSOR

    val = digitalRead (IR);
    if (val == 0)
    {
      count = (count + 1) ;
      digitalWrite(led2, HIGH);
      Serial.print ("No. of people in the room=");
      Serial.println (count);
      //delay(500);
    }
    else
    {
      digitalWrite(led2, LOW);
      //delay(500);

    }

    //TEMP DETECTION


    void loop()

    {
      val = analogRead (tempPin);
      float mv = (val / 1024.0) * 5000;
      float cel = mv / 10;
      Serial.print("TEMPRATURE = ");
      Serial.print(cel);
      Serial.print("*c");
      Serial.println();
      delay(1000);


      lc.writeString(0, dtostrf(cel, 2, 2, result)); //sending characters to display
      lc.clearAll();//clearing the display
      delay(1000);
      if (cel > 31.7)
      {
        digitalWrite ( led, HIGH);
        lc.writeString(0, "HIGH"); //sending characters to display
        lc.clearAll();//clearing the display
        //delay(1000);
      }
      else
      {
        digitalWrite ( led, LOW);
        lc.writeString(0, "LOW"); //sending characters to display
        lc.clearAll();//clearing the display
      }



    }
