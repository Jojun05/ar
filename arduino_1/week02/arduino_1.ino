#define TRIG 13 //TRIG 핀 설정
#define ECHO 12 //ECHO 핀 설정
int led_r = 7; // RED LED 
int led_g = 9; //GREEN LED
void setup()
{
  Serial.begin(9600);
  pinMode(led_g, OUTPUT); //초록색 모드 설정
  pinMode(led_r, OUTPUT); //노란색 모드 설정
  pinMode (TRIG, OUTPUT);// TRIG 핀 모드 설정
  pinMode (ECHO, INPUT); // ECHO 핀 모드 설정
  
}

void loop()
{
  long duration,distance;

  ditalWrite(TRIG,LOW); //TRIG LOW로 설정
  delayMicroseconds(2); //딜레이 2
  ditalWrite(TRIG,HIGH); //TRIG HIGH 설정
  delayMicroseconds(10); //딜레이 10
  ditalWrite(TRIG,LOW);//TRIG LOW 설정
  
  duration = pulseIn(ECHO,HIGH);
  
  distance = duration / 58.2; //CM단위로 한거
  Serial.println(duration );
  Serial.print("\nDIstance : "); //지속시간
  Serial.print(distance); //거리
  Serial.println(" Cm"); 
  
  if(distance >= 100){ //100cm면 
    ditalWrite(led_r, HIGH); //RED LED 켜기
    ditalWrite(led_g, LOW); //GREEN LED 끄끼
  }
  else{
  ditalWrite(led_r,LOW); //RED LED 끄기
   ditalWrite(led_g, HIGH); //GREEN LED 켜기
  }
  delay(1000); //1초 딜레이
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
