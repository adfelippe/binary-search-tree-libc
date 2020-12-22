#include "bstlib.h"


/* Private prototypes */
static void printBinaryTree(struct node* root);
static struct node* findNode(struct node* root, int key, struct node** parent);


struct node* createNewNode(int key) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    
    n->key = key;
    n->left = NULL;
    n->right = NULL;

    return n;
}

struct node* insertNewNode(struct node* root, int key) {
    /* If tree is empty, return new node */
    if (root == NULL) {
        return createNewNode(key);
    }

    /* Or else, go down the tree */
    if (key < root->key) {
        root->left = insertNewNode(root->left, key);
    } else if (key > root->key) {
        root->right = insertNewNode(root->right, key);
    }

    return root;
}

struct node* searchNode(struct node* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    /* Node found, return its address */
    if (root->key == key) {
        return root;
    }

    if (root->key > key) {
        return searchNode(root->left, key);
    } else {
        return searchNode(root->right, key);
    }
}

struct node* removeNode(struct node* root, int key) {
    struct node* parent;
    struct node* node;
    struct node* p;
    struct node* q;

    node = findNode(root, key, &parent);

    if (node == NULL) {
        return root;
    }

    if (!node->left || !node->right) {
        if (!node->left) {
            q = node->right;
        } else {
            q = node->left;
        }
    } else {
        p = node;
        q = node->left;

        while (q->right) {
            p = q;
            q = q->right;
        }

        if (p != node) {
            p->right = q->left;
            q->left = node->left;
        }

        q->right = node->right;
    }

    if (!parent) {
        free(node);
        return q;
    }

    if (key < parent->key) {
        parent->left = q;
    } else {
        parent->right = q;
    }

    free(node);

    return root;
}

int countNodes(struct node* root) {
    if (root == NULL) {
        return 0;
    } else {
        /* Count nodes at left, right and sum the tree root */
        return (countNodes(root->left) + countNodes(root->right) + 1);
    }
}

void showBinaryTree(struct node* root) {
    printBinaryTree(root);
    printf("\n");
}

static void printBinaryTree(struct node* root) {
    if (root == NULL) {
        return;
    }

    printf("%i", root->key);
    printf("(");
    printBinaryTree(root->left);
    printBinaryTree(root->right);
    printf(")");
}

static struct node* findNode(struct node* root, int key, struct node** parent) {
    struct node* current = root;
    
    *parent = NULL;

    while(current) {
        if (current->key == key) {
            return current;
        }

        *parent = current;

        if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return NULL;
}


