#include <iostream>
#include "Text.h"

class A {
    int a;
public:

    A() = default;
    A(int a): a(a) {}
    A(const A& obj) {
        std::cout << "KK" << std::endl;
    }
    A& operator=(const A& obj) {
        std::cout << "OP=" << std::endl;
        return *this;
    }
};

class B {
    A a;
};

void f(A obj) {}

A g(int a) {
    return A(a);
}

A h() {
    A a;

    return a;
}

int main()
{
    /*Censor c1([](char ch) {return ch >= '0' && ch <= '9'; });
    Text t1("hello1234fgh", c1);
    Text t2("eeeeee23456", c1);

    t1.print();
    t2.print();
    */
    
    B b;
    B b1;

    b = b1;
}
