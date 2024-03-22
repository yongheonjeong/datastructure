#include <stdio.h>
#include <stdlib.h>

typedef char element;

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
    if (is_empty(s)) {
        fprintf(stderr, "the stack is empty.");
        exit(1);
    }
    return s->data[s->top];
}

//A~Z 65~90 
//a~z 97~122 
int main() {
    char ch;

    StackType* s;
    s=(StackType*)malloc(sizeof(StackType)*26);
    for(int i=0;i<26;i++){
        stack_init(&s[i]);
    }
    printf("문자열을 입력하시오: ");
    while((ch=getchar()) != '\n'){
        if(ch>=65 && ch<=90){
            push(&s[ch-65],ch);
        }else if(ch>=97 && ch<=122){
            push(&s[ch-97],ch);
        }
    }

    printf("압축된 문자열: ");
    for(int i=0;i<26;i++){
       
        if(s[i].top != -1){
            
            printf("%d",s[i].top+1);
            ch=peek(&s[i]);
            
            if(ch<97){
                ch += 32;
                printf("%c",ch);
            }else{
                printf("%c",ch);
            }
        }
    }
    
    free(s);
}