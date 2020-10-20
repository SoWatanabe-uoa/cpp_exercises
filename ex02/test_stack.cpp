// test_stack.cpp
#include <cassert>
#include <iostream>
#include "stack.h"

int main(void) {
  Stack stack(100);

  for (int i = 0; i < 40; ++i) {
    stack.push(i);
  }

  assert(stack.full() == false);

  int i = 39;
  while (!stack.empty()) {
    int element = stack.top();
    assert(element == i);
    std::cout << "Topmost element: " << element <<
    ", The number of elements: " << stack.size() << std::endl;
    stack.pop();
    i = i - 1;
  }

  return 0;
}