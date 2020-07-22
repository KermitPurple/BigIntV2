#ifndef BIG_INT_H
#define BIG_INT_H

#include<iostream>
#include<limits.h>
#include<vector>

class BigInt{
private:
    std::vector<unsigned> value;
    bool positive;
    static const uint64_t BASE = 4294967296;
    std::vector<unsigned> align(uint64_t zeros);
    BigInt add(BigInt other);
    BigInt subtract(BigInt other);
    BigInt divide(BigInt other);
    void clean_leading_zeros();
public:
    BigInt multiply(BigInt other);
    // constructors
    BigInt();
    BigInt(int64_t num);
    BigInt(std::vector<unsigned> vec);
    BigInt(std::vector<unsigned> vec, bool pos);
    // getters and setters
    std::vector<unsigned> get_value();
    bool get_positive();
    void set_value(int64_t num);
    void set_positive(bool b);
    // operators
    bool operator==(BigInt other);
    bool operator!=(BigInt other);
    bool operator<(BigInt other);
    bool operator>(BigInt other);
    bool operator<=(BigInt other);
    bool operator>=(BigInt other);
    BigInt operator-();
    BigInt operator+(BigInt other);
    BigInt operator-(BigInt other);
    BigInt operator*(BigInt other);
    BigInt operator/(BigInt other);
    BigInt operator<<(int64_t num);
    BigInt operator>>(int64_t num);
    BigInt* operator+=(BigInt other);
    BigInt* operator-=(BigInt other);
    BigInt* operator*=(BigInt other);
    BigInt* operator/=(BigInt other);
    BigInt* operator<<=(int64_t num);
    BigInt* operator>>=(int64_t num);
    BigInt* operator++(int i);
    BigInt* operator--(int i);
    // other
    uint64_t size();
    BigInt abs();
    void print_parts();
};

#endif // BIG_INT_H
