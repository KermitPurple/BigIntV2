#include<iostream>
#include"BigInt.h"

int main(){
    BigInt a = 44444444444444444;
    std::cout << a << std::endl;
    a *= 44444444444444444;
    std::cout << a << std::endl;
    a = BigInt(0b01) ^ (0b11);
    std::cout << a << std::endl;
    return 0;
}
