#include <iostream>
#include "HealthPoints.h"
#include "Queue.h"

//int main() {
//    HealthPoints hp1 = HealthPoints(150);
//    HealthPoints hp2 = 100;
//    HealthPoints hp3 = hp1 - 10;
//    hp1 -= 30;
//    hp1 += 20;
//    hp2 = hp3 + 5;
//    hp1 = 10 + hp3;
//    if (hp1 == hp2) {
//        std::cout << "1" << std::endl;
//    }
//    if (hp1 == 100) {
//        std::cout << "1" << std::endl;
//    }
//    if (hp1 > 100) {
//        std::cout << "1" << std::endl;
//    }
//    if (hp1 >= 100) {
//        std::cout << "1" << std::endl;
//    }
//    if (100 == hp1) {
//        std::cout << "1" << std::endl;
//    }
//    if (100 <= hp1) {
//        std::cout << "1" << std::endl;
//    }
//    if (100 < hp1) {
//        std::cout << "1" << std::endl;
//    }
//    std::cout << hp2 << std::endl;
//    std::cout << hp2 << "asda" << std::endl;
//    std::cout << "asda" << hp2 << std::endl;
//    std::cout << "asda" << hp2 << "asda" << std::endl;
//    std::cout << hp2 << "asda" << hp1 << std::endl;
//    return 0;
//}

class Value{

public:
    int m_innerValue=0;

    Value& operator=(const Value& var) = default;

    bool operator==(const Value& var) const{
        return this->m_innerValue==var.m_innerValue;
    }

    Value& operator=(const int& var) {
        this->m_innerValue=var;
        return *this;
    }


};

int main2(int argc, char *argv[]){

    Queue<Value> q;

    int size=-1;
    size= q.size();
    std::cout << "current Value of queue is"<<size;

    return 0;
}
