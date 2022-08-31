#include <iostream>

struct Vector{

    Vector(double x, double y) : x(x), y(y) {}

    Vector operator-() const{return Vector(-x, -y);}
    Vector operator-(Vector const & other) const{
        return Vector(x - other.x, y - other.y);
    }

    Vector operator*(double d){
        x *= d;
        y *= d;
        return *this;
    }

    Vector operator*=(double d){
        x *= d;
        y *= d;
        return *this;
    }

    double operator[](size_t i){
        return i == 0 ? x : y;
    }

    double x, y;
};

Vector operator*(double d, Vector v){
    return v * d;
}

struct BigNum{

    //prefix
    BigNum & operator ++ (){
        //increment
        return *this;
    }

    //postfix. int = dummy
    BigNum operator ++ (int){
        BigNum tmp(*this);
        ++(*this);
        return tmp;
    }
};

//int main(){
//
////    int a = 0;
////    int b = a++;
////    std::cout << a << " " << b << std::endl;
////    b = ++a;
////    std::cout << a << " " << b << std::endl;
//
//    return 0;
//}