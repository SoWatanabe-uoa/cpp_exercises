// Hanoi.cpp
#include <iostream>
#include <string>

// COMPLETE:
// Define the function Hanoi. 
// Its argument is the number of disks.
//
// The function should print a series of instructions for 
// how to move the disks in order to solve the problem. 
void Hanoi(int n, char org, char temp, char dest){
    if(n == 1) std::cout << org << " -> " << dest << std::endl;
    else{
        Hanoi(n-1,org,dest,temp);
        Hanoi(1,org,temp,dest);
        Hanoi(n-1,temp,org,dest);
    }
}

int main(int argc, char** argv) {
  if (argc!=2) {
    std::cout << "Usage: " << argv[0] << " n" << std::endl;
    std::cout << "where n is the number of disks." << std::endl;
    return 1;
  }

  int n = std::stoi(argv[1]); // convert the argv[1] to an int

  // COMPLETE:
  // Call Hanoi with n disks
  std::cout << "X -> Y means Move a disk fron X to Y" << std::endl;
  Hanoi(n,'A','B','C');

  return 0;
}