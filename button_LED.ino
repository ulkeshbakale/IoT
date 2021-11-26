int led=13;
int button=2;
int ledPin;
int buttonPin;

void setup() {
  // put your setup code here, to run once:
pinMode(ledPin,OUTPUT);
pinMode(buttonPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
button=digitalRead(buttonPin);
if (buttonPin=HIGH)
digitalWrite(led,HIGH);
else (buttonPin=LOW);
digitalWrite(led,LOW);
}
