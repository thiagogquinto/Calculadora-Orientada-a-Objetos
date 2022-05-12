#include <iostream>
#include "ThiagoCalculator.h"
#include "ThiagoCPU.h"
#include "ThiagoDisplay.h"
#include "Calculator.h"
#include "ThiagoKeyboard.h"

int main() {
  
  ThiagoKeyboard keyboard;
  ThiagoCPU cpu;
  ThiagoDisplay display;

  ThiagoCalculator calc;
  
  cpu.setDisplay(&display);

  keyboard.setCpu(&cpu);

  calc.setDisplay(&display);
  calc.setCpu(&cpu);
  calc.setKeyboard(&keyboard);

  KeyDigit key0(ZERO), key1(ONE), key2(TWO), key3(THREE), key4(FOUR), key5(FIVE), key6(SIX), key7(SEVEN), key8(EIGHT), key9(NINE);

  KeyOperation keyAddition(ADDITION), keySubtraction(SUBTRACTION), keyDivision(DIVISION), keyMultiplication(MULTIPLICATION), keySquareRoot(SQUARE_ROOT), keyPercentage(PERCENTAGE);

  KeyControl keyDecimalSeparator(DECIMAL_SEPARATOR), keyEqual(EQUAL), keyMRC(MEMORY_READ_CLEAR), keyMemSub(MEMORY_SUBTRACTION), keyMemAdd(MEMORY_ADDITION);

  keyDecimalSeparator.setReceiver(&keyboard);
  keyEqual.setReceiver(&keyboard);
  
  key0.setReceiver(&keyboard);
  key1.setReceiver(&keyboard);
  key2.setReceiver(&keyboard);
  key3.setReceiver(&keyboard);
  key4.setReceiver(&keyboard);
  key5.setReceiver(&keyboard);
  key6.setReceiver(&keyboard);
  key7.setReceiver(&keyboard);
  key8.setReceiver(&keyboard);
  key9.setReceiver(&keyboard);


  keyAddition.setReceiver(&keyboard);
  keySubtraction.setReceiver(&keyboard);
  keyDivision.setReceiver(&keyboard);
  keyMultiplication.setReceiver(&keyboard);
  keySquareRoot.setReceiver(&keyboard);
  keyPercentage.setReceiver(&keyboard);
  
  keyboard.addKey(&key0);
  keyboard.addKey(&key1);
  keyboard.addKey(&key2);
  keyboard.addKey(&key3);
  keyboard.addKey(&key4);
  keyboard.addKey(&key5);
  keyboard.addKey(&key6);
  keyboard.addKey(&key7);
  keyboard.addKey(&key8);
  keyboard.addKey(&key9);

  
  keyboard.addKey(&keyAddition);
  keyboard.addKey(&keySubtraction);
  keyboard.addKey(&keyDivision);
  keyboard.addKey(&keyMultiplication);
  keyboard.addKey(&keySquareRoot);
  keyboard.addKey(&keyPercentage);

  keyboard.addKey(&keyDecimalSeparator);
  keyboard.addKey(&keyEqual);
  

  key1.press();
  key3.press();
  keyDecimalSeparator.press();
  key5.press();
  key2.press();
  key3.press();
  key4.press();
  key7.press();
  key8.press();
  key1.press();
  
  keyAddition.press();

  key2.press();
  keyDecimalSeparator.press();
  key8.press();
  key2.press();
  key2.press();
  key2.press();
  key2.press();
  key2.press();
  key2.press();
  key2.press();
  
  keyEqual.press();
  
  keySubtraction.press();

  keySubtraction.press();
  key3.press();
  keyDecimalSeparator.press();
  key4.press();

  keyEqual.press();

 
}

