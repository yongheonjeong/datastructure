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
    return s->data[s->top];
}


//A~Z 65~90 
//a~z 97~122 

int main() {
    StackType* s;
    char str[30];

    int size = 0;
    int count = 0;

    s = (StackType*)malloc(sizeof(StackType));

    stack_init(s);
 

    printf("문자열을 입력하시오: ");
    scanf("%[^\n]s", str,sizeof(str));

    
    while (str[size] != '\0') {
        if ((str[size] >= 65 && str[size] <= 90) || (str[size] >= 97 && str[size] <= 122)) {
            if (str[size] >= 65 && str[size] <= 90) {
                push(s, str[size] + 32);
                size++;
                continue;
            }
            else {
                push(s, str[size]);
            }
        }

        size++;
    }

    

    for (int i = 0; i < size; i++) {
        if (str[i] >= 65 && str[i] <= 90) {
            if ((str[i] + 32) == peek(s)) {
                pop(s);
                count++;
            }
            else {
                break;
            }
        }
        else if (str[i] >= 97 && str[i] <= 122) {
            if (str[i] == peek(s)) {
                pop(s);
                count++;
            }
            else {
                break;
            }
        }
        else {
            count++;
        }
    }

    if (count == size) {
        printf("화문입니다!");
    }
    else {
        printf("화문이 아닙니다!");
    }
 
    free(s);
}