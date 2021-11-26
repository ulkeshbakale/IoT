
int LDR;
int LED=13;
void setup() {
  // put your setup code here, to run once:
pinMode(LED,OUTPUT);
pinMode(A0,INPUT);
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
LDR = analogRead(A0);
Serial.println(LDR);
if(LDR>=50)
{
  digitalWrite(LED,LOW);
  Serial.println("light OFF");
}else{
  digitalWrite(LED,HIGH);
  Serial.println("light ON");
}
delay(1000);
}
