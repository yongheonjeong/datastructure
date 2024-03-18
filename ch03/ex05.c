#include <stdio.h>

// 20214935 컴퓨터 공학과 정용헌, 3장 - 05번 

typedef struct person{
    char name[20];
    int age;
    float salary;
}Person;
int main(){
    Person yongheon = {"yongheon",50,1.0};
    printf("name : %s\tage : %d\tsalary : %f",yongheon.name,yongheon.age,yongheon.salary);
}