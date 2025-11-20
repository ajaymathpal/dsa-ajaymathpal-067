#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert() {
    struct Node *newNode, *temp;
    int val;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value to insert: ");
    scanf("%d", &val);
    newNode->data = val;
    newNode->next = NULL;

    if(head == NULL)
        head = newNode;
    else {
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void deleteNode() {
    struct Node *temp, *prev;
    int val;
    if(head == NULL)
        printf("List is empty\n");
    else {
        printf("Enter value to delete: ");
        scanf("%d", &val);
        temp = head;

        if(head->data == val) {
            head = head->next;
            free(temp);
            printf("Node deleted\n");
            return;
        }

        while(temp != NULL && temp->data != val) {
            prev = temp;
            temp = temp->next;
        }

        if(temp == NULL)
            printf("Value not found\n");
        else {
            prev->next = temp->next;
            free(temp);
            printf("Node deleted\n");
        }
    }
}

void display() {
    struct Node *temp;
    if(head == NULL)
        printf("List is empty\n");
    else {
        temp = head;
        printf("Linked List: ");
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice;
    while(1) {
        printf("\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\nEnter choice: ");
        scanf("%d", &choice);
        if(choice == 1)
            insert();
        else if(choice == 2)
            deleteNode();
        else if(choice == 3)
            display();
        else if(choice == 4)
            break;
        else
            printf("Invalid choice\n");
    }
    return 0;
}
