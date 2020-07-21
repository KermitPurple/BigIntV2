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
    b = a == BigInt(static_cast<uint64_t>(UINT_MAX) + 1);
    std::cout << (b ? "True" : "False") << std::endl;
    b = a != BigInt(static_cast<uint64_t>(UINT_MAX) + 1);
    std::cout << (b ? "True" : "False") << std::endl;

    // for(auto item: a.subtract(BigInt(999)).get_value()){
    //     std::cout << item << " ";
    // }
    // std::cout << std::endl;

	return 0;
}
