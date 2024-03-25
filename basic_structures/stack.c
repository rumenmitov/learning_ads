#include <stdio.h>
#include <stdlib.h>
struct Node {
    int val;
    struct Node* prev;
};

struct Stack {
    struct Node* head;
};

void push(struct Stack* s, int val) {
    struct Node* newEl = (struct Node*) malloc(sizeof(struct Node));
    if (newEl == NULL) {
        fprintf(stderr, "Couldn't allocate memory!\n");
        exit(1);
    }

    newEl->val = val;

    if (s->head) {
        newEl->prev = s->head;
    }

    s->head = newEl;
}

int pop(struct Stack* s) {
    if (s->head == NULL) {
        fprintf(stderr, "Stack is empty!\n");
        return 0;
    }

    int val = s->head->val;

    struct Node* cur = s->head;
    s->head = s->head->prev;

    free(cur);
    cur = NULL;

    return val;
}

int peek(struct Stack* s) {
    if (s->head == NULL) {
        fprintf(stderr, "Stack is empty!\n");
        return 0;
    }

    return s->head->val;
}
