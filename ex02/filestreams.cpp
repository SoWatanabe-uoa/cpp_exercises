// filestreams.cpp

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){
    int col1[5];
    double col2[5];

    //Input from the file
    ifstream input("data.txt");
    if (!input.is_open()) {
        cerr << "Cannot open file" << endl;
        exit(1);
    }
    for(int i=0; i < 5; i++){
        input >> col1[i] >> col2[i];
    }
    input.close();

    //std output
    cout << setfill('-') << setw(21) << '+' << setw(21) << '+' << setw(21) << ' ' << endl;
    for(int i=0; i < 5; i++){
        cout << setfill(' ') << setw(19) << i+1 << " |" << setw(19) << col1[i] << " |"
        << setw(20) << col2[i] << endl;
    }

    return 0;
}