#ifndef MYPAIR_H
#define MYPAIR_H

template<typename T1, typename T2>
class MyPair {
    public:
    T1 first;
    T2 second;

    MyPair(const T1& f,const T2& s){
        first = f;
        second = s;
    }
};

#endif
