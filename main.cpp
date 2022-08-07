#include <iostream>
#include <iomanip>
#include <cassert>
#include <unordered_map>
#include <vector>

//int d(){
//
//    int a = 0;
//    std::cin >> a;
//
//    if (a) {
//
//        d();
//
//    } else {
//
//        return 0;
//
//    }
//
//    std::cout << a << " ";
//
//}

//double randUniform(){
//
//    return (double)random() / (RAND_MAX + 1.);
//
//}
//
//void eval_pi_monte_carlo(){
//
//    int n = 1000000000;
//    int res = 0;
//
//    for (int i = 0; i < n; ++i){
//
//        double a = randUniform();
//        double b = randUniform();
//
//        if (a * a + b * b < 1){
//            res++;
//        }
//    }
//
//    float c = 4;
//    float pi = c * (float)res / (float)n;
//
//    std::cout << std::setprecision(15);
//    std::cout << pi << std::endl;
//
//}

//int to_bin(int n){
//    int res = 0;
//    int mult = 1;
//    while (n > 0){
//        res += (n % 2) * mult;
//        mult *= 10;
//        n /= 2;
//    }
//
//    return res;
//}
//
//
//int mm_fib(int n){
//
//    int n_bin = to_bin(n);
//
//    int eye[2][2] = {{1, 0}, {0, 1}};
//    int a[2][2] = {{0, 1}, {1, 1}};
//    int b[2][2] = {{0, 1}, {1, 1}};
//    int c[2][2] = {{0, 0}, {0, 0}};
//
//
//
//    for (int i = 0; i < n; i++){
//
//        for(int j = 0; j < 2; ++j){
//            for(int k = 0; k < 2; ++k){
//                c[j][k] = (b[j][0] * a[0][k] + b[j][1] * a[1][k]) % 10;
//            }
//        }
//
//        //std::cout << c[0][0] << " " << c[0][1] << " " << c[1][0] << " " << c[1][1] << std::endl;
//
//        for (int j = 0; j < 2; ++j){
//            for (int k = 0; k < 2; ++k){
//                b[j][k] = c[j][k];
//            }
//
//        }
//    }
//    return b[0][1];
//}
//
//void swap(int &a, int &b){
//    int t = a;
//    a = b;
//    b = t;
//}
//
//void swap_1(int * a, int * b){
//    int t = * a;
//    * a = * b;
//    * b = t;
//}
//
//int main() {
//
//    int k = 10, m = 20;
//    swap(k, m);
//    std::cout << k << ' ' << m << std::endl;
//
//    int s = 50, p = 100;
//    swap_1(&s, &p);
//    std::cout << s << ' ' << p << std::endl;
//
//    return 0;
//
//}

//int max_element(int * m, int size){
//    int max = *m;
//    for (int i = 1; i < size; ++ i){
//        if (m[i] > max)
//            max = m[i];
//    }
//}
//
//int main(){
//
//    int m[10] = {};
//    for (int i = 0; i < 10; ++i){
//        std::cout << *(m + i) << " ";
//    }
//    std::cout << std::endl;
//    for (int * p = m; p <= m + 9; ++p)
//        *p = (p - m) + 1;
//    std::cout << *m << ' ' << m[0] << ' ' << m[1] << ' ' << *(m + 9) << std::endl;
//
//    return 0;
//}
//
//void rotate(int a[], unsigned size, int shift){
//    if (shift > 0 and size > 0){
//        shift %= size;
//        for (int * p = a; p < a + size; ++p){
//            int t = * (p + shift) % size;
////            *(p + shift) = ;
//        }
//
//    }
//
//}




void rec_rot(int a[], unsigned size, int shift, int i){
   if (i){
       int tmp = a[i - 1];
//       std::cout << i << " " << tmp << std::endl;
       rec_rot(a, size, shift, i - 1);
       a[size - 1 - shift + i] = tmp;
   } else {
       for (int j = 0; j < size - shift; j++){
           a[j] = a[j + shift];
       }
   }
}

void rotate(int a[], unsigned size, int shift)
{
    shift = (shift > 0) ? (shift % size) : ((size - (-shift) % size));
    rec_rot(a, size, shift, shift);
}

unsigned strlen1(const char *str)
{
    unsigned res = 0;
    while (*str++)
        res++;

    return res;
}

void strcat1(char *to, const char *from)
{
    while (*to)
        ++to;

    for(; *from;++to, ++from) {
        *to = *from;
    }
    *to = '\0';
}

int strstr2(const char *text, const char *pattern){

    if (!*pattern)
        return 0;

    for (int i = 0; *text; ++text, ++i){
        const char * t = text;
        const char * p = pattern;

        while (*p++ == *t++){
            if (!*p)
                return i;
        }
    }

    return -1;
}

int strstr1(const char *text, const char *pattern)
{
    if (*pattern == '\0')
        return 0;
    if (*text == '\0')
        return -1;

    unsigned int len_pattern = strlen1(pattern);
    unsigned int len_text = strlen1(text);

    if (len_pattern > len_text)
        return -1;

    for (int i = 0; i <= len_text - len_pattern; i++){

        int s = 0;

        for (int j = 0; j < len_pattern; j++){
            if (*(pattern + j) == *(text + j + i))
                s++;
        }
        if (s == len_pattern)
            return i;
    }

    return -1;

}

//int main(){
//
//    int res = strstr1("aaab", "aabb");
//    std::cout << res;
//
//    return 0;
//}

//int main(){
//
////    int a[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
////    rotate(a, 11, -3);
////    for (int i = 0; i < 11; i++){
////        std::cout << a[i] << ' ';
////    }
////    std::cout << std::endl;
//
//    char a[] = "C_string";
//    char b[] = "from1";
////    std::cout << strlen1(a);
//    strcat1(a, b);
//    std::cout << a << std::endl;
//
//
//    return 0;
//}