#include <stdio.h>
#include <stdlib.h>

/* ---------- Stack using Linked List ---------- */
struct StackNode {
    int data;
    struct StackNode *next;
};
struct StackNode *top = NULL;

void push() {
    int val;
    struct StackNode *newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    printf("Enter value to push: ");
    scanf("%d", &val);
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if(top == NULL)
        printf("Stack Underflow\n");
    else {
        struct StackNode *temp = top;
        printf("Popped element: %d\n", top->data);
        top = top->next;
        free(temp);
    }
}

void displayStack() {
    struct StackNode *temp = top;
    if(temp == NULL)
        printf("Stack is empty\n");
    else {
        printf("Stack elements: ");
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

/* ---------- Queue using Linked List ---------- */
struct QueueNode {
    int data;
    struct QueueNode *next;
};
struct QueueNode *front = NULL, *rear = NULL;

void enqueue() {
    int val;
    struct QueueNode *newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    printf("Enter value to enqueue: ");
    scanf("%d", &val);
    newNode->data = val;
    newNode->next = NULL;
    if(front == NULL)
        front = rear = newNode;
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if(front == NULL)
        printf("Queue Underflow\n");
    else {
        struct QueueNode *temp = front;
        printf("Dequeued element: %d\n", front->data);
        front = front->next;
        free(temp);
    }
}

void displayQueue() {
    struct QueueNode *temp = front;
    if(temp == NULL)
        printf("Queue is empty\n");
    else {
        printf("Queue elements: ");
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

/* ---------- Circular Queue using Linked List ---------- */
struct CQueueNode {
    int data;
    struct CQueueNode *next;
};
struct CQueueNode *cfront = NULL, *crear = NULL;

void cenqueue() {
    int val;
    struct CQueueNode *newNode = (struct CQueueNode*)malloc(sizeof(struct CQueueNode));
    printf("Enter value to enqueue: ");
    scanf("%d", &val);
    newNode->data = val;
    newNode->next = NULL;

    if(cfront == NULL) {
        cfront = crear = newNode;
        crear->next = cfront;
    } else {
        crear->next = newNode;
        crear = newNode;
        crear->next = cfront;
    }
}

void cdequeue() {
    if(cfront == NULL)
        printf("Circular Queue Underflow\n");
    else if(cfront == crear) {
        printf("Dequeued element: %d\n", cfront->data);
        free(cfront);
        cfront = crear = NULL;
    } else {
        struct CQueueNode *temp = cfront;
        printf("Dequeued element: %d\n", cfront->data);
        cfront = cfront->next;
        crear->next = cfront;
        free(temp);
    }
}

void displayCQueue() {
    struct CQueueNode *temp = cfront;
    if(cfront == NULL)
        printf("Circular Queue is empty\n");
    else {
        printf("Circular Queue elements: ");
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while(temp != cfront);
        printf("\n");
    }
}

/* ---------- Main Menu ---------- */
int main() {
    int choice;
    while(1) {
        printf("\n1.Stack using Linked List\n2.Queue using Linked List\n3.Circular Queue using Linked List\n4.Exit\nEnter choice: ");
        scanf("%d", &choice);
        if(choice == 1) {
            while(1) {
                int ch;
                printf("\n-- Stack Menu --\n1.Push\n2.Pop\n3.Display\n4.Back\nEnter choice: ");
                scanf("%d", &ch);
                if(ch==1) push();
                else if(ch==2) pop();
                else if(ch==3) displayStack();
                else if(ch==4) break;
                else printf("Invalid choice\n");
            }
        }
        else if(choice == 2) {
            while(1) {
                int ch;
                printf("\n-- Queue Menu --\n1.Enqueue\n2.Dequeue\n3.Display\n4.Back\nEnter choice: ");
                scanf("%d", &ch);
                if(ch==1) enqueue();
                else if(ch==2) dequeue();
                else if(ch==3) displayQueue();
                else if(ch==4) break;
                else printf("Invalid choice\n");
            }
        }
        else if(choice == 3) {
            while(1) {
                int ch;
                printf("\n-- Circular Queue Menu --\n1.Enqueue\n2.Dequeue\n3.Display\n4.Back\nEnter choice: ");
                scanf("%d", &ch);
                if(ch==1) cenqueue();
                else if(ch==2) cdequeue();
                else if(ch==3) displayCQueue();
                else if(ch==4) break;
                else printf("Invalid choice\n");
            }
        }
        else if(choice == 4)
            break;
        else
            printf("Invalid choice\n");
    }
    return 0;
}
