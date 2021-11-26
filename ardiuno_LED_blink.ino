int led1=13;
int led2=12;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(led1, HIGH);
digitalWrite(led2, LOW);
delay(1000);
digitalWrite(led1,LOW);
digitalWrite(led2,HIGH);
delay(1000);
}
