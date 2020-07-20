#include<iostream>
#include"BigInt.h"

int main(){
    BigInt a;
    a.set_value(9999999999999);
    for(auto item: a.get_value()){
        std::cout << item << " ";
    }
    std::cout << std::endl;
	return 0;
}
