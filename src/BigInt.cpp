#include"BigInt.h"

// private


// public

BigInt::BigInt(){
    value = {0};
    positive = true;
}

std::vector<unsigned> BigInt::get_value(){
    return value;
}

bool BigInt::get_positive(){
    return positive;
}

void BigInt::set_value(int64_t num){
    if(num == 0){
        value = {0};
        positive = true;
        return;
    } else if(num < 0){
        positive = false;
        num = -num;
    }
    value = {};
    value.push_back(num % UINT_MAX);
    for(int i = 0; i < num / UINT_MAX; i ++){
        value.push_back(UINT_MAX);
    }
}

void BigInt::set_positive(bool b){
    positive = b;
}
