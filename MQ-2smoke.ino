int val;
int xy=A0;

void setup()
{
pinMode (xy,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here,to run repeatedly:

val= analogRead(xy);
Serial.print("smoke=");
Serial.print(val);
Serial.println();
delay(1000);}
