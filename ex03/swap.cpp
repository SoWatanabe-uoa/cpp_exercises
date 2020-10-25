// swap.cpp
void swap(int& i,int& j){
    int tmp = i;
    i = j;
    j = tmp;
}

void swap(int* i,int* j){
    int tmp = *i;
    *i = *j;
    *j = tmp;
}