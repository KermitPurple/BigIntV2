#include<iostream>
#include"BigInt.h"

int main(){
    BigInt a = 1;
    a >>= 32;
    std::cout << a << std::endl;
    return 0;
}
