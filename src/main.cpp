#include<iostream>
#include"BigInt.h"

int main(){
    BigInt a(static_cast<uint64_t>(UINT_MAX) + 1);
    for(auto item: a.get_value()){
        std::cout << item << " ";
    }
    std::cout << std::endl;
    bool b = a < BigInt(static_cast<uint64_t>(UINT_MAX) + 1);
    std::cout << (b ? "True" : "False") << std::endl;
    b = a == BigInt(static_cast<uint64_t>(UINT_MAX) + 2);
    std::cout << (b ? "True" : "False") << std::endl;
    b = a != BigInt(static_cast<uint64_t>(UINT_MAX) + 2);
    std::cout << (b ? "True" : "False") << std::endl;
    b = a < BigInt(static_cast<uint64_t>(UINT_MAX) + 2);
    std::cout << (b ? "True" : "False") << std::endl;
    b = a > BigInt(static_cast<uint64_t>(UINT_MAX) + 2);
    std::cout << (b ? "True" : "False") << std::endl;
    b = a <= BigInt(static_cast<uint64_t>(UINT_MAX) + 2);
    std::cout << (b ? "True" : "False") << std::endl;
    b = a >= BigInt(static_cast<uint64_t>(UINT_MAX) + 2);
    std::cout << (b ? "True" : "False") << std::endl;

    a = BigInt(9999999999);
    a.print_parts();
    (a + a).print_parts();
    (a - a).print_parts();
    (a - a - a + BigInt(999999)).print_parts();
    BigInt(-9999999999).print_parts();
	return 0;
}
