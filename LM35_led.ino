int val;
int tempPin = A0;
int led = 12;

void setup() {
  // put your setup code here, to run once:
pinMode(tempPin,INPUT);
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
Serial.println();
if(cel>33){
  digitalWrite(led,HIGH);
}else{
  digitalWrite(led,LOW);
}


delay(1000);
}
