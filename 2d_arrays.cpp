#include <iostream>

int ** create_simple_2d_array(size_t a, size_t b){
    int ** m = new int *[a];
    for (size_t i = 0; i < a; ++i){
        m[i] = new int[b];
    }
    return m;
}

int ** create_2d_array(size_t a, size_t b){
    int ** m = new int *[a];
    m[0] = new int [a * b];
    for (size_t i = 1; i < a; ++i){
        m[i] = m[i - 1] + b;
    }
    return m;
}

void delete_2d_array(int ** m){
    delete [] m[0];
    delete [] m;
}

int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
    int ** m_new = create_2d_array(cols, rows);

    for(int i = 0; i < cols; i++){
        for (int j = 0; j < rows; j++){
            m_new[i][j] = m[j][i];
        }
    }
    return m_new;
}

void swap_min(int *m[], unsigned rows, unsigned cols)
{
    int min_row_index = 0;
    int min = m[0][0];
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j){
            if (min > m[i][j]){
                min = m[i][j];
                min_row_index = i;
            }
        }
    }

    if (min_row_index != 0) {
        std::swap(m[0], m[min_row_index]);
    }
}


int main_2d(){

    unsigned rows = 5, cols = 7;

    int ** m = create_2d_array(rows, cols);
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j){
            m[i][j] = i + j * j;
        }
    }

    m[3][2] = -100;

    std::cout << "matrix:" << std::endl;
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j){
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    };


    int ** m_t = transpose(m, rows, cols);
    swap_min(m, rows, cols);
//    std::cout << "matrix transposed:" << std::endl;
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j){
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    };


    return 0;
}