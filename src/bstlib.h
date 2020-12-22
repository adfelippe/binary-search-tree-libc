#ifndef _BSTLIB_H_
#define _BSTLIB_H_

#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node* left;
    struct node* right;
};

struct node* createNewNode(int item);
struct node* insertNewNode(struct node* root, int key);
struct node* searchNode(struct node* root, int key);
struct node* removeNode(struct node* root, int key);
int countNodes(struct node* root);
void showBinaryTree(struct node* root);

#endif /*_BSTLIB_H_*/