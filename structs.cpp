#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

struct Point{
//    Point(): x(0), y(0)
//    {}

    // explicit prohibits struct to be converted from type (eg Point p = 20 transforms to Point {20, 0})
    explicit Point(double x = 0, double y = 0)
    : x(x), y(y)
    {}

    double x;
    double y;

    void shift(double x, double y){
        this->x += x;
        this->y += y;
    }

    void mirror();
};

struct Segment {

    Segment() = default;

    explicit Segment(double length):
    p2(length, 0)
    {}
    explicit Segment(Point p1, Point p2): p1(p1), p2(p2) {}

    Point p1;
    Point p2;

    double length() const {
        double dx = p1.x - p2.x;
        double dy = p1.y - p2.y;
        return sqrt(dx * dx + dy * dy);
    }
};

struct IntArray2D{

    IntArray2D(){};

    // allows to use 1d array as 2d array. eg m.get(i, j) returns address of the (i, j) element
    int & get(size_t i, size_t j) const {
        return data[i * b + j];
    }

    size_t a;
    size_t b;
    int * data;
};

class IntArray{

public:

    // constructors
    IntArray(): data_(new int[1]){}

    explicit IntArray(size_t size): size_(size), data_(new int[size]) {
        data_[0] = size;
    }

    //copy constructor
    IntArray(IntArray const & a)
        : size_(a.size_), data_(new int[size_])
        {
            for(size_t i = 0; i < size_; ++i)
                data_[i] = a.data_[i];
        }

    /*IntArray & operator = (IntArray const &a){
        if (this != &a){
            delete [] data_;
            size_ = a.size_;
            data_ = new int[size_];
            for (size_t i = 0; i < size_; ++i)
                data_[i] = a.data_[i];
        }
        return *this;
    }*/

    IntArray & operator = (IntArray const &a){
        if (this != &a){
            IntArray(a).swap(*this);
        }
        return *this;
    }

    //destructor
    ~IntArray(){
        delete [] data_;
    }

    //methods
    int get(size_t i) const{
        return data_[i];
    }

    int & get(size_t i){
        return data_[i];
    };

    void resize(size_t nsize){
        int * ndata = new int[nsize];
        size_t n = nsize > size_ ? size_ : nsize;
        for (size_t i = 0; i < n; ++i)
            ndata[i] = data_[i];
        delete [] data_;
        data_ = ndata;
        size_ = n;

    }

    void swap(IntArray &a){
        std::swap(size_, a.size_);
        std::swap(data_, a.data_);

        /*
        size_t const t1 = size_;
        size_ = a.size_;
        a.size_ = t1;

        int * const t2 = data_;
        data_ = a.data_;
        a.data_ = t2;*/
    }



private:
    int size_;
    int * data_;
};

double length1(Segment * s){
    double dx = s->p1.x - s->p2.x;
    double dy = s->p1.y - s->p2.y;

    return sqrt(dx * dx + dy * dy);
}

void Point::mirror(){
    this->x = -x;
}

int main_1_(){
    Point p1(0.1, 2);
    Point p2(3.2, 4.1);
    Segment s(p1, p2);
    cout << s.length() << endl;

    IntArray2D m;
    auto * m2 = new IntArray(10);
    IntArray * m3 = new IntArray[10];
    for (size_t i = 0; i != m.a; ++i) {
        for (size_t j = 0; j != m.b; ++j){
            if (m.get(i, j) < 0) m.get(i, j) = 0;
        }
    }
    return 0;
}