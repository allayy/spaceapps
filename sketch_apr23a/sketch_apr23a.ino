int greenLed =133;
int blueLed1=12;
int blueLed2=13;
int redLed=10;
int ldr=A0;


int E1 = 6; //M1 Speed Control
int E2 = 5; //M2 Speed Control
int M1 = 8; //M1 Direction Control
int M2 = 7; //M2 Direction Control



void setup()
{                                                                                                                                                    
//pinMode (greenLed,OUTPUT);
pinMode (redLed,OUTPUT);

pinMode(blueLed1,OUTPUT);
pinMode(blueLed2,OUTPUT);

pinMode(ldr,INPUT);
Serial.begin(9600);
}

void loop()
{
//Blink(greenLed,redLed);


//int ldrValue  =analogRead(ldr);
//Serial.println(ldrValue*2);
//delay(2000);


//digitalWrite(greenLed,HIGH);
//digitalWrite(redLed,HIGH);
//Blink(blueLed1,blueLed2);

reverse(120,120);



Blink(blueLed1,blueLed2);
delay(10);

//delay(3000);
//backward(200);
//delay(3000);
//delay(3000);
//forward(100,255);
//delay(5000);
}
void Blink(int greenLed,int redLed)
{
  int ambientValue=0;
  for (int count=0;count<5;count++)
{
  ambientValue+=analogRead(ldr);
}
int environmentValue = ambientValue/5;

 
  int baseLine =55;
 
digitalWrite(greenLed,HIGH);
int greenValue1=analogRead(ldr);
Serial.println("Average intensity");
//Serial.println(greenValue1*2);

int intensityValue= 0;

for (int count=0;count<5;count++)
{
  intensityValue+=analogRead(ldr);
}
int averageIntensity = intensityValue/5;

/**int changer=0;
for (int count=0;count<5;count++)
{
  changer+=analogRead(ldr);
}

int checkingValue=changer/5;**/
int sum=environmentValue-averageIntensity;
int diff=averageIntensity-environmentValue;

if (sum>3||diff>3){
  //Serial.println("Current Color intensity");
 // int current = analogRead(ldr);
    left(120,120);
}
  //Serial.println("Average intensity");

 




//Serial.println(averageIntensity);
//if(averageIntensity>baseLine)
//{
//// blue box move left
//left('255','255');
//}
//else
//{
////other colored box move right.
//right('255','255');
//}

delay(50);

digitalWrite(greenLed,LOW);

//digitalWrite(redLed,HIGH);
//int redValue=analogRead(ldr);
//delay(1000);

//if(redvalue<greenValue)
//{
  //send value to server
//}else if(greenValue<redValue)
//{
//send


//digitalWrite(redLed,LOW);

//digitalWrite(greenLed,HIGH);
//delay(2000);
}







//----------------------------------------------------------
void stop(void) //Stop
{
digitalWrite(E1,LOW);
digitalWrite(E2,LOW);
}

void forward(char a,char b)
{
analogWrite (E1,a);
digitalWrite(M1,LOW);
analogWrite (E2,b);
digitalWrite(M2,LOW);
}
void reverse (char a,char b)
{
analogWrite (E1,a);
digitalWrite(M1,HIGH);
analogWrite (E2,b);
digitalWrite(M2,HIGH);
}
void left (char a,char b)
{
analogWrite (E1,a);
digitalWrite(M1,HIGH);
analogWrite (E2,b);
digitalWrite(M2,LOW);
//delay(3000);
}
void right (char a,char b)
{
analogWrite (E1,a);
digitalWrite(M1,LOW);
analogWrite (E2,b);
digitalWrite(M2,HIGH);
//delay(3000);
}
