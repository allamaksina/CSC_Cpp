#include <cstddef>
#include <algorithm>
#include <iostream>

template <class Type,
          class SizeT = size_t,
          class CRet = Type>
struct Array_simple{

    explicit Array_simple(SizeT size): data_(new Type[size]), size_(size) {}
    ~Array_simple(){ delete [] data_; }

    SizeT size() const { return size_;}

    CRet operator[](size_t i) const{
        return data_[i];
    }
    Type & operator[](size_t i){
        return data_[i];
    }


private:
    Type * data_;
    SizeT size_;
};

//int main(){
//    Array<int> ai(10);
//    Array<float> af(10);
//
//    return 0;
//}

template <typename T>
class Array_a
{
public:
    // Список операций:

    //   конструктор класса, который создает
    //   Array размера size, заполненный значениями
    //   value типа T. Считайте что у типа T есть
    //   конструктор, который можно вызвать без
    //   без параметров, либо он ему не нужен.
    explicit Array_a(size_t size = 0, const T& value = T())
        : size_(size), data_(new T[size])
        {
            for (size_t i = 0; i < size_; ++i){
                data_[i] = value;
            }
        }

    //   конструктор копирования, который создает
    //   копию параметра. Считайте, что для типа
    //   T определен оператор присваивания.
    Array_a(const Array_a & a)
        : size_(a.size_), data_(new T[a.size_])
        {
            for (size_t i = 0; i < size_; ++i){
                data_[i] = a.data_[i];
            }
        }

    ~Array_a(){
        delete [] data_;
    }
    //   деструктор, если он вам необходим.
//
    void swap(Array_a & a){
        std::swap(size_, a.size_);
        std::swap(data_, a.data_);
    }

    //   оператор присваивания.
    Array_a& operator=(const Array_a & a){
        if (this != &a){
            Array(a).swap(*this);
//            delete [] data_;
//            size_ = a.size_;
//            data_ = new T[size_];
//            for (size_t i = 0; i < size_; ++i)
//                data_[i] = a.data_[i];
        }
        return *this;
    }

    //   возвращает размер массива (количество
    //                              элементов).
    size_t size() const{ return size_;}

    //   две версии оператора доступа по индексу.
    T& operator[](size_t i){ return data_[i]; }

    const T& operator[](size_t i) const {return data_[i];}

private:
    size_t size_;
    T * data_;
};


template <typename T>
class Array
{
public:

    //   конструктор класса, который создает
    //   Array размера size, заполненный значениями
    //   value типа T. Если у класса нет конструктора
    //   по умолчанию, то второй аргумент этого конструктора
    //   обязателен.
    explicit Array(size_t size, const T& value)
    : size_(size)
    {
        // можно так: создать указатель на что-то указанного размера. потом разместить там массив.
        // В каждом элементе массива запустить конструктор
        void * p = new char[size_ * sizeof(T)];
        data_ = new (p) T[size_];
        for (size_t i = 0; i < size_; ++i)
            new (data_ + i) T(value);
    }

    //   конструктор класса, который можно вызвать
    //   без параметров. Должен создавать пустой
    //   Array.
    Array(): size_(0), data_(nullptr){}

    //   конструктор копирования, который создает
    //   копию параметра. Для типа T оператор
    //   присваивания не определен.
    Array(const Array& a)
    : size_(a.size_)
    {
        // а можно так: преобразовать к типу Т указатель на массив чар указанного размера
        data_ = (T*) new char[size_ * sizeof(T)];
        for (size_t i = 0; i < size_; ++i)
            new (data_ + i) T(a[i]);
    }

    //   деструктор, если он вам необходим.
    // вызвать деструктор для каждого элемента, а потом удалить сам массив
    ~Array(){
        for (size_t i = 0; i < size_; ++i){
            data_[i].~T();
        }
        delete[] (char*)data_;
    }

    void swap(Array & a){
        std::swap(size_, a.size_);
        std::swap(data_, a.data_);
    }

    //   оператор присваивания.
    Array& operator=(const Array& a){
        if (this != &a){
            Array(a).swap(*this);
        }
        return *this;
    }

    size_t size() const{ return size_;}
    //   возвращает размер массива (количество
    //                              элементов).

    //   две версии оператора доступа по индексу.
    T& operator[](size_t i){return data_[i];}
    const T& operator[](size_t i) const{return data_[i];}

private:
    size_t size_;
    T * data_;
};

int main()
{
    typedef Array<float> ArrayF;
    typedef Array<ArrayF> AArrayF;

    ArrayF a0(1, 3.14);
    std::cout << "a0 created" << std::endl;
    std::cout << a0[0] << std::endl << std::endl;

    AArrayF a(5, a0); // default constructor
    std::cout << "a created" << std::endl;
    std::cout << a[0][0] << std::endl << std::endl;

    AArrayF b(a); // copy constructor
    std::cout << "b created" << std::endl << std::endl;

    AArrayF c; // default constructor
    std::cout << "c created" << std::endl << std::endl;
    c = b; // assignment (calls copy constructor and swap)
    std::cout << "c changed" << std::endl << std::endl;

    return 0;
}
