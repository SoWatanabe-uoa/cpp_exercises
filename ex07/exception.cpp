// exception.cpp
#include <stdexcept>
#include <cstdio>
#include <iostream>

using namespace std;

void doSomeComputation() {
 throw runtime_error("failure during doing some computation");
}

void example() {
 FILE* logfile = fopen("logfile.txt", "w+");
 try{
    if (!logfile) {
     throw runtime_error("failed to open file");
    }

    fputs("log1", logfile);

    // call a function that performs some computation and may throw 
    // an exception
    doSomeComputation();
 }  catch(runtime_error& e){
     fclose(logfile);
     throw;
 }

 cout << "closing logfile" << endl;
 fclose(logfile);
}

int main(void) {
 cout << "Calling example()" << endl;
 try{
    example();
 }  catch(runtime_error& e){
     cerr << e.what() << endl;
 }
 cout << "After calling example()" << endl;
 return 0;
}