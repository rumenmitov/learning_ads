#include <cstdlib>
#include <iostream>

struct BTreeNode {
    int val;
    struct BTreeNode* left;
    struct BTreeNode* right;

};

struct QueueNode {
    struct BTreeNode* val;
    struct QueueNode* next;
};

void enqueue(struct QueueNode* head, struct QueueNode* tail, struct BTreeNode* node) {
    struct QueueNode* newEl = new QueueNode;
    newEl->val = node;

    if (!head && !tail) {
        head = newEl;
        tail = newEl;
        return;
    }

    tail->next = newEl;
    tail = newEl;
}

struct BTreeNode* dequeue(struct QueueNode* head, struct QueueNode* tail) {
    if (!head && !tail) {
        std::cerr << "Queue is empty!\n";
        exit(1);
    }

    struct BTreeNode* node = head->val;

    if (head == tail) {
        delete head->val;
        delete head;

        return node;

    }

    struct QueueNode* marker = head;
    head = head->next;

    delete marker->val;
    delete marker;

    return node;

}

bool bfs(struct BTreeNode* head, int needle) {
    struct QueueNode* queue_head;
    struct QueueNode* queue_tail;

    while (head) {
        enqueue(queue_head, queue_tail, head->left);
        enqueue(queue_head, queue_tail, head->right);

        if (head->val == needle) {
            return true;

        } else {
            head = dequeue(queue_head, queue_tail);
        }
    }

    return false;
}
