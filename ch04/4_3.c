#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
}StackType;

void init_stack(StackType* s){
    s->top = -1;
}

int is_empty(StackType *s){
    return (s->top == -1);
}

int is_full(StackType *s){
    return (s->top == (MAX_STACK_SIZE-1));
}

void push(StackType *s,element item){
    if(is_full(s)){
        fprintf(stderr,"스택 포화 에러\n");
        return;
    }
    else s->data[++(s->top)] = item;
}

element pop(StackType* s){
    if(is_empty(s)){
        fprintf(stderr,"스택 공백 에러\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}

element peek(StackType* s)
{
    if(is_empty(s)){
        fprintf(stderr,"스택 공백 에러\n");
        exit(1);
    }
    else return s->data[s->top];
}

int main(void)
{
    StackType s1;

    init_stack(&s1);
    push(&s1,1);
    push(&s1,2);
    push(&s1,3); 

    //도전문제
    StackType s2;
    s2 = s1;
    printf("%d\n",pop(&s2));
    printf("%d\n",pop(&s2));

    //4.4 동적스택,스택 여러개를 동적으로 할당
    StackType *s;
    s = (StackType*)malloc(sizeof(StackType));
    init_stack(s);
    push(s,4);
    push(s,5);
    push(s,6);

    printf("%d\n",pop(s));
    printf("%d\n",pop(s));
    printf("%d\n",pop(s));
    
    free(s);
}