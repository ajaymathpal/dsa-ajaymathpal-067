#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head1 = NULL, *head2 = NULL;

struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int val, i;
    for(i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &val);
        newNode->data = val;
        newNode->next = NULL;
        if(head == NULL)
            head = temp = newNode;
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

void display(struct Node *head) {
    if(head == NULL)
        printf("List is empty\n");
    else {
        while(head != NULL) {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
}

struct Node* concatenate(struct Node *list1, struct Node *list2) {
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;

    struct Node *temp = list1;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = list2;
    return list1;
}

int main() {
    int n1, n2;
    printf("Enter number of nodes in first list: ");
    scanf("%d", &n1);
    head1 = createList(n1);

    printf("Enter number of nodes in second list: ");
    scanf("%d", &n2);
    head2 = createList(n2);

    printf("\nFirst Linked List: ");
    display(head1);
    printf("Second Linked List: ");
    display(head2);

    head1 = concatenate(head1, head2);
    printf("\nAfter Concatenation: ");
    display(head1);

    return 0;
}
