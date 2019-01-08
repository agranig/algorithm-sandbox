#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *left;
    struct node *right;
    int data;
};

struct node *insert(struct node *tree, int data) {
    struct node *root = tree;
    struct node *t = malloc(sizeof(struct node));
    t->left = NULL;
    t->right = NULL;
    t->data = data;

    if(!tree) {
        printf("new %d as root\n", data);
        return t;
    }

    while(tree) {
        if(data < tree->data) {
            printf("new %d le %d, go left\n", data, tree->data);
            if(tree->left) {
                tree = tree->left;
            } else {
                printf("no more at left, put leave\n");
                tree->left = t;
                return root;
            }
        } else if(data > tree->data) {
            printf("new %d gt %d, go right\n", data, tree->data);
            if(tree->right) {
                tree = tree->right;
            } else {
                printf("no more at right, put leave\n");
                tree->right = t;
                return root;
            }
        } else {
            printf("duplicate entry, exit!\n");
            exit(1);
        }

    }
}

int _count(int s, struct node *node) {
    if(!node) return s;
    printf("at %d\n", node->data);
    s = _count(s, node->left);
    s = _count(s, node->right);
    return s+1;
}

int size(struct node *node) {
    int s = 0;
    s = _count(s, node);
    return s;
}

int minValue(struct node *node) {
    if(!node->left)
        return node->data;
    return minValue(node->left);
}

void printTree(struct node *node) {
    if(node->left)
        printTree(node->left);
    printf("%d ", node->data);
    if(node->right)
        printTree(node->right);
}


int main() {
    struct node *tree = NULL;
    tree = insert(tree, 10);
    tree = insert(tree, 8);
    tree = insert(tree, 11);
    tree = insert(tree, 5);
    tree = insert(tree, 9);
    tree = insert(tree, 4);
    tree = insert(tree, 13);
    tree = insert(tree, 3);

    printTree(tree);
    printf("\n");

    printf("size=%d\n", size(tree));
    printf("min=%d\n", minValue(tree));
    return 0;
}
