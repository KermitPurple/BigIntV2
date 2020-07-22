#include<iostream>
#include"BigInt.h"

int main(){
    BigInt a = 44444444444444444;
    a.print_parts();
    std::cout << a << std::endl;
    a *= a;
    a.print_parts();
    std::cout << a << std::endl;
    return 0;
}
