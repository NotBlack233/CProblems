#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct node {
    int64_t data;
    struct node *next;
} Node;

int main() {
    Node *head = malloc(sizeof(Node));
    Node *tail = head;
    
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int64_t x;
        scanf("%lld", &x);
        Node *t = malloc(sizeof(Node));
        t->data = x;
        t->next = NULL;
        tail->next = t;
        tail = t;
    }

    for (Node *cur = head->next; cur != NULL; cur = cur->next) {
        printf("%lld ", cur->data);
    }

    return 0;
}