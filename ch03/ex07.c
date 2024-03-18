#include <stdio.h>

// 20214935 컴퓨터 공학과 정용헌, 3장 - 07번 

typedef struct complex{
    float real;
    float imaginary;
}Complex;

Complex complex_add(Complex a,Complex b){
    Complex c;
    c.real = a.real + b.real;
    c.imaginary = a.imaginary + b.imaginary;
    return c;
}

int main(){
    Complex c1 = {7.4,3.1};
    Complex c2 = {5.2,4.2};
    Complex c3 = complex_add(c1,c2);
    printf("c3 : %.1f + %.1fi\n",c3.real,c3.imaginary);
}