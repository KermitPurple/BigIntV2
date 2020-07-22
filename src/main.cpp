#include<iostream>
#include"BigInt.h"

int main(){
    BigInt a = 44444444444444444;
    a.print_parts();
    std::cout << a << std::endl;
    a <<= 999;
    a.print_parts();
    std::cout << a << std::endl;
    return 0;
}
