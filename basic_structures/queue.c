#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

struct Queue {
    struct Node* head;
    struct Node* tail;
};

void enqueue(struct Queue* q, int val) {
    struct Node* newEl = (struct Node*) malloc(sizeof(struct Node));
    if (newEl == NULL) {
        fprintf(stderr, "Couldn't allocate memory!\n");
        exit(1);
    }

    newEl->val = val;
    newEl->next = NULL;

    if (q->tail) {
        q->tail->next = newEl;
        q->tail = newEl;
    } else {
        q->head = newEl;
        q->tail = newEl;
    }
}

int dequeue(struct Queue* q) {
    int val;

    if (q->head) {
        struct Node* head = q->head;
        q->head = q->head->next;

        val = head->val;

        free(head);
        head = NULL;
    } else {
        fprintf(stderr, "List is empty!");
        val = 0;
    }

    return val;
}

int peek(struct Queue* q) {
    if (q->head) return q->head->val;
    else return NULL;
}
