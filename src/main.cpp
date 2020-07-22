#include<iostream>
#include"BigInt.h"

int main(){
    BigInt a = 64;
    a <<= 26;
    a.print_parts();
    a |= 26;
    a.print_parts();
    a >>= 26;
    a.print_parts();
    (BigInt(5) & 2).print_parts();
    a = 99;
    (a / 3).print_parts();
	return 0;
}
