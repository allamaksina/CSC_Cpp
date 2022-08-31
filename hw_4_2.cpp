#include <iostream>

void foo(char c){std::cout << "char" << std::endl;};
void foo(unsigned char c){std::cout << "unsigned char" << std::endl;};
void foo(signed char c){std::cout << "signed char" << std::endl;};

void promotion(char &) { std::cout << "char" << std::endl; }
void promotion(int  &) { std::cout << "int"  << std::endl; }
void promotion(long &) { std::cout << "long" << std::endl; }

//int main(){
////    foo(97);
//    short sh = 10;
//    promotion(sh);
//}