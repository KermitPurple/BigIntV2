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

    a = 9999999999;
    a.print_parts();
    (a + a).print_parts();
    (a - a).print_parts();
    (a - a - a + BigInt(999999)).print_parts();
    BigInt(-9999999999).print_parts();
    BigInt(BigInt(999999999999).get_value()).print_parts();
    (BigInt(-99) * 999).print_parts();
    a.print_parts();
    a += 10000;
    a.print_parts();
    a -= 9999999999;
    a.print_parts();
    a *= 12345;
    a.print_parts();
    a *= 999999999999;
    a *= 999999999999;
    a *= 999999999999;
    a.print_parts();
    (BigInt(99999)/-9).print_parts();
    a = 99;
    a.print_parts();
    a /= -3;
    a.print_parts();
    a /= -3;
    a.print_parts();
    a++;
    a.print_parts();
    a--;
    a.print_parts();
    a = static_cast<uint64_t>(UINT_MAX) * 2;
    a.print_parts();
    a += 2;
    a -= 2;
    a.print_parts();
    a -= static_cast<uint64_t>(UINT_MAX);
    a.print_parts();
    a += 1;
    a.print_parts();
    a = static_cast<uint64_t>(UINT_MAX);
    a += 1;
    a.print_parts();
    a *= 2;
    a.print_parts();
    (a << -5).print_parts();
    (a >> 5).print_parts();
    (a << 5).print_parts();
    (a >> -5).print_parts();
    a.print_parts();
    (a << 0).print_parts();
    (a >> 0).print_parts();
    a >>= 16;
    a.print_parts();
    a <<= 16;
    a.print_parts();
    a <<= 31;
    a.print_parts();
    a <<= 31;
    a.print_parts();
    a <<= 31;
    a.print_parts();
	return 0;
}
