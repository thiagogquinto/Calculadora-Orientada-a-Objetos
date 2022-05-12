#pragma once

#include "ThiagoCalculator.h"

class Key; // Preset for early reference

class ThiagoKeyboard:public Keyboard{
   Cpu* cpu; // difere 
   Key* keys[26];
   int KeysCounter = 0;

   public:

       void setCpu(Cpu* ); // difere
       void addKey(Key* );
       void receiveDigit(Digit );
       void receiveOperation(Operation );
       void receiveControl(Control);
  
};
