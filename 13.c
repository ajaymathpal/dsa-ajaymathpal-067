#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* create() {
    int val;
    struct Node *newNode;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &val);
    if(val == -1)
        return NULL;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    printf("Enter left child of %d:\n", val);
    newNode->left = create();
    printf("Enter right child of %d:\n", val);
    newNode->right = create();
    return newNode;
}

void inorder(struct Node *root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root) {
    if(root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node *root = NULL;
    root = create();

    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\nPreorder Traversal: ");
    preorder(root);
    printf("\nPostorder Traversal: ");
    postorder(root);
    printf("\n");
    return 0;
}
