#include <iostream>

struct Foo {
    void say() const { std::cout << "Foo says: " << msg << "\n"; }
protected:
    Foo(const char *msg) : msg(msg) { }
private:
    const char *msg;
};

void foo_says(const Foo& foo) { foo.say(); }

//struct Foo_kid : Foo{
//    explicit Foo_kid(const char *msg): Foo(msg){}
//};

//Foo get_foo(const char *msg) {
//    Foo_kid s(msg);
//    Foo s2 = s;
//    return s2;
//}

struct get_foo : Foo
{
    explicit get_foo(const char *msg) : Foo(msg) {}
};

//int main(){
//    foo_says(get_foo("msg"));
//}