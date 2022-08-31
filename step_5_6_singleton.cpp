//
// Created by alla on 26.08.22.
//
#include <iostream>

struct Singleton{

    // возврат по ссылке, чтобы не произошло копирование
    static Singleton & instatnce(){
        static Singleton s;
        return s;
    }

    size_t & data(){
        return data_;
    }

private:
    Singleton(){}
    Singleton(Singleton const&);
    Singleton& operator=(Singleton const&);

    size_t data_;
};

int main_singleton(){
    //первое обращение
    Singleton & s = Singleton::instatnce();
    size_t d = s.data();

    d = Singleton::instatnce().data();//вернет ту же ссылку на тот же статический объект


    return 0;
}
