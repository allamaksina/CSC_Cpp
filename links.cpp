#include <iostream>

void swap(int & a, int & b){
    int t = a;
    a = b;
    b = t;
}

int main__(){
    int a = 10;
    int b = 40;
    swap(a, b);
    std::cout << a << " " << b << std::endl;

    int * p = &a;
    int ** pp = &p;
    int & l = a;
    int * pl = &l;

    std::cout << p << " " << *p << " " << &p << " " << l << " " << &l << " " << pl << " " << &a;

    return 0;
}
