#include <iostream>

int ** create_2d_array(size_t a, size_t b){
    int ** m = new int *[a];
    m[0] = new int [a * b];
    for (size_t i = 1; i < a; ++i){
        m[i] = m[i - 1] + b;
    }
    return m;
}

void delete_2d_array(int ** m, size_t a){
    delete [] m[0];
    delete [] m;
}