#include <cstddef> // size_t
#include <cstring> // strlen, strcpy
#include <algorithm>
#include <iostream>

struct String;



struct String {

    /* Реализуйте этот конструктор */
    String(const char *str = "")
        : size(strlen(str)), str(new char[size + 1])
        {
            strcpy(this->str, str);
        }

    /* Реализуйте этот конструктор */
    String(size_t n, char c)
        : size(n), str(new char[size + 1])
        {
            for (int i = 0; i < n; ++i){
                str[i] = c;
            }
            str[n] = '\0';
        }

    /* Реализуйте конструктор копирования */
    // видимо если объект уже существует, то перед запуском конструктора, запускается деструктор
    // и все освобождает, поэтому освобождать нечего, т.к. объекта нет (видимо!!)
    String(const String &other)
        : size(other.size), str(new char[size + 1])
        {
            for(size_t i = 0; i < size; ++i)
                str[i] = other.str[i];
            str[size] = '\0';
        }

    /* Реализуйте оператор присваивания */
    String &operator=(const String &other){
        if (this != &other)
            String(other).swap(*this);
        return *this;
    }

    void swap(String &a) {
        std::swap(size, a.size);
        std::swap(str, a.str);
    }

    /* и деструктор */
    ~String(){
        delete [] str;
    }

    /* Реализуйте этот метод. */
    void append(String &other)
    {
        char * temp = new char[size + other.size + 1];
        for (int i = 0; i < size; ++i){
            temp[i] = str[i];
        }
        for (int i = 0; i < other.size; ++i){
            temp[size + i] = other.str[i];
        }
        temp[size + other.size] = '\0';
        delete [] str;
        str = temp;
        size += other.size;

        //strcat
    }

//    char & at(size_t i) {
////        std::cout << "non-const";
//        return str[i];}
//    char   at(size_t i) const {
////        std::cout<<"const";
//        return str[i];}

    struct Substring{

//        Substring(size_t const start, size_t size, char *str)
//                : start_(start), size_(size - start), str_(new char[size - start]){
//            for (size_t j = start; j < size; ++j){
//                str_[j - start] = str[j];
//            }
//        }

        Substring(size_t start, char *str)
        : start_(start), str_(str)
        {}

        String operator[](size_t end) const{

            String res(str_);
            res.str[end - start_] = '\0';
            res.size = end - start_;

//            char * c = new char[end - start_];
//            for (int i = 0; i < end - start_; ++i){
//                c[i] = str_[i];
//            }
//            String res(c);
//            delete [] c;
            return res;
        }

        size_t start_;
//        size_t size_;
        char *str_;
    };

    Substring operator[](size_t i) const{

//        Substring c(i, size, str);
        Substring c(i, str + i);
        return c;


    }

    size_t size;
    char *str;
};


//int main(){
//
//    const char * c = "qwerty";
//    String c2(c + 3);
//    std::cout << c2.str << std::endl;
//
//
//    String const hello("hello");
//    String const hell = hello[0][4]; // теперь в hell хранится подстрока "hell"
//    String const ell  = hello[1][4]; // теперь в ell хранится подстрока "ell"
//    std::cout << ell.str << std::endl;
//
//    return 0;
//}

//struct Person{
//    Person(String name, int age)
//        : name_(name), age_(age)
//    {}
//
//    String name() const {return name_;}
//    int     age() const {return age_;}
//
//protected:
//    // нарушает инкапсуляцию. Любой наследник имеет доступ к этим полям,
//    // и, таким образом может сломать инвариант класса
//    String name_;
//    int age_;
//};

//struct Professor : Person{
//    String name() const {
//        String p = "Prof. ";
//        p.append(Person :: name());
//        return p;
//    }
//};

//struct Student : Person{
//    Student(String name, int age, String uni): Person(name, age), university_(uni){}
//    String university() const {return university_;}
//private:
//    String university_;
//};

//int main(){
//
////    String s = "abcd";
////    std::cout << s.size << ' ' << s.str << std::endl;
////
////    String s2;
////    s2 = s;
////    std::cout << s2.str << std::endl;
//
//    String greet("Hello");
//    char ch1 = greet.at(0);
//
//    String const const_greet("Hello, Const!");
//    char const &ch2 = const_greet.at(0);
//
//    return 0;
//}