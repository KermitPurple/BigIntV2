#include<iostream>
#include"BigInt.h"

int main(){
    BigInt a = 99999999999;
    a.print_parts();
    std::cout << a.to_string() << std::endl;
    a -= 9999999999999999999999;
    a.print_parts();
    std::cout << a.to_string() << std::endl;
	return 0;
}
