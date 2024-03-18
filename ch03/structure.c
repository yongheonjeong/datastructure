#include <stdio.h>

typedef struct studentTage
{
    char ame[10];
    int age;
    double gpa;
}student;

int main(){
    student a = {"kim",20,4.3};
    student b = {"park",21,4.2};
    return 0;
}
