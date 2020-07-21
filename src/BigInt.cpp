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

BigInt BigInt::multiply(BigInt other){
    uint64_t sz = size();
    uint64_t other_sz = other.size();
    std::vector<unsigned> other_value = other.get_value();
    std::vector<unsigned> result;
    for(int i = 0; i < sz; i++){
        int64_t carry = 0;
        for(int j = 0; j < other_sz; j++){
            uint64_t a = value[i];
            uint64_t b = other_value[j];
            uint64_t x = a * b + carry;
            carry = x / BASE;
            result.push_back(x % BASE);
        }
        result.push_back(carry);
    }
    return BigInt(result);
}

BigInt BigInt::divide(BigInt other){
    BigInt result = 0;
    BigInt remain = abs();
    while(remain >= other.abs()){
        result += 1;
        remain -= other.abs();
    }
    return result;
}

void BigInt::clean_leading_zeros(){
    for(uint64_t i = size() - 1; i >= 1; i--){
        if(value[i] == 0)
            value.pop_back();
        else
            break;
    }
}

// public

BigInt::BigInt(){
    value = {0};
    positive = true;
}

BigInt::BigInt(int64_t num){
    set_value(num);
}

BigInt::BigInt(std::vector<unsigned> vec):BigInt(vec, true){
}

BigInt::BigInt(std::vector<unsigned> vec, bool pos){
    value = vec;
    positive = pos;
    clean_leading_zeros();
}

std::vector<unsigned> BigInt::get_value(){
    return value;
}

bool BigInt::get_positive(){
    return positive;
}

void BigInt::set_value(int64_t num){
    positive = true;
    if(num == 0){
        value = {0};
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

bool BigInt::operator==(BigInt other){
    return positive == other.get_positive() && value == other.get_value();
}

bool BigInt::operator!=(BigInt other){
    return !(*this == other);
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

bool BigInt::operator>(BigInt other){
    return !(*this <= other);
}

bool BigInt::operator<=(BigInt other){
    return *this == other || *this < other;
}

bool BigInt::operator>=(BigInt other){
    return !(*this < other);
}

BigInt BigInt::operator-(){
    return BigInt(value, !positive);
}

BigInt BigInt::operator+(BigInt other){
    if(positive){
        if(other.get_positive()){ // a + b
            if(abs() > other.abs()) 
                return add(other); // a + b
            else 
                return other.add(*this); // b + a
        } else { // a + ( - b ) == a - b
            if(abs() >= other.abs()) 
                return subtract(other); // a - b
            else 
                return -other.subtract(*this); // a - b == -( b - a )
        }
    } else {
        if(other.get_positive()){ // ( - a ) + b == b - a
            if(abs() > other.abs()) 
                return -subtract(other); // b - a == -( a - b )
            else 
                return other.subtract(*this);// b - a
        } else { // ( - a) + ( - b) == - ( a + b )
            if(abs() > other.abs())
                return -add(other); // - ( a + b )
            else 
                return -other.add(*this); // - ( b + a )
        }
    }
}

BigInt BigInt::operator-(BigInt other){
    return *this + (-other);
}

BigInt BigInt::operator*(BigInt other){
    if(positive){
        if(other.get_positive()) // a * b
            return multiply(other); // a * b
        else // a * -( b )
            return -multiply(other);
    }else{
        if(other.get_positive()) // -( a ) * b
            return -multiply(other);
        else // -( a ) * -( b ) == a * b
            return multiply(other);
    }
}

BigInt BigInt::operator/(BigInt other){
    if(positive){
        if(other.get_positive()) // a * b
            return divide(other); // a * b
        else // a * -( b )
            return -divide(other);
    }else{
        if(other.get_positive()) // -( a ) * b
            return -divide(other);
        else // -( a ) * -( b ) == a * b
            return divide(other);
    }
}

BigInt* BigInt::operator+=(BigInt other){
    *this = *this + other;
    return this;
}

BigInt* BigInt::operator-=(BigInt other){
    *this = *this - other;
    return this;
}

BigInt* BigInt::operator*=(BigInt other){
    *this = *this * other;
    return this;
}

BigInt* BigInt::operator/=(BigInt other){
    *this = *this / other;
    return this;
}

BigInt BigInt::abs(){
    return BigInt(value, true);
}

uint64_t BigInt::size(){
    return value.size();
}

void BigInt::print_parts(){
    std::cout << (positive ? "positive " : "negative ");
    for(auto i: value){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
