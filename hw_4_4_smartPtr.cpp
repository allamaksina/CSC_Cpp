#include <iostream>

struct Number;
struct BinaryOperation;

struct Visitor{
    virtual void visitNumber(Number const * number) = 0;
    virtual void visitBinaryOperation(BinaryOperation const * binary) = 0;
    virtual ~Visitor() = default;
};

struct Expression
{
    virtual double evaluate() const = 0;
    virtual void visit(Visitor * visitor) const = 0;
    virtual ~Expression() {};
};

struct Number : Expression
{
    explicit Number(double value)
            : value(value)
    {}

    double evaluate() const{
        return value;
    }
    double get_value() const { return value; }

    void visit(Visitor * visitor) const {visitor->visitNumber(this);}

private:
    double value;
};


struct BinaryOperation : Expression
{
    /*
      Здесь op это один из 4 символов: '+', '-', '*' или '/', соответствующих операциям,
      которые вам нужно реализовать.
     */
    BinaryOperation(Expression const * left, char op, Expression const * right)
            : left(left), op(op), right(right)
    { }

    ~BinaryOperation(){
        delete left;
        delete right;
    }

    double evaluate() const{
        double res = 0;
        switch (op) {
            case '+': return left->evaluate() + right->evaluate();
            case '-': return left->evaluate() - right->evaluate();
            case '*': return left->evaluate() * right->evaluate();
            case '/': return left->evaluate() / right->evaluate();
        }
    }

    Expression const * get_left() const {return left;}
    Expression const * get_right() const {return right;}
    char get_op() const {return op;}

    void visit(Visitor * visitor) const {visitor->visitBinaryOperation(this);}

private:
    Expression const * left;
    Expression const * right;
    char op;
};



/* Этот класс вам нужно реализовать */
struct PrintVisitor : Visitor {
    void visitNumber(Number const * number)
    {
        std::cout << number->get_value();
    }

    void visitBinaryOperation(BinaryOperation const * bop)
    {
        std::cout << "(";
        bop->get_left()->visit(this);
        std::cout << " " << bop->get_op() << " ";
        bop->get_right()->visit(this);
        std::cout << ")";
    }
};

bool check_equals(Expression const *left, Expression const *right)
{
    int b = ((int *)right)[0];

    std::cout << *(void **)left << " " << *(void **)right << std::endl;

    return (((int *)left)[0] == ((int *)right)[0]);

    //  return *(void **)left == *(void **)right;
}



struct ScopedPtr
{
    // реализуйте следующие методы:
    explicit ScopedPtr(Expression *ptr = 0): ptr_(ptr){}

    ~ScopedPtr(){ delete ptr_;}

    Expression* get() const     {return ptr_;}

    Expression* release()   {
        Expression * temp = ptr_;
        ptr_ = 0;
        return temp;
    }

    void reset(Expression *ptr = 0){
        delete ptr_;
        ptr_ = ptr;
    }

    Expression& operator*() const   { return *ptr_; }
    Expression* operator->() const  { return ptr_; }


private:
    // запрещаем копирование ScopedPtr
    ScopedPtr(const ScopedPtr&);
    ScopedPtr& operator=(const ScopedPtr&);

    Expression *ptr_;
};

//struct Counter{
//    Counter(): value_(0){}
//    void add(){ value_++;}
//    void sub(){ value_--;}
//    int get() const {return value_;}
//private:
//    int value_;
//};

struct SharedPtr
{
    // реализуйте следующие методы

    explicit SharedPtr(Expression *ptr = 0): ptr_(ptr), counter(0){
        if (ptr_)
            counter = new size_t(1);
    }

    ~SharedPtr(){
        if (counter && (--*counter == 0)){
            delete ptr_;
            delete counter;
        }
    }

    //copy
    SharedPtr(const SharedPtr &other): ptr_(other.ptr_), counter(other.counter){
        if (ptr_) ++*counter;
    }

    //=
    SharedPtr& operator=(const SharedPtr &other){
        if (ptr_ != other.ptr_) {
            if (counter && (--*counter == 0)){
                delete ptr_;
                delete counter;
            }
            ptr_ = other.ptr_;
            counter = other.counter;
            ++*counter;
        }
        return *this;
    }

    Expression* get() const{ return ptr_; }

    void reset(Expression *ptr = 0){
        if (counter && (--*counter == 0)){
            delete ptr_;
            delete counter;
        }
        ptr_ = ptr;
        if (ptr_)
            counter = new size_t(1);
        else
            counter = 0;

    }
    Expression& operator*() const {return *ptr_;}
    Expression* operator->() const {return ptr_;}

    size_t * counter;
private:
    Expression *ptr_;

};

int main_44(){

    SharedPtr p1;
    {
        SharedPtr p2(new Number(2));
        SharedPtr p3(new Number(3));
        SharedPtr p4(p2);
        SharedPtr p5;
        p5 = p2;
        p5 = p4;
        p1 = p5;
        p3.reset(NULL);
        p3 = p5;
        p5.reset(NULL);
        SharedPtr p6;
        SharedPtr p7;
        p7 = p7;
        p7.reset(NULL);
        p7.reset(new Number(8));
        SharedPtr p8(new Number(5));
        p8.reset(NULL);
    }
    p1 = p1;

    auto * a = new Number(5);
    auto * b = new Number(10);

    SharedPtr p0(0);

//    SharedPtr p1(a);
//    std::cout << p1.get() << " " << *p1.counter << std::endl;
//    SharedPtr p2 = p1;
//    SharedPtr p3(p2);
//    std::cout << p1.get() << " " << p2.get() << std::endl;
//    std::cout << *p1.counter << std::endl;
//    std::cout << *p2.counter << std::endl;
//
//    p2.reset(b);
//    p2.reset(a);
//    p2.reset(b);
//
//    std::cout << p2.get() << " " << p2.counter << std::endl;
//    std::cout << p1.get() << " " << p1.counter << std::endl;

//
//
//
//    std::cout << check_equals(a, b) << std::endl;
//
//    int m[2][2] = {{111, 3}, {7, 8}};
//
//    std::cout << *(void **)m << " " << &(**m) <<  " " << &(m[0][0]) << " " << **m <<  std::endl;


    return 0;
}


//// сначала создаём объекты для подвыражения 4.5 * 5
//    Expression * sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
//// потом используем его в выражении для +
//    Expression * expr = new BinaryOperation(new Number(3), '+', sube);
//
//// вычисляем и выводим результат: 25.5
//    std::cout << expr->evaluate() << std::endl;
//

//
//// тут освобождаются *все* выделенные объекты
//// (например, sube будет правым операндом expr, поэтому его удалять не нужно)
//    delete expr;
//
//    return 0;
//}

//-fsanitize=leak при сборке с помощью g++