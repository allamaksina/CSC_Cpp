#include <string>
#include <iostream>
using namespace std;

struct Person {
    Person(string const& name, int age)
            : name_(name), age_(age) {}
    // virtual allows to address fun name() according to concrete object, not to the one from parent class
    virtual string name() const { return name_; }

    int age() const { return age_; }

    // no realization, abstract method. So the class is abstract too - one can't create an object of this class.
    virtual string occupation() const = 0;

    // virtual destructor - every object of child-class would be deleted correctly with all its fields.
    // If it is not virtual, destructor deletes just base class fields;
    virtual ~Person(){}

protected:
    // нарушает инкапсуляцию. Любой наследник имеет доступ к этим полям,
    // и, таким образом может сломать инвариант класса
    string name_;
    int age_;
};

struct Professor : Person{

    Professor(string const & name, int age, string const& thesis)
        : Person(name, age), thesis_(thesis){}

    string name() const override {return "Prof. " + Person :: name();}

    string  occupation() const override {return "professor";}

    virtual string thesis(){return thesis_;}

private:
    string thesis_;

};

struct Student : Person{

    Student(string const& name, int age, string uni): Person(name, age), university_(uni){}

    string university() const {return university_;}

    string  occupation() const override {return "student";}

private:
    string university_;
};


//int main() {
//
//    Professor pr("Stroustrup", 67, "C++");
//    cout << pr.name() << endl;
//    Person *p = &pr;
//    // if non-virtual then "Bibi", virtual "Prof. Bibi"
//    cout << p->name() << endl;
//    return 0;
//}



// g++ -fdump-lang-class csc_cpp_4_2.cpp -o persons