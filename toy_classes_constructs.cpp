#include <iostream>

struct A
{
    virtual void foo() = 0;
    virtual ~A() {}
};

struct B : A
{
    B() { foo(); }
    void foo() { std::cout << "B" << std::endl; }
    ~B() { foo(); }
};

struct C : B
{
    C() { foo(); }
    void foo() { std::cout << "C" << std::endl; }
    ~C() { foo(); }
};

struct D : C
{
    D() { foo(); }
    void foo() { std::cout << "D" << std::endl; }
    ~D(){std::cout << "Delete!" << std::endl;}
};

//int       main()
//{
//    A * object = new D();
//    delete object;
//    return 0;
//}