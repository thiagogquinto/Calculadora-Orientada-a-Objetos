#pragma once

#include "Calculator.h"

class ThiagoCalculator: public Calculator{
  Display* dply;
  Cpu* cpu;
  Keyboard* kbd;
  public:
     void setDisplay(Display* );
     void setCpu(Cpu* );
     void setKeyboard(Keyboard* );
};

