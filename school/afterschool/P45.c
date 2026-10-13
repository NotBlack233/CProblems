#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct node {
    int64_t data;
    struct node *prev;
    struct node *next;
} Node;

int main() {
    Node *head = malloc(sizeof(Node));
    Node *tail = head;
    head->prev = NULL;
    head->next = NULL;
    
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int64_t x;
        scanf("%lld", &x);
        Node *t = malloc(sizeof(Node));
        t->data = x;
        t->prev = tail;
        t->next = NULL;
        tail->next = t;
        tail = t;
    }

    for (Node *cur = tail; cur != head; cur = cur->prev) {
        printf("%lld ", cur->data);
    }

    return 0;
}