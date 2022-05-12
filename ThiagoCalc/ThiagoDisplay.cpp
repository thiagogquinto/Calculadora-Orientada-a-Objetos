#include "ThiagoDisplay.h"
#include <iostream>

void ThiagoDisplay::add(Digit dig){
  if(this->CountDigit < 8 ){
    if(dig == ZERO){ std::cout << "0000\n0  0\n0  0\n0  0\n0000\n\n";}
    if(dig == ONE){std::cout<<"0\n0\n0\n0\n0\n\n";}
    if(dig == TWO){std::cout<< "0000\n   0\n0000\n0\n0000\n\n";}
    if(dig == THREE){std::cout<<"0000\n   0\n0000\n   0\n0000\n\n";}
    if(dig == FOUR){std::cout<<"0  0\n0  0\n0000\n   0\n   0\n\n";}
    if(dig == FIVE){std::cout<<"0000\n0\n0000\n   0\n0000\n\n";}
    if(dig == SIX){std::cout<<"0000\n0\n0000\n0  0\n0000\n\n";}
    if(dig == SEVEN){std::cout<<"0000\n0  0\n   0\n   0\n   0\n\n";}
    if(dig == EIGHT){std::cout<<"0000\n0  0\n0000\n0  0\n0000\n\n";}
    if(dig == NINE){std::cout<<"0000\n0  0\n0000\n   0\n0000\n\n";}
  }
    this->CountDigit++;
}


void ThiagoDisplay::setDecimalSeparator(){
    std::cout << "\n00\n00\n\n";

    this->CountDigit++;
    this->DecimalSeparator++;  
}

void ThiagoDisplay::setSignal(Signal sinal){
    if(NEGATIVE) {
      std::cout << "\n----\n"; 
  }
}

void ThiagoDisplay::setError(){
    std::cout << "0000\n0\n0000\n0\n0000";
}
     

void ThiagoDisplay::clear() {
    this->DecimalSeparator = 0;
    this->CountDigit = 0;
}



