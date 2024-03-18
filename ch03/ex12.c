#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct example {
    int num;
    char str[20];
}Example;

int main() {
    Example* sp;
    sp = (Example*)malloc(sizeof(Example));
    sp->num = 100;
    strcpy(sp->str, "just testing");

    printf("%d %s", sp->num, sp->str);

    free(sp);
}