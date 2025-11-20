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

    if(head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        temp = head;
        while(temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
}

void deleteNode() {
    struct Node *temp = head, *prev;
    int val;
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Enter value to delete: ");
    scanf("%d", &val);

    if(head->data == val) {
        if(head->next == head) {
            free(head);
            head = NULL;
        } else {
            temp = head;
            while(temp->next != head)
                temp = temp->next;
            temp->next = head->next;
            free(head);
            head = temp->next;
        }
        printf("Node deleted\n");
        return;
    }

    prev = head;
    temp = head->next;
    while(temp != head && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == head)
        printf("Value not found\n");
    else {
        prev->next = temp->next;
        free(temp);
        printf("Node deleted\n");
    }
}

void display() {
    struct Node *temp = head;
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);
    printf("\n");
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
