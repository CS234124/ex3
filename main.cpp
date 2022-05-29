#include <iostream>
#include <assert.h>
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

class Value {

public:
    int m_innerValue = 0;

    Value &operator=(const Value &var) = default;

    bool operator==(const Value &var) const {
        return this->m_innerValue == var.m_innerValue;
    }

    Value &operator=(const int &var) {
        this->m_innerValue = var;
        return *this;
    }


};

int main2(int argc, char *argv[]) {

    Queue<int> q;

    assert(q.size() == 0);
    try {
        q.front();
    }
    catch (Queue<int>::EmptyQueue e) {
        std::cout << "1";
    }
    try {
        q.popFront();
    }
    catch (Queue<int>::EmptyQueue e) {
        std::cout << "2";
    }

    q.pushBack(0);
    assert(q.size() == 1);
    assert(q.front() == 0);
    q.front() = 1;
    assert(q.front() == 1);

    q.popFront();
    assert(q.size() == 0);
    try {
        q.front();
    }
    catch (Queue<int>::EmptyQueue e) {
        std::cout << "3";
    }
    try {
        q.popFront();
    }
    catch (Queue<int>::EmptyQueue e) {
        std::cout << "4";
    }

    return 0;
}
