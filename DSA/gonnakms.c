#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

typedef struct {
    int data[MAX];
    int top;
} stack;

bool isFull(stack *s) {
    return s->top == MAX;
}

bool isEmpty(stack *s) {
    return s->top == 0;
}

void push(int num, stack *s) {
    if (!isFull(s)) {
        s->data[s->top] = num;
        s->top++;
    } else {
        printf("Stack is full.\n");
    }
}

void pop(stack *s){
    if(!isEmpty(s)){
        (s->top)--;
    } else {
        printf("Stack is empty.\n");
    }
}

int main() {
    stack *s = malloc(sizeof(stack));

    s->top = 0; 

    push(1, s);
    push(3, s);
    pop(s);

    for (int i = 0; i < s->top; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");


    return 0;
}
