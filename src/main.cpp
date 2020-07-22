#include<iostream>
#include"BigInt.h"

int main(){
    BigInt a = 44444444444;
    a.print_parts();
    std::cout << a << std::endl;
    a /= 4;
    a.print_parts();
    std::cout << a << std::endl;
    return 0;
}
