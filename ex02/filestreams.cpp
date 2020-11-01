// filestreams.cpp

#include <iostream>
#include <fstream>
#include <iomanip>

#define MAX 100

using namespace std;

int main(){
    //Open the input file
    ifstream input("data.txt");
    if (!input.is_open()) {
        cerr << "Cannot open file" << endl;
        exit(1);
    }

    //Input and Output
    cout << setfill('-') << setw(21) << '+' << setw(21) << '+' << setw(21) << ' ' << endl;
    int count = 0;
    while( !input.eof() ){
        int field1; 
        double field2;
        input >> field1 >> field2;
        count++;
        cout << setfill(' ') << setw(19) << count << " |" << setw(19) << field1 << " |"
        << setw(20) << field2 << endl;
    }
    input.close();

    return 0;
}
