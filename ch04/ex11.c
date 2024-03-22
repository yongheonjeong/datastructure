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
    if (is_empty(s)) {
        fprintf(stderr, "the stack is empty.");
        exit(1);
    }
    return s->data[s->top];
}
int main() {

    // bracket[0] = 소괄호, bracket[1] = 중괄호, bracket[2] = 대괄호 
    StackType* bracket;
    bracket = (StackType*)malloc(sizeof(StackType) * 3);
    stack_init(&bracket[0]);
    stack_init(&bracket[1]);
    stack_init(&bracket[2]);

    int b0 = 0, b1 = 0, b2 = 0;

    char ch;

    printf("수식: ");

    int print = 0;

    while ((ch = getchar()) != '\n') {

        if (print++ == 0) {
            printf("괄호 수: ");
        }
        
        switch (ch) {
        case '(':
            push(&bracket[0], ++b0);
            printf("%d ", b0);
            break;
        case '{':
            push(&bracket[1], ++b1);
            printf("%d ", b1);
            break;
        case '[':
            push(&bracket[2], ++b2);
            printf("%d ", b2);
            break;
        case ')':
            printf("%d ", pop(&bracket[0]));
            break;
        case '}':
            printf("%d ", pop(&bracket[1]));
            break;
        case ']':
            printf("%d ", pop(&bracket[2]));
            break;
        default:
            break;
        }
    }
}