## Blitz Test

**При всички задачи работим в Little-Endian x86 операционна система (4-байтови указатели)** 

**Задача 1.** Какво ще се отпечата?
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

**Задача 2.** Какво ще се отпечата на конзолата?
```c++
class A
{
    int number;
public:
    virtual void f()
    {
        std::cout<< "A";
    }
};

class B : public A
{
    double anotherNumber;
public:
    void f() override
    {
        std::cout << "B";
    }
};


int main()
{
    std::cout << sizeof(A);
    std::cout << std::endl;
    std::cout << sizeof(B);
}
```

**Задача 3.** Малко теория:
1) Kакъв недостатък откъм производителност има употребата на виртуални функции?
2) При полиморфни йерархии защо се налага деструктура да е виртуален? (Ако ви е по-лесно, дайте пример и обяснете по него)

**Задача 4.** Какво ще се случи след изпълнение на кода?
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

**Задача 5.** Има ли проблем с кода? Ако да - обяснете какъв. Ако не - какво ще изведе?
```c++
class Base
{
    int number;
public:
    Base(int n): number(n)
    {

    }

    virtual void printData()
    {
        std::cout << "Base class" << std::endl;
        std::cout << "Number: " << number << std::endl;
    }
};

class Der : public Base
{
    int* myArr = nullptr;
    size_t mySize = 0;
public:
    Der(const int* arr, size_t size): Base(5)
    {
        // validation, nullptr checks and more...

        mySize = size;
        myArr = new int[mySize];

        for(size_t i = 0; i < size; i++)
        {
            myArr[i] = arr[i];
        }        
    }

    void printData() override
    {
        Base::printData();
        std::cout << "Der class" << std::endl;
        for(size_t i = 0; i < size; i++)
        {
            std::cout << i << ": "<< myArr[i] << std::endl;
        }  
    }

    ~Der()
    {
        delete[] myArr;
        myArr = nullptr;
        mySize = 0;
    }
};

int main()
{
    const int arr[] = {1, 2, 3};
    Base* ptr = new Der(arr, 3);

    ptr->printData();

    delete ptr;
}
```
