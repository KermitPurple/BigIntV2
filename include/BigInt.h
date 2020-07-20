#ifndef BIG_INT_H
#define BIG_INT_H

#include<iostream>
#include<limits.h>
#include<vector>

class BigInt{
private:
    std::vector<unsigned> value;
    bool positive;
    std::vector<unsigned> align(uint64_t zeros);
public:
    // constructors
    BigInt();
    // getters and setters
    std::vector<unsigned> get_value();
    bool get_positive();
    void set_value(int64_t num);
    void set_positive(bool b);
    // other
    uint64_t size();
};

#endif // BIG_INT_H
