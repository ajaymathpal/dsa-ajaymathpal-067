#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node *head = NULL;

void insert_begin() {
    int val;
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value to insert at beginning: ");
    scanf("%d", &val);
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;
    if(head != NULL)
        head->prev = newNode;
    head = newNode;
}

void insert_end() {
    int val;
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value to insert at end: ");
    scanf("%d", &val);
    newNode->data = val;
    newNode->next = NULL;

    if(head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        struct Node *temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void delete_begin() {
    if(head == NULL)
        printf("List is empty\n");
    else {
        struct Node *temp = head;
        head = head->next;
        if(head != NULL)
            head->prev = NULL;
        printf("Deleted: %d\n", temp->data);
        free(temp);
    }
}

void delete_end() {
    if(head == NULL)
        printf("List is empty\n");
    else if(head->next == NULL) {
        printf("Deleted: %d\n", head->data);
        free(head);
        head = NULL;
    } else {
        struct Node *temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        printf("Deleted: %d\n", temp->data);
        temp->prev->next = NULL;
        free(temp);
    }
}

void display() {
    struct Node *temp = head;
    if(temp == NULL)
        printf("List is empty\n");
    else {
        printf("Doubly Linked List: ");
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
        printf("\n1.Insert at Beginning\n2.Insert at End\n3.Delete from Beginning\n4.Delete from End\n5.Display\n6.Exit\nEnter choice: ");
        scanf("%d", &choice);
        if(choice == 1)
            insert_begin();
        else if(choice == 2)
            insert_end();
        else if(choice == 3)
            delete_begin();
        else if(choice == 4)
            delete_end();
        else if(choice == 5)
            display();
        else if(choice == 6)
            break;
        else
            printf("Invalid choice\n");
    }
    return 0;
}
