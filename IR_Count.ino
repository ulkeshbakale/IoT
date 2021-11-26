int val;
int IR = 10;
int LED;
int count=0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(IR,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
val=digitalRead(IR);

if(val==0)
{
 digitalWrite(LED,HIGH); 
 count=count+1;
 Serial.print("OBJECT DETECTED=");
 Serial.println(count);
  }
else
{
  digitalWrite(LED,LOW);
  }delay(500);
}
