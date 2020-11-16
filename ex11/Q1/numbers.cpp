#include <iostream>
#include <fstream>
#include <iterator>

using namespace std;

int main(){
    istream_iterator<int> first(cin);
    istream_iterator<int> last;
    ofstream f("numbers.txt");
    ostream_iterator<int> os(f, " ");

    while(first != last){
        if((*first)%3==0 && (*first)%5!=0) *os = *first++;
        else first++;
    }
}