#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node *node, int data) {
    if (node == NULL) {
        return createNode(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

int getHeight(Node *node) {
    if (node == NULL) {
        return -1;
    }
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
}

int isBalanced(Node *node) {
    if (node == NULL) {
        return 1;
    }
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    return ((abs(leftHeight - rightHeight) <= 1) && isBalanced(node->left) && isBalanced(node->right));
}

void printInorder(Node *node) {
    if (node != NULL) {
        printInorder(node->left);
        printf("%d ", node->data);
        printInorder(node->right);
    }
}

void freeTree(Node *node) {
    if (node != NULL) {
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int m;
        scanf("%d", &m);
        Node *root = NULL;
        while (m--) {
            int x;
            scanf("%d", &x);
            root = insert(root, x);
        }
        if (isBalanced(root)) {
            printInorder(root);
            printf("\n");
        } else {
            printf("Data tidak ada\n");
        }
        freeTree(root);
    }
    return 0;
}
