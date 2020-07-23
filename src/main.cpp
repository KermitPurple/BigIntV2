#include<iostream>
#include"BigInt.h"

int main(){
    BigInt a = 44444444444444444;
    std::cout << a << std::endl;
    a *= 44444444444444444;
    std::cout << a << std::endl;
    a = BigInt(3) & 2;
    std::cout << a << std::endl;
    return 0;
}
