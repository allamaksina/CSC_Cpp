//
// Created by alla on 25.08.22.
//
#include <iostream>

struct String_1{

    //получает доступ к закрытым полям
    friend struct StringBuffer;

    // тоже дает доступ внешним фукнциям к закрытым полям
    friend std::ostream&
        operator<<(std::ostream & os, String_1 const& s){
        return os << s.data_;
    }

private:
    char * data_;
    size_t len_;
};

struct StringBuffer{

    void get_data(String_1 *c){
        data_buff = c->data_;
    }

    char * data_buff;
};
