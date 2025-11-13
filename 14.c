#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int val) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node *root, int val) {
    if(root == NULL)
        return createNode(val);
    if(val < root->data)
        root->left = insert(root->left, val);
    else if(val > root->data)
        root->right = insert(root->right, val);
    return root;
}

struct Node* findMin(struct Node *node) {
    while(node->left != NULL)
        node = node->left;
    return node;
}

struct Node* deleteNode(struct Node *root, int val) {
    if(root == NULL)
        return root;

    if(val < root->data)
        root->left = deleteNode(root->left, val);
    else if(val > root->data)
        root->right = deleteNode(root->right, val);
    else {
        // Node with only one child or no child
        if(root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children
        struct Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(struct Node *root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node *root = NULL;
    int choice, val;

    while(1) {
        printf("\n1.Insert\n2.Delete\n3.Display (Inorder)\n4.Exit\nEnter choice: ");
        scanf("%d", &choice);
        if(choice == 1) {
            printf("Enter value to insert: ");
            scanf("%d", &val);
            root = insert(root, val);
        }
        else if(choice == 2) {
            printf("Enter value to delete: ");
            scanf("%d", &val);
            root = deleteNode(root, val);
        }
        else if(choice == 3) {
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
        }
        else if(choice == 4)
            break;
        else
            printf("Invalid choice\n");
    }
    return 0;
}
