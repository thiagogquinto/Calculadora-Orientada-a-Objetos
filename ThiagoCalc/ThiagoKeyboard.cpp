#include "ThiagoKeyboard.h"
#include <iostream>

void ThiagoKeyboard::setCpu(Cpu* cpu){
  this->cpu = cpu;
}

void ThiagoKeyboard::addKey(Key* key){
  if(KeysCounter < 26){
    this->keys[KeysCounter] = key;
    this->KeysCounter++;
  };
}

void ThiagoKeyboard::receiveDigit(Digit d){
  this->cpu?this->cpu->receiveDigit(d):void();
}

void ThiagoKeyboard::receiveOperation(Operation o){
  this->cpu?this->cpu->receiveOperation(o):void();
}

void ThiagoKeyboard::receiveControl(Control c){
  this->cpu?this->cpu->receiveControl(c):void();
  
}