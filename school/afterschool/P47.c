#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int no;
    int score;
    struct node *next;
} Node;

void delete(Node *root, int no) {
    Node *prev = root;
    for (Node *cur = root->next; cur != NULL; cur = cur->next) {
        if (cur->no == no) {
            prev->next = cur->next;
            continue;
            // return;
        }
        prev = cur;
    }
}

int main() {
    Node *heada = malloc(sizeof(Node)), *headb = malloc(sizeof(Node));
    Node *taila = heada, *tailb = headb;

    bool state = true;
    
    
    for (;;) {
        int no, score;
        scanf("%d %d", &no, &score);
        if (no < 0) {
            if (state) {
                state = false;
                continue;
            } else {
                break;
            }
        }
        Node *t = malloc(sizeof(Node));
        t->no = no;
        t->score = score;
        t->next = NULL;
        if (state) {
            taila->next = t;
            taila = t;
        } else {
            tailb->next = t;
            tailb = t;
        }
    }

    for (Node *curb = headb->next; curb != NULL; curb = curb->next) {
        delete(heada, curb->no);
    }

    for (Node *cura = heada->next; cura != NULL; cura = cura->next) {
        printf("%d %d\n", cura->no, cura->score);
    }

    return 0;
}