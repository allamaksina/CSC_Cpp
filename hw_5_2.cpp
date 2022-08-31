#include <iostream>

struct Rational {
    Rational(int numerator = 0, int denominator = 1) : numerator_(numerator), denominator_(denominator) {};

    void add(Rational rational) {
        numerator_ = numerator_ * rational.denominator_ + rational.numerator_ * denominator_;
        denominator_ *= rational.denominator_;
    }

    void sub(Rational rational) {
        numerator_ = numerator_ * rational.denominator_ - rational.numerator_ * denominator_;
        denominator_ *= rational.denominator_;
    }

    void mul(Rational rational) {
        numerator_ *= rational.numerator_;
        denominator_ *= rational.denominator_;
    }

    void div(Rational rational) {
        numerator_ *= rational.denominator_;
        denominator_ *= rational.numerator_;
    }

    void neg() {
        numerator_ = -numerator_;
    }

    void inv() {}

    double to_double() const {
        return numerator_ / (double) denominator_;
    }

    Rational operator -() const{ return Rational(-numerator_, denominator_); }

    Rational operator +() const{ return Rational(numerator_, denominator_); }

    Rational & operator -= (Rational const &r){ sub(r); return *this; }
    Rational & operator += (Rational const &r){ add(r); return *this; }
    Rational & operator /= (Rational const &r){ div(r); return *this; }
    Rational & operator *= (Rational const &r){ mul(r); return *this; }

    int get_numerator() const {return numerator_;}
    int get_denominator() const {return denominator_;}

    operator double () const{
        return to_double();
    }

private:
    int numerator_;
    int denominator_;
};

Rational operator + (Rational &l, Rational const &r){ return l += r; }
Rational operator - (Rational &l, Rational const &r){ return l -= r; }
Rational operator * (Rational &l, Rational const &r){ return l *= r; }
Rational operator / (Rational &l, Rational const &r){ return l /= r; }

bool operator == (Rational const& a, Rational const& b){
    return (a.get_numerator() == b.get_numerator()) && (a.get_denominator() == b.get_denominator());
}

bool operator != (Rational const& a, Rational const& b){
    return !(a == b);
}

bool operator < (Rational const& a, Rational const& b){
    return a.get_numerator() * b.get_denominator() < a.get_denominator() * b.get_numerator();
}

bool operator > (Rational const& a, Rational const& b){
    return  b < a;
}

bool operator <= (Rational const& a, Rational const& b){
    return !(a > b);
}

bool operator >= (Rational const& a, Rational const& b){
    return !(a < b);
}


//Rational operator - (int const &d, Rational const & r){ Rational res = r; res -= d; return res; }
//Rational operator * (int const &d, Rational const & r){ Rational res = r; res *= d; return res; }
//Rational operator / (int const &d, Rational const & r){ Rational res = r; res /= d; return res; }


//int main() {
//    Rational r1(1, 2);
//    Rational r2(1, 3);
//    Rational r3(5);
//
//    r1.add(r2);
//    std::cout << r1.to_double() << std::endl;
//    r1.sub(r2);
//    std::cout << r1.to_double() << std::endl;
//    r1.neg();
//    std::cout << r1.to_double() << std::endl;
//    r3.mul(r1);
//    std::cout << r3.to_double() << std::endl;
//    r3.div(r2);
//    std::cout << r3.to_double() << std::endl;
//
//    std::cout << r1.to_double() << " " << r3.to_double() << std::endl;
//    r1 += r3;
//    std::cout << r1.to_double() << std::endl;
//
//}

