// int_str_main.cpp
#include <cstdlib> // for free
#include <iostream>
#include "int_str.h"

int main(void) {
  int i1 = 10;
  char* c1 = intToStr(i1);
  std::cout << "String c1 by intToStr(i1): " << c1 << std::endl;
  free(c1);

  char* c2 = (char*)"10";
  int i2 = strToInt(c2);
  std::cout << "Int-type value i2 by strToInt(c2): " << i2 << std::endl;

  int i3 = -20;
  char* c3 = intToStr(i3);
  std::cout << "String c3 by intToStr(i3): " << c3 << std::endl;
  free(c3);

  char* c4 = (char*)"-20";
  int i4 = strToInt(c4);
  std::cout << "Int-type value i4 by strToInt(c4): " << i4 << std::endl;

  int i5 = 0;
  char* c5 = intToStr(i5);
  std::cout << "String c5 by intToStr(i5): " << c5 << std::endl;
  free(c5);

  char* c6 = (char*)"0";
  int i6 = strToInt(c6);
  std::cout << "Int-type value i6 by strToInt(c6): " << i6 << std::endl;

  return 0;
}