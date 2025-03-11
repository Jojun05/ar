#define TRIG 13 //TRIG 핀 설정(초음파 보내는 핀)
#define ECHO 12 //ECHO 핀 설정(초음판 받는 핀)
int led_r = 7; //
int led_g = 9;
void setup()
{
  Serial.begin(9600);
  pinMode(led_g, OUTPUT); //초록색 선
  pinMode(led_r, OUTPUT); //노란색 선
  pinMode (TRIG, OUTPUT);
  pinMode (ECHO, INPUT);
  
}

void loop()
{
  long duration,distance;

  ditalWrite(TRIG,LOW);
  delayMicroseconds(2); //딜레이 2
  ditalWrite(TRIG,HIGH);
  delayMicroseconds(10); 
  ditalWrite(TRIG,LOW);
  
  duration = pulseIn(ECHO,HIGH);
  
  distance = duration / 58.2;
  
  Serial.println(duration );
  Serial.print("\nDIstance : ");
  Serial.print(distance);
  Serial.println(" Cm");
  if(distance >= 100){
    ditalWrite(led_r, HIGH);
    ditalWrite(led_g, LOW);
  }
  else{
  ditalWrite(led_r,LOW);
   ditalWrite(led_g, HIGH);
  }
  delay(1000);
  /*
  digitalWrite(led_R, HIGH); //초록선 -> 저항 -> LED
  delay(1000); //1초 (더빠르게 할수도 있음)
  digitalWrite(led_R, LOW); 
  delay(1000); //1초
  digitalWrite(8, HIGH); //노란선 -> 저항 -> LED
  delay(1000); //1초
  digitalWrite(8, LOW);
  delay(1000); //1초
  */
}
