// ArrayStack.h

#include <string>
#include <iostream>

#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

class ArrayStack {
    private:
    int _num_items; // number of items in the stack
    int* _items; // stack items
    int _allocated_size; // size of memory allocated

    void resize(int max_size) {
        if (max_size==0) max_size++;
        
        // Move stack to a new array of size max
        _allocated_size = max_size;
        int* temp = new int[max_size];
        // Copy 
        for (int i = 0; i < _num_items; ++i) {
            temp[i] = _items[i];
        }
        delete[] _items;
        _items = temp;
    }

    public:
    // Constructors:
    ArrayStack() : _num_items(0),_allocated_size(0),_items(nullptr) {}
    /* COMPLETE ... init _num_items to 0, _allocated_size to 0, and
     * set _items to a null pointer, 
     */

    explicit ArrayStack(int allocated_size) 
    /* COMPLETE ... init _num_items to 0, 
     * pre-allocate memory for an array of size allocated_size
     * and make _items point to it */
    : _num_items(0), _allocated_size(allocated_size), _items(new int[allocated_size]) {}

    // Copy constructor
    ArrayStack(const ArrayStack& another_ArrayStack) :
    _num_items(another_ArrayStack._num_items),
    _items(new int[another_ArrayStack._allocated_size]),
    _allocated_size(another_ArrayStack._allocated_size)
    {
        for(int i=0; i < another_ArrayStack._num_items; i++) _items[i] = another_ArrayStack._items[i];
        std::cout << "Copy Constructor" << std::endl;
    }

    // Assignment operator
   ArrayStack& operator= (const ArrayStack& stack){  
        std::cout << "Assignment Operator" << std::endl;
        if(this == &stack) return *this;  //Self assignment
        delete[] _items;
        _num_items = stack._num_items;
        _items = new int[stack._allocated_size];
        for(int i=0; i < stack._num_items; i++){
               _items[i] = stack._items[i];
        }
        _allocated_size = stack._allocated_size;
        return *this;
}

    // Destructor::
    ~ArrayStack() {
        // COMPLETE
        delete[] _items;
    }

    void push(int item) {
        if (_num_items == _allocated_size) resize(2*_allocated_size);
        _items[_num_items++] = item;
    }

    int pop() {
        int ret = _items[--_num_items];
        if (_num_items > 0 && _num_items == _allocated_size/4) resize(_allocated_size/2);
        return ret;
    }

    bool empty() const { return _num_items == 0; }

    int size() const { return _num_items; }
};

#endif // ARRAY_STACK_H