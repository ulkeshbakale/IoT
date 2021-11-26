int buzzer =10;
int sensorThres=290;
int smoke =A0;

void setup() {
  // put your setup code here, to run once:
pinMode (buzzer,OUTPUT);
pinMode(smoke,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int analogSensor = analogRead(smoke);
Serial.print("Pin A0:");
Serial.println(analogSensor);
delay(1000);
if (analogSensor > sensorThres)
 {
  digitalWrite(buzzer,HIGH);
  digitalWrite(buzzer,LOW);
  tone(buzzer,1000,200);
  }
 }
