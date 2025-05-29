
**Какво ще отпечата следната програма?**

```c++
#include <iostream>

struct A {
	virtual void f() { std::cout << "A::f()" << std::endl; }
	void g() { std::cout << "A::g()" << std::endl; }
	~A() { std::cout << "~A()" << std::endl; }
};

struct B : A {
	void f() { std::cout << "B::f()" << std::endl; }
	~B() { std::cout << "~B()" << std::endl; }
};

struct C : B {
	void g() { std::cout << "C::g()" << std::endl; }
	~C() { std::cout << "~C()" << std::endl; }
};

int main() {
	A* ptr = new C();
	ptr->f();
	ptr->g();
	delete ptr;
}
```