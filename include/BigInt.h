#ifndef BIG_INT_H
#define BIG_INT_H

#include<iostream>
#include<limits.h>
#include<vector>

class BigInt{
private:
    std::vector<unsigned> value;
    bool positive;
    const uint64_t BASE = 4294967296;
    std::vector<unsigned> align(uint64_t zeros);
    BigInt add(BigInt other);
    BigInt subtract(BigInt other);
public:
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
    BigInt operator-();
    // other
    uint64_t size();
};

#endif // BIG_INT_H
