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
    while(num > 0){
        value.push_back(num % U_1_MAX);
        num /= U_1_MAX;
    }
}

void BigInt::set_positive(bool b){
    positive = b;
}

uint64_t BigInt::size(){
    return value.size();
}

std::vector<unsigned> BigInt::align(uint64_t zeros){
    std::vector<unsigned> vec = value;
    for(int i = 0; i < zeros; i++){
        vec.push_back(0);
    }
    return vec;
}
