int val;
int tempPin = A0;
int LED=13;
float mv;

void setup() {
  // put your setup code here, to run once:
pinMode(tempPin,INPUT);
pinMode(LED, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
val = analogRead(tempPin);

float mv = (val/1024.0)*5000;
float cel = mv/10;
Serial.print("TEMPRATURE = ");
Serial.print(cel);
Serial.print("*C");
delay(1000);
if(cel>31.5)
{
  digitalWrite(LED,HIGH);
}
else
{
  digitalWrite(LED,LOW);
}
Serial.println();

delay(1000);
}
