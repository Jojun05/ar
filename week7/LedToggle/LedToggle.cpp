#include "LedToggle.h"
//초기상태 LOW 설정
LedToggle::LedToggle(int pin){
    _pin = pin;
    _state = false;
    //핀모드 출력설정
    pinMode(_pin,OUTPUT);
    //초기 상태 꺼짐 
    digitalWrite(_pin,LOW);
}
//딜레이 시간,핀을 설정하고 초기상태를 LOW로 설정
LedToggle::LedToggle(int pin,unsigned long delayTime){
    _pin = pin;
    _state = false;
    //출력
    pinMode(_pin,OUTPUT);
    //LOW
    digitalWrite(_pin,LOW);
}
//LED 상태 전환
void LedToggle::toggle(){
    if(_delayTime>0){
        //설정 딜레이 시간만큼 대기
        delay(_delayTime);
    }
    // 현재 상태를 반대로 전환
    _state = !_state;
    // HITH OR LOW 설정
    digitalWrite(_pin,_state ? HIGH : LOW);
}
