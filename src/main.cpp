#include<iostream>
#include"BigInt.h"

int main(){
    BigInt a = 88888888888;
    a.print_parts();
    std::cout << a << std::endl;
    a >>= 1;
    a.print_parts();
    std::cout << a << std::endl;
	return 0;
}
