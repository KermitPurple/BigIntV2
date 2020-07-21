#include"BigInt.h"

// private

std::vector<unsigned> BigInt::align(uint64_t zeros){
    std::vector<unsigned> vec = value;
    for(int i = 0; i < zeros; i++){
        vec.push_back(0);
    }
    return vec;
}

BigInt BigInt::add(BigInt other){
    std::vector<unsigned> aligned = other.align(size() - other.size());
    std::vector<unsigned> result;
    int64_t carry = 0;
    for(int i = 0; i < size(); i++){
        uint64_t a = value[i];
        uint64_t b = aligned[i];
        uint64_t x = a + b + carry;
        carry = x / BASE;
        result.push_back(x % BASE);
    }
    return BigInt(result);
}

BigInt BigInt::subtract(BigInt other){
    std::vector<unsigned> aligned = other.align(size() - other.size());
    std::vector<unsigned> result;
    int64_t carry = 0;
    for(int i = 0; i < size(); i++){
        uint64_t a = value[i];
        uint64_t b = aligned[i];
        uint64_t x = a - b - carry;
        if(x < 0){
            x += BASE;
            carry = 1;
        } else {
            carry = 0;
        }
        result.push_back(x);
    }
    return BigInt(result);
}

// public

BigInt::BigInt(){
    value = {0};
    positive = true;
}

BigInt::BigInt(int64_t num){
    set_value(num);
    positive = true;
}

BigInt::BigInt(std::vector<unsigned> vec){
    value = vec;
    positive = true;
}

BigInt::BigInt(std::vector<unsigned> vec, bool pos){
    value = vec;
    positive = pos;
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
        value.push_back(num % BASE);
        num /= BASE;
    }
}

void BigInt::set_positive(bool b){
    positive = b;
}

bool BigInt::operator<(BigInt other){
    if(positive && !other.get_positive())
        return false;
    else if(!positive && other.get_positive())
        return true;
    uint64_t sz = size();
    uint64_t other_sz = other.size();
    if(sz != other_sz){
        if(positive) return sz < other_sz;
        else return sz > other_sz;
    }
    std::vector<unsigned> other_value = other.get_value();
    for(int i = sz - 1; i >= 0; i--){
        if(value[i] != other_value[i]){
            if(positive)
                return value[i] < other_value[i];
            else
                return value[i] > other_value[i];
        }
    }
    return false;
}

BigInt BigInt::operator-(){
    return BigInt(value, !positive);
}

uint64_t BigInt::size(){
    return value.size();
}
