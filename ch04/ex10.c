#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct Stack{
    element* data;
    int top;
    int capacity;
}StackType;

void stack_init(StackType* s,element size){
    s->top = -1;
    s->capacity=size;
    s->data = (element*)malloc(sizeof(element)*s->capacity);
}

int is_full(StackType* s){
    return (s->top >= (s->capacity-1));
}

int is_empty(StackType* s){
    return s->top == -1;
}

void push(StackType* s,element n){
    if(is_full(s)){
        fprintf(stderr,"the stack is full.");
        exit(1);
    }
    s->data[++(s->top)] = n;
}

int pop(StackType*s){
    if(is_empty(s)){
        fprintf(stderr,"the stack is empty.");
        exit(1);
    }
    return s->data[(s->top)--];
}

int peek(StackType* s){
    if(is_empty(s)){
        fprintf(stderr,"the stack is empty.");
        exit(1);
    }
    return s->data[s->top];
}
int main(){
    StackType s;
    int size;
    int num;

    printf("정수 배열의 크기: ");
    scanf_s("%d",&size);
    stack_init(&s,size);
    
    printf("정수를 입력하시오: ");
 
    for(int i=0;i<size;i++){
        scanf_s("%d",&num);
        push(&s,num);
    }



    while(!is_empty(&s)){
        printf("%d ",pop(&s));
    }

    free(s.data);
}