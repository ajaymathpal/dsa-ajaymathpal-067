#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

int main() {
    char exp[100];
    int i;
    int op1, op2, res;

    printf("Enter a postfix expression: ");
    scanf("%s", exp);

    for(i = 0; exp[i] != '\0'; i++) {
        if(isdigit(exp[i])) {
            push(exp[i] - '0');
        } else {
            op2 = pop();
            op1 = pop();
            switch(exp[i]) {
                case '+': res = op1 + op2; break;
                case '-': res = op1 - op2; break;
                case '*': res = op1 * op2; break;
                case '/': res = op1 / op2; break;
                case '%': res = op1 % op2; break;
                default: printf("Invalid operator\n"); return 0;
            }
            push(res);
        }
    }

    printf("Result = %d\n", pop());
    return 0;
}
