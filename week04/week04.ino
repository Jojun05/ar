#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // 주소가 0x27로 설정된 LCD

void setup()
{
  lcd.init(); // LCD 초기화
  lcd.backlight(); // 백라이트 켜기
  lcd.print("LCD init");
  delay(2000);
  lcd.clear();
}

void loop()
{
  lcd.setCursor(0, 0); // 커서 위치 설정
  lcd.print("Hello, World");
  
  for(int position = 0; position < 16; position++){
    lcd.scrollDisplayLeft(); // 왼쪽으로 스크롤
    delay(1500); // 스크롤 속도 조정
  }
}
