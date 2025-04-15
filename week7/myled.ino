#include <LedToggle.h> //Sketch - include library
LedToggle led(LED_BUILTIN);

void setup(){
}
void loop(){
  led.toggle();
}