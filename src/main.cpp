#include<iostream>
#include"BigInt.h"

int main(){
    BigInt a;
    a.set_value(5000000000);
    for(auto item: a.get_value()){
        std::cout << item << std::endl;
    }
	return 0;
}
