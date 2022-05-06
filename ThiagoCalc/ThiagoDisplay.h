#pragma once

#include "ThiagoCalculator.h"

class ThiagoDisplay:public Display{
  int DecimalSeparator = 0;
  int CountDigit = 0;

public:
    
    void addDigit(Digit );
    void setDecimalSeparator();
    void resetDecimalSeparator();
    void resetCountDigit();
    void setSignal(Signal );
    void setError();
    void clear();
};

