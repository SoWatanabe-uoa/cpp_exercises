// stringToInt.cpp
#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>

using namespace std;

int stringToInt(const string& input) {
  stringstream instream;
  instream << input;
  int number;
  instream >> number;

  if (instream.fail())
      throw invalid_argument("input can not be converted to an int");

  char left;
  instream >> left;
  if (!instream.fail())
      throw invalid_argument("input can not be converted to an int");

  // everything went fine: returns the int
  return number;
 }

int main(void) {
    try{
        string test1 = "11";
        cout << stringToInt(test1) << endl; 
    }   catch(invalid_argument& e){
        cerr << e.what() << endl;
        cerr << "Please try to use a valid integer instead" << endl;
    }

    try{
        string test2 = "cc11";
        cout << stringToInt(test2) << endl;
    }   catch(invalid_argument& e){
        cerr << e.what() << endl;
        cerr << "Please try to use a valid integer instead" << endl;
    }

    try{
        string test3 = "11cc";
        cout << stringToInt(test3) << endl;
    }   catch(invalid_argument& e){
        cerr << e.what() << endl;
        cerr << "Please try to use a valid integer instead" << endl;
    }
    
  cout << "Tests passed" << endl;

  return 0;
}