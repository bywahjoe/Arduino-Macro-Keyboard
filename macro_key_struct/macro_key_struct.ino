#include <Keyboard.h>

struct macro {
  unsigned int pin;
  String text;
};
const int maxButton = 10;
macro myMacro[maxButton];

void setup() {
  Keyboard.begin();
  
  //Struct Init
  myMacro[0].pin = 2; myMacro[0].text = "Hello World-0";
  myMacro[1].pin = 3; myMacro[1].text = "Hello World-1";
  myMacro[2].pin = 4; myMacro[2].text = "Hello World-2";
  myMacro[3].pin = 5; myMacro[3].text = "Hello World-3";
  myMacro[4].pin = 6; myMacro[4].text = "Hello World-4";
  myMacro[5].pin = 7; myMacro[5].text = "Hello World-5";
  myMacro[6].pin = 8; myMacro[6].text = "Hello World-6";
  myMacro[7].pin = 9; myMacro[7].text = "Hello World-7";
  myMacro[8].pin = 10; myMacro[8].text = "Hello World-8";
  myMacro[9].pin = 11; myMacro[9].text = "Hello World-9";
  myMacro[10].pin = 12; myMacro[10].text = "Hello World-10";
  
  //Button Input Pullup
  for (int i = 0; i <= maxButton; i++) pinMode(myMacro[i].pin, INPUT_PULLUP);
  
}

void loop() {
  //Procces 10 Button
  for (int i = 0; i <= 10; i++) {
    if (!(digitalRead(myMacro[i].pin))) {
      Keyboard.println(myMacro[i].text);//Send Text
      
      while(!(digitalRead(myMacro[i].pin)))delay(200);//Handling Double Click
    }
  }
}
