#include <LedToggle.h> //Sketch - include library
LedToggle led(LED_BUILTIN);
// LedToggle 객체를 생성
void setup(){
  // setup()  초기 설정
}
void loop(){
  // Arduino의 메인 루프 계속 밤복 실행됨
  //LED 계속 전환 켜지고 꺼지고
  led.toggle();
}
