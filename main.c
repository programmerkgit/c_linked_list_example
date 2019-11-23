#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node *prev, *next;
} Node;

Node *nil;


int init() {
    nil = malloc(sizeof(Node));
    nil->key = 100;
    nil->prev = nil;
    nil->next = nil;
    return 0;
}

void deleteNode(Node *n) {
    if (n == nil) {
        return;
    }
    n->next->prev = n->prev;
    n->prev->next = n->next;
    free(n);
}

void insert(int key) {
    Node *n = (Node *) malloc(sizeof(Node));
    n->key = key;
    n->next = nil->next;
    n->prev = nil;
    nil->next->prev = n;
    nil->next = n;
}

Node *listSearch(int key) {
    Node *target = nil->next;
    while (target != nil && target->key != key) {
        target = target->next;
    }
    return target;
}

void deleteKey(int key) {
    deleteNode(listSearch(key));
}

void deleteFirst() {
    deleteNode(nil->next);
}

void deleteLast() {
    deleteNode(nil->prev);
}

int main() {
    init();
    insert(1);
    insert(2);
    insert(3);
    deleteLast();
    printf("next: %d\n", nil->next->key);
    printf("next next;%d\n", nil->next->next->key);
    printf("next next nex: %d\n", nil->next->next->next->key);
}
