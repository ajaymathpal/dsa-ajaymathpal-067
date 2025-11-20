#include <stdio.h>
#define MAX 5

int stack[MAX], top = -1;
int queue[MAX], front = -1, rear = -1;
int cqueue[MAX], cfront = -1, crear = -1;

/* Stack Operations */
void push() {
    int val;
    if(top == MAX - 1)
        printf("Stack Overflow\n");
    else {
        printf("Enter value to push: ");
        scanf("%d", &val);
        stack[++top] = val;
    }
}

void pop() {
    if(top == -1)
        printf("Stack Underflow\n");
    else
        printf("Popped element: %d\n", stack[top--]);
}

void displayStack() {
    int i;
    if(top == -1)
        printf("Stack is empty\n");
    else {
        printf("Stack elements: ");
        for(i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

/* Queue Operations */
void enqueue() {
    int val;
    if(rear == MAX - 1)
        printf("Queue Overflow\n");
    else {
        printf("Enter value to enqueue: ");
        scanf("%d", &val);
        if(front == -1)
            front = 0;
        queue[++rear] = val;
    }
}

void dequeue() {
    if(front == -1 || front > rear)
        printf("Queue Underflow\n");
    else
        printf("Dequeued element: %d\n", queue[front++]);
}

void displayQueue() {
    int i;
    if(front == -1 || front > rear)
        printf("Queue is empty\n");
    else {
        printf("Queue elements: ");
        for(i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

/* Circular Queue Operations */
void cenqueue() {
    int val;
    if((cfront == 0 && crear == MAX - 1) || (crear + 1) % MAX == cfront)
        printf("Circular Queue Overflow\n");
    else {
        printf("Enter value to enqueue: ");
        scanf("%d", &val);
        if(cfront == -1)
            cfront = 0;
        crear = (crear + 1) % MAX;
        cqueue[crear] = val;
    }
}

void cdequeue() {
    if(cfront == -1)
        printf("Circular Queue Underflow\n");
    else {
        printf("Dequeued element: %d\n", cqueue[cfront]);
        if(cfront == crear)
            cfront = crear = -1;
        else
            cfront = (cfront + 1) % MAX;
    }
}

void displayCQueue() {
    int i;
    if(cfront == -1)
        printf("Circular Queue is empty\n");
    else {
        printf("Circular Queue elements: ");
        i = cfront;
        while(1) {
            printf("%d ", cqueue[i]);
            if(i == crear)
                break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

/* Main Menu */
int main() {
    int choice;
    while(1) {
        printf("\n1.Stack Operations\n2.Queue Operations\n3.Circular Queue Operations\n4.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
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
                break;
            case 2:
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
                break;
            case 3:
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
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
