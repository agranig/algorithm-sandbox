#include <stdio.h>
#include <stdlib.h>

typedef struct node node_t;
struct node {
    int data;
    node_t *next;
    node_t *prev;
};

node_t * insert(node_t *head, int data) {
    node_t *n = (node_t*) malloc(sizeof(node_t));
    n->data = data;
    n->prev = NULL;
    n->next = head;
    if(head)
        head->prev = n;
    return n;
}

void print(node_t *head) {
    while(head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

node_t * bubblesort(node_t *head) {
    node_t *newhead = head;
    node_t *cur = head;
    int done = 1;

    do {
        done = 1;
        if(!cur->next) {
            cur = newhead;
            continue;
        }
        if(cur->data > cur->next->data) {
            node_t *oldnext = cur->next;
            node_t *oldprev = cur->prev;
            // TODO: swap!
            done = 0;
        }
        
    } while(!done);

    return newhead;
}

int main() {
    node_t *n = NULL;
    n = insert(n, 5);
    n = insert(n, 3);
    n = insert(n, 9);
    n = insert(n, 0);
    n = insert(n, 4);
    print(n);
    n = bubblesort(n);
    print(n);
}
