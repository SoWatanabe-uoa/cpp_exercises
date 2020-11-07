// exception.cpp
#include <stdexcept>
#include <cstdio>
#include <iostream>

using namespace std;

class LogFile{
    private:
    FILE* _logfile;

    public:
    LogFile(const char* n, const char* a){ _logfile = fopen(n, a); }
    ~LogFile(){ fclose(_logfile); }
    FILE* get_filePtr(){ return _logfile; }
    void write(const char* input){ fputs(input,_logfile); }
};

void doSomeComputation() {
 throw runtime_error("failure during doing some computation");
}

void example() {
 LogFile logfile("logfile.txt", "w+");
 
 if ( !(logfile.get_filePtr()) ) 
   throw runtime_error("failed to open file");

 logfile.write("log2");

// call a function that performs some computation and may throw 
// an exception
 doSomeComputation();

 cout << "closing logfile" << endl;
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