#pragma once

#include "Calculator.h"

class ThiagoCPU: public Cpu{

  float op1[9] = {0};
  float op2[9] = {0};

  int Equal = 0;
  int CountDigit1 = 0;
  int CountDigit2 = 0;
  int Operator = 0;
  int posDecSep1 = 0;
  int posDecSep2 = 0;
  int SignalOp1 = 0; 
  int SignalOp2 = 0; 

  float memory = 0;
  Operation receive_operation;

  void convertOp1();
  void convertOp2();
  void convertToDigit();
  void sumAllVector1();   
  void sumAllVector2();   
  int pot(int );

public:
    void setDisplay(Display* );
    void receiveDigit(Digit );
    void receiveOperation(Operation );
    void receiveControl(Control );
};
