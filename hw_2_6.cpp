#include <iostream>
# include <vector>
using namespace std;



char *resize(const char *str, unsigned size, unsigned new_size)
{
    char * m  = new char[new_size];
    for(int i = 0; i < size && i < new_size; i++) {
        m[i] = str[i];
    }
    delete [] str;
    return m;

}

char *resize2(const char *str, unsigned size, unsigned new_size)
{
    cout << str << endl;
    char * m  = new char[new_size];
    unsigned int max_size = (size < new_size) ? size : new_size;
    for(; max_size--; m++, str++) {
        *m = *str;
        cout << str << endl;
    }
    cout << str << endl;
    delete [] str;
    return m;

}

char *getline()
{
    int array_size = 10;
    char * str = new char[array_size];
    char t = '0';
    int i = 0;
    while (cin.get(t) && t != '\n'){
        str[i] = t;
        i++;
        if (i >= array_size){
            str = resize(str, array_size, array_size + 10);
            array_size += 10;
        }
    }
    str[i] = '\0';

    return str;
}

int main_(){

//    char * z = getline();
//    std::cout << z;

    char * str = new char[3];

    str[0] = 'o';
    str[1] = 'r';
    str[2] = 'u';

    char * m = resize2(str, 3, 10);

    for(int i = 0; i < 10; i++){
        std::cout << *(m + i) << " ";
    }


}


void test(){

}