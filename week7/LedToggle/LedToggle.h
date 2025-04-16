#ifndef LedToggle_h
#define LedToggle_h
#include "Arduino.h"
// LedToggle 클래스 선언
// LED를 제어하고 상태 전환기능
class LedToggle{

    public:
//LED 핀을 설정 초기 상태를 설정
      LedToggle(int pin);
//LED 핀과 상태전환 딜레이 시간을 설정
      LedToggle(int pin,unsigned long delayTime);
//LED 상태 전환메소드
    void toggle();

    private:
//LED핀번호 저장변수
        int _pin;
//LED현재 상태 저장
        bool _state;
//딜레이 시간 저장
        unsigned long _delayTime;
};
#endif
