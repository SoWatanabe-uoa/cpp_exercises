// filestreams.cpp

#include <iostream>
#include <fstream>
#include <iomanip>

#define MAX 100

using namespace std;

int main(){
    int col1[MAX];
    double col2[MAX];
    int num_lines=0;

    //Input from the file
    ifstream input("data.txt");
    if (!input.is_open()) {
        cerr << "Cannot open file" << endl;
        exit(1);
    }
    while( !input.eof() ){
        input >> col1[num_lines] >> col2[num_lines];
        num_lines++;
    }
    input.close();

    //std output
    cout << setfill('-') << setw(21) << '+' << setw(21) << '+' << setw(21) << ' ' << endl;
    for(int i=0; i < num_lines; i++){
        cout << setfill(' ') << setw(19) << i+1 << " |" << setw(19) << col1[i] << " |"
        << setw(20) << col2[i] << endl;
    }

    return 0;
}
