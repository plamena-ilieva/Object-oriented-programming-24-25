# ООП - Практикум 05.06.2025 Седмица 15

## *Упътване* Нужно е да отговорите в рамките на до 2-3 изречения.

## Задача 1

Какво е абстракция?

## Задача 2

Какво е капсулация?

## Задача 3

 Нека е дадена следната структура: 

```cpp
 struct Employee{
        char name[30];
        double salary; 
        int id;
        bool toBePromoted;
    };
```

Какъв е размерът на структурата Employee?

## Задача 4

Напишете функция, която приема име на файл и връща размера на файла.


## Задача 5

Къде в кода има грешки?

```C++
struct А{
   int n;
   void f(){//do stuff}
   void g() const {//do stuff}

    void h()const { f() }
};

void func(const A& ref){
   ref.f();     //1)
   ref.g();     //2)
   ref.h();     //3)
}
```

## Задача 6

Изведете какво ще се отпечата при изпълнение на следния код

```C++
class A {
public:
	A() {
		std::cout << "Default A\n";
	}

	~A() {
		std::cout << "Destructor A\n";
	}
};

class B {
	A a;
public:
	B() {
		std::cout << "Default B\n";
	}

	~B() {
		std::cout << "Destructor B\n";
	}
};

class C {
	A x;
	B y;
public:
	C() {
		std::cout << "Default C\n";
	}

	~C() {
		std::cout << "Destructor C\n";
	}
};

int main() {
	C c;
}
```

## Задача 7

За тази задача може да използвате следното изображение:

![](https://flylib.com/books/2/253/1/html/2/images/16fig11.jpg)

Какъв ще е резултатът на конзолата от изпълнение на:
```c++
int main()
{
	try
	{
		throw std::invalid_argument("ERROR");
	}
	catch (const std::runtime_error&)
	{
		std::cout << "Runtime error";
	}
	catch (const std::logic_error&)
	{
		std::cout << "Logic error";
	}
	catch (const std::invalid_argument&)
	{
		std::cout << "Invalid argument";
	}
	catch (const std::exception&)
	{
		std::cout << "Exception";
	}
}
```
А) "Runtime error"

B) "Logic error"

C) "Invalid argument"

D) "Exception"

## Задача 8

Кога използваме наследяване и кога композиция?

## Задача 9

Какво ще се отпечата?

```c++
#include <iostream>
#include <string>
using namespace std;
class A
{
	int a, b;// sizeof(int) = 4
	float d;// sizeof(float) = 4
	bool bl;// sizeof(bool) = 1 
   
};
 
class B: private A
{
    bool bl;
};
 
int main(int argc, char const *argv[])
{
	cout<<sizeof(A)<<endl;
	cout<<sizeof(B);
	return 0;
}
```
## Задача 10

Какво ще се случи след изпълнение на кода?
```c++
class A
{
public:
    virtual void f()
    {
        std::cout << "From A";
    }
};

class B : public A
{
public:
    void f() override final
    {
        std::cout << "Virtual From B";
    }
};

class C : public B
{
public:
    void f()
    {
        std::cout << "Shadow From C";
    }
};

int main()
{
    A* ptr = new C();
    ptr->f();
}
```

## Задача 11

Какво ще се отпечата?
```c++
class A
{
    public:
    virtual void f()
    {
        std::cout << "A";
    }
};

class B : public A
{
    public:
    void f() override
    {
        std::cout << "B";
    }
};

class C : public B
{
    public:
    void f()
    {
        std::cout << "C";
    }
};

int main()
{
    A* ptr = new C();
    ptr->f();
}
```

## Задача 12

Дадена е следната йерархия. Начертайте как ще изглежда в паметта обект от тип E. (Трябва да се вижда ясно разположението на всеки родителски клас)

```c++
struct A
{
	int a;
};

struct B : virtual A
{
	int b;
};

struct C : virtual A
{
	int c;
};

struct D : A
{
	int d;
};

struct E : B, C, D
{
	int e;
};
