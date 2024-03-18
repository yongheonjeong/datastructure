#include <stdio.h>

// 20214935 컴퓨터 공학과 정용헌, 3장 - 06번 

typedef struct complex{
    float real;
    float imaginary;
}Complex;

int main(){
    Complex c1 = {7.4,3.1};
    Complex c2 = {5.2,4.2};
    printf(" c1 : %.1f + %.1fi\n c2 : %.1f + %.1fi",c1.real,c1.imaginary, c2.real,c2.imaginary);
}