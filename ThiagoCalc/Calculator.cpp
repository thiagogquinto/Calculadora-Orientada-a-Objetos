#include "Calculator.h"

void Key::setReceiver(Receiver* receiver){
  this->receiver = receiver;
}


KeyDigit::KeyDigit(Digit d) {
 this->digit = d; 
}

void KeyDigit::press(){
  this->receiver?this->receiver->receiveDigit(this->digit):void();
}

KeyOperation::KeyOperation(Operation operation){
  this->operation = operation;
}

void KeyOperation::press(){
  this->receiver?this->receiver->receiveOperation(this->operation):void();
}


KeyControl::KeyControl(Control control){
  this->control = control;
}

void KeyControl::press(){
  this->receiver?this->receiver->receiveControl(this->control):void();
}