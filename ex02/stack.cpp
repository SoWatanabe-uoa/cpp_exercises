// stack.cpp
#include <iostream>
#include "stack.h"

// check whether the stack is empty
bool Stack::empty(){
    if( _top == 0 ) return true;
    else return false;
}

// check whether the stack is full
bool Stack::full(){
    if( _top == _max_size ) return true;
    else return false;
}

// return the number of elements
int Stack::size(){ return _top; }

// insert element on top
// print an error message on std::cerr when overflow
void Stack::push(int val){
    if( full() == true ){
        std::cerr << "Stack is full !" << std::endl;
        std::exit(1);
    }
    _data[_top] = val;
    _top++;
}

// remove element on top
// print an error message on std::cerr when underflow
void Stack::pop(){
    if( empty() == true ){
        std::cerr << "Stack is empty !" << std::endl;
        std::exit(2);
    }
    _top--;
}

// acces the topmost element
int Stack::top(){ return _data[_top-1]; }