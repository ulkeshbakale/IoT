int val;
int IR = 10;
int LED;

void setup() {
  // put your setup code here, to run once:
Serial.begin(96000);
pinMode(IR,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
val=digitalRead(IR);
Serial.println(val);
if(val>0)
{
 digitalWrite(LED,HIGH); 
  }
else
{
  digitalWrite(LED,LOW);
  }
}
