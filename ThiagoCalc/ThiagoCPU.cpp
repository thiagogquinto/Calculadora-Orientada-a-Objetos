 #include "ThiagoCPU.h"

#include <iostream>
#include <cmath>
#include <string> 
#include <cstdio>


void ThiagoCPU::receiveDigit(Digit d){

  if(this->CountDigit2 == 0){
      this->display?this->display->clear() : void();
  }
    
  if(this->Operator == 0 && this->CountDigit1 < 8) {
    this->op1[CountDigit1] = d;
    CountDigit1++;

  } 
    
  if(this->Operator != 0 && this->CountDigit2 < 8)    {
    this->op2[CountDigit2] = d;
    CountDigit2++;

  }
    
  this->display?this->display->add(d):void();

}

void ThiagoCPU::receiveOperation(Operation operation){

     if(operation == SUBTRACTION && this->CountDigit1 == 0 && this->SignalOp1 == 0) {
      this->display?this->display->setSignal(NEGATIVE) : void();
      this->SignalOp1++;
   
    } else if(operation == SUBTRACTION && this->Operator > 0 && this->SignalOp2 == 0) {
        this->display?this->display->setSignal(NEGATIVE) : void();
        this->SignalOp2++;
   
    } else {

        std::cout << "\n\n\n";
        this->receive_operation = operation; 
      if(this->Equal == 0){
        this->convertOp1();
        }
        this->sumAllVector1();
        this->Operator++;
        this->CountDigit2 = 0;
    }
}

void ThiagoCPU::receiveControl(Control c){

  if(c == CLEAR){
    this->Operator = 0;
    this->CountDigit1 = 0;
    this->CountDigit2 = 0;
    this->display?this->display->clear():void();
    
  }

  
  if(c == DECIMAL_SEPARATOR){
     
  
    if(this->posDecSep1 == 0 && this->CountDigit1 < 8){
      this->posDecSep1 = this->CountDigit1;
      this->CountDigit1++;

    } 
    
    if(this->posDecSep2 == 0 && this->CountDigit2 < 8) {
      this->posDecSep2 = this->CountDigit2;
      this->CountDigit2++;
      this->display?this->display->setDecimalSeparator():void();
    }

  }

  
  if(c == RESET){
     std::cout << "0000\n0  0\n0  0\n0  0\n0000\n";
    this->op1[0] = 0;
    this->op2[0] = 0;
    this->CountDigit1 = 0;
    this->CountDigit2 = 0;
    this->Equal = 0;
    this->memory = 0;
   }

  
  if(c == MEMORY_READ_CLEAR){
    this->display?this->display->clear() : void();
    this->convertToDigit();
    this->memory = 0;
  }

  
  if(c == MEMORY_ADDITION){
    this->memory += this->op1[0];
    // this->op1[0] = 0;
    // this->op2[0] = 0;
  }

  if(c == MEMORY_SUBTRACTION) {
    this->memory -= this->op1[0];
    // this->op1[0] = 0;
    // this->op2[0] = 0;
  }

  if(c == EQUAL){
    this->display?this->display->clear():void();
    this->convertOp2();
    this->sumAllVector2();
    this->CountDigit2 = 0;
    this->posDecSep2 = 0;
    this->Equal++;

     if(this->SignalOp1 == 1){
         this->op1[0]  *= -1;
       }

       if(this->SignalOp2 == 1){
         this->op2[0] *= -1;
       }

    
    switch (this->receive_operation) {
  
      
    case ADDITION:
      
      this->op1[0] = this->op1[0] + this->op2[0];
      break;
  
    case SUBTRACTION:
      this->op1[0] = this->op1[0] - this->op2[0];
      break;
  
    case DIVISION:
      this->op1[0] = this->op1[0] / this->op2[0];
      break;
      
    case MULTIPLICATION:
      this->op1[0] = this->op1[0] * this->op2[0];
      break;
      
    case SQUARE_ROOT:
      if(this->op1[0] < 0){
        this->display?this->display->setError() : void();
        this->op1[0] = 0;
      } else{
      this->op1[0] = sqrtf(this->op1[0]); 
        }
      break;
  
    case PERCENTAGE:
      this->op1[0] = this->op1[0] * (this->op2[0] / 100) ;
      break;
  
    default:
      this->convertOp1();
      this->sumAllVector1();
      break;

    }

    std::cout << "\n\n\n";
    this->convertToDigit();

  }
  
 }

int ThiagoCPU::pot(int n){
  if(n == 0){ return 1; }
      int p = 10;
      int b = n-1;
      while(b > 0){
           p = p*10;
            b--; 
  }
  return p;
}

void ThiagoCPU::convertOp1(){
  
  
  int pos1, pos2, pos3;
  
  if(this->posDecSep1 == 0){

    int exp = this->CountDigit1 - 1;
      for(int i = 0; i < this->CountDigit1; i++){
        this->op1[i] = (float) this->op1[i] * pot(exp);
        exp--;
      }
  }
  
  if(this->posDecSep1 != 0) {
    
    pos1 = this->posDecSep1 - 1; 
      for(int a = 0; a < this->posDecSep1; a++){
        float Dig = (float) (this->op1[a] * pot(pos1));
        this->op1[a] = Dig;
        pos1--;                             
  }
            
    pos2 = this->posDecSep1 + 1;
    pos3 = this->posDecSep1;
      for(int i = 1; i < CountDigit1+1; i++){
        float c = (float) (this->op1[pos2] / pot(i));  
        this->op1[pos3] = c;
        pos2++;        
        pos3++;
    }
  }
  
    
}

void ThiagoCPU::convertOp2(){

  int pos1, pos2, pos3;
  
  if(this->posDecSep2 == 0){

    int exp = this->CountDigit2 - 1;
    for(int i = 0; i < this->CountDigit2; i++){
      this->op2[i] = (float) this->op2[i] * pot(exp);
      exp--;
    }
  }
  
  if(this->posDecSep2 != 0) {
    
    pos1 = this->posDecSep2 - 1; 
    for(int i = 0; i < this->posDecSep2; i++){
      this->op2[i] = (float) (this->op2[i] * pot(pos1));
      pos1--;                             
    }
  
    pos2 = this->posDecSep2 + 1;
    pos3 = this->posDecSep2;
    for(int i = 1; i < CountDigit2+1; i++){
      this->op2[pos3] = (float) (this->op2[pos2] / pot(i));  
      pos2++;        
      pos3++;
    }
  }
      
}

void ThiagoCPU::sumAllVector1(){
  
  for (int i = this->CountDigit1 - 1; i > 0; i--) {
    this->op1[i-1] += this->op1[i];
    this->op1[i] = 0;
  }
 
}

void ThiagoCPU::sumAllVector2(){
    for (int i = this->CountDigit2 - 1; i > 0; i--) {
    this->op2[i-1] += this->op2[i];
    this->op2[i] = 0;
     
    }  
 
}

void ThiagoCPU::convertToDigit() {
    char result[9];

  std::sprintf(result, "%g", this->op1[0]);

  for(int i = 0; i < 9; i++) {
    
   switch (result[i]) {
     
    case '0':
      this->display?this->display->add(ZERO):void();
      break;
  
    case '1':
      this->display?this->display->add(ONE):void();
      break;
  
    case '2':
      this->display?this->display->add(TWO):void();
      break;
      
    case '3':
      this->display?this->display->add(THREE):void();
      break;
      
     case  '4':
       this->display?this->display->add(FOUR):void();
       break;
  
    case '5':
      this->display?this->display->add(FIVE):void();
      break;

     case '6':
      this->display?this->display->add(SIX):void();
      break;

     case '7':
      this->display?this->display->add(SEVEN):void();
      break;
    
     case '8':
       this->display?this->display->add(EIGHT):void();
       break;

     case '9':
      this->display?this->display->add(NINE):void();
      break;

     case '.':
      this->display?this->display->setDecimalSeparator():void();
      break;

    case '-':
      this->display?this->display->setSignal(NEGATIVE):void();
      break;
    default:
      break;
  
    }
  
  }
  
}

