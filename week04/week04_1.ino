#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 (16 chars and 2-line display)
LiquidCrystal_I2C lcd(0x27, 16, 2);
//LiquidCrystal_I2C lcd(0x3F, 16, 2);

int Vo = A0;
int V_led = 7;

float Vo_value = 0;
float Voltage = 0;
float dustDensity = 0;

void setup() {
  pinMode(V_led, OUTPUT);
  pinMode(Vo, INPUT);
  lcd.init(); // I2C LCD 초기화
  lcd.backlight(); // 백라이트 켜기
  lcd.print("LCD init");
  delay(2000);
  lcd.clear();
}

void loop() {
  digitalWrite(V_led, LOW);
  delayMicroseconds(280);
  Vo_value = analogRead(Vo);
  delayMicroseconds(40);
  digitalWrite(V_led, HIGH);
  delayMicroseconds(968);


  Voltage = Vo_value * 5.0 / 1023.0;


  dustDensity = (Voltage - 0.5) / 0.005;

  lcd.setCursor(0, 0);
  lcd.print("Dust Density: ");
  lcd.setCursor(0, 1);
  lcd.print(dustDensity);
  lcd.print(" um");

  delay(1000);  
}
