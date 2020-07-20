#include<iostream>
#include"BigInt.h"

int main(){
    BigInt a(999000);
    for(auto item: a.get_value()){
        std::cout << item << " ";
    }
    std::cout << std::endl;

    // for(auto item: a.subtract(BigInt(999)).get_value()){
    //     std::cout << item << " ";
    // }
    // std::cout << std::endl;

	return 0;
}
