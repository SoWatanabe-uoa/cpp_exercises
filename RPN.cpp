#include <stack>
#include <string>
#include <sstream>
#include <cassert>
#include <iostream>

using namespace std;

int eval(string);

int main(){
    string formula = "1 -2 + 3 -4 - *";
    assert(eval(formula) == (1+(-2))*(3-(-4)));
    cout << "Test passed" << endl;
    return 0;
}

int eval(string formula){
    stack<int> S;
    stringstream ss;
    string token;
    int result;
    
    ss << formula;
    while(ss >> token){
        if(token == "+"){
            int t1 = S.top();
            S.pop();
            int t2 = S.top();
            S.pop();
            S.push(t2+t1);
        }
        else if(token == "-"){
            int t1 = S.top();
            S.pop();
            int t2 = S.top();
            S.pop();
            S.push(t2-t1);
        }
        else if(token == "*"){
            int t1 = S.top();
            S.pop();
            int t2 = S.top();
            S.pop();
            S.push(t2*t1);
        }
        else if(token == "/"){
            int t1 = S.top();
            S.pop();
            int t2 = S.top();
            S.pop();
            S.push(t2/t1);
        }
        else{
            int t = atoi(token.c_str());
            S.push(t);
        }
    }
    result = S.top();

    return result;
}