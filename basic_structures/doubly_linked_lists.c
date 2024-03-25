#include <stdio.h>
#include <stdlib.h>
struct Node {
    int val;
    struct Node* next;
    struct Node* prev;
};

struct Node* prepend(struct Node* head, int val) {
    struct Node* el = (struct Node*) malloc(sizeof(struct Node));
    if (el == NULL) {
        fprintf(stderr, "Couldn't allocate memory!\n");
        exit(1);
    }

    el->val = val;

    if (head == NULL) return el;

    head->prev = el;
    el->next = head;

    return el;
}

struct Node* append(struct Node* head, int val) {
    struct Node* el = (struct Node*) malloc(sizeof(struct Node));
    if (el == NULL) {
        fprintf(stderr, "Couldn't allocate memory!\n");
        exit(1);
    }

    el->val = val;

    if (head == NULL) return el;

    struct Node* cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }

    cur->next = el;
    el->prev = cur;

    return head;
}

struct Node* insert(struct Node* head, int idx, int val) {

    if (idx == 0) return prepend(head, val);

    struct Node* cur = head;
    for (int i = 0; i < idx; i++) {
        cur = cur->next;

        if (cur == NULL) return append(head, val); 
    }

    struct Node* el = (struct Node*) malloc(sizeof(struct Node));
    if (el == NULL) {
        fprintf(stderr, "Couldn't allocate memory!\n");
        exit(1);
    }

    el->val = val;

    // NOTE: attach node first, break links second
    el->next = cur->next;
    el->prev = cur;

    cur->next->prev = el;
    cur->next = el;

    return head;
}

int get(struct Node* head, int idx) {
    if (!head) return NULL;

    int i = 0;
    struct Node* cur = head;

    while (i < idx && cur->next != NULL) {
        i++;
        cur = cur->next;
    }

    return cur->val;
}

struct Node* removeVal(struct Node* head, int needle) {
    if (!head) return NULL;

    struct Node* cur = head;

    int idx = 0;
    while (cur->next != NULL) {
        /* if (cur->val == needle) return removeAt(head, idx); */
        idx++;
        cur = cur->next;
    }

    return head;
}

struct Node* removeAt(struct Node* head, int idx) {
    if (!head) return NULL;

    int i = 0;
    struct Node* cur = head;

    while (cur->next != NULL && i < idx) {
        cur = cur->next;
    }

    struct Node* prev = cur->prev;
    struct Node* next = cur->next;

    if (!prev && !next) {
        free(head);
        head = NULL;
    }

    if (!prev) {
        next->prev = NULL;
        free(cur);
        cur = NULL;
    }

    if (!next) {
        prev->next = NULL;
        free(cur);
        cur = NULL;
    }

    return head;
}
