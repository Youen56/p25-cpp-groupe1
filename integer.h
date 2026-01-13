#include <iostream>
#pragma once

struct Int{
    int value=0;
    void incr();
    void decr(){
        value-=1;
    }
    int get(){return value;}
};

inline void Int::incr(){value++;}