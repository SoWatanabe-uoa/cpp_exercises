//int_str.cpp
#include <cstdlib>

char* intToStr(int i){
    char* c = (char*)malloc(10*sizeof(char));
    char c_temp[10];
    int j=0,k=0; //counter
    int negative_flag = 0;

    //Extract each digit one by one
    while( 1 ){
        if(i < 0){
            negative_flag = 1;
            i = (-1)*i;
            continue;
        }
        c_temp[j++] = (char)(i%10 + 48);
        i /= 10;
        if(i == 0) break;
    }

    //Make "c" string corresponding to correct digit place
    if(negative_flag == 1){
        c[k++] = '-';
        c[j+1] = '\0';
        j--;
    }
    else c[j--] = '\0';
    for(; j>-1; k++){
        c[k] = c_temp[j--];
    }

    return c;
}

int strToInt(char* c){
    int i=0;
    int negative_flag = 0;

    for(int j=0; c[j] != '\0'; j++){
        i *= 10;
        if(c[j] == '-'){
            negative_flag = 1;
            continue;
        }
        else{
            i += (int)c[j] - 48;
        }
    }

    if(negative_flag == 1) return i * (-1);
    else return i;
}