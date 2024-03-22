#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct Stack {
    element* data;
    int top;
    int capacity;
}StackType;

void stack_init(StackType* s) {
    s->top = -1;
    s->capacity = 1;
    s->data = (element*)malloc(sizeof(element) * s->capacity);
}

int is_full(StackType* s) {
    return (s->top >= (s->capacity - 1));
}

int is_empty(StackType* s) {
    return s->top == -1;
}

void push(StackType* s, element n) {
    if (is_full(s)) {
        s->capacity *= 2;
        s->data = (StackType*)realloc(s->data, sizeof(element) * s->capacity);
    }
    s->data[++(s->top)] = n;
}

int pop(StackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "the stack is empty.");
        exit(1);
    }
    return s->data[(s->top)--];
}

int peek(StackType* s) {
    return s->data[s->top];
}

int size(StackType* s){
    
}

// 0 -> 48
// 9 -> 57

int main(){
    StackType* s;
    s = (StackType*)malloc(sizeof(StackType)*10);
    
    for(int i=0;i<10;i++){
        stack_init(&s[i]);
    }

    char ch;

    int alloc=0;
    int sign=0;
    printf("정수를 입력하시오: ");
    while( (ch=getchar()) != '\n'){
        if(ch>=48 && ch <=57){
            for(int f=0;f<10;f++){
                if(peek(&s[f]) == (ch-48)){
                    push(&s[f],ch-48);
                    sign++;
                    break;
                }               
            }

            if(sign){
                sign--;
                continue;
            }else{
                push(&s[alloc++],(int)ch-48);
            }
        }
    }
    
    printf("출력: ");
    for(int i=0;i<10;i++){
        if(s[i].top != -1){
            printf("%d",peek(&s[i]));
        }
    }

    free(s);
}