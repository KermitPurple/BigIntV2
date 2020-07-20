#include<iostream>
#include"BigInt.h"

int main(){
    BigInt a(99999999999999999);
    for(auto item: a.get_value()){
        std::cout << item << " ";
    }
    std::cout << std::endl;

    // for(auto item: a.add(BigInt(100)).get_value()){
    //     std::cout << item << " ";
    // }
    // std::cout << std::endl;

	return 0;
}
