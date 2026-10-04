#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

// 1. PUSH Operation
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d. Stack is full.\n", x);
        return;
    }
    top++;
    stack[top] = x;
    printf("Pushed: %d\n", x);
}

// 2. POP Operation
void pop() {
    if (top == -1) {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }
    printf("Popped: %d\n", stack[top]);
    top--;
}

// 3. PEEK Operation
void peek() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Top element: %d\n", stack[top]);
}

// 4. DISPLAY Operation
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    printf("--- STACK OPERATIONS DEMO ---\n");
    pop();       // Triggers Underflow
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);    // Triggers Overflow
    
    peek();
    display();
    
    pop();
    display();

    return 0;
}

/* 
====================================================
ADDITIONAL TASK ANSWERS (THEORY)
====================================================
1. TIME COMPLEXITY:
   - PUSH(x)   : O(1)
   - POP()     : O(1)
   - PEEK()    : O(1)
   - DISPLAY() : O(n) [where n is the current number of elements]

2. SPACE COMPLEXITY:
   - O(N) auxiliary space [where N is the fixed array capacity]

3. WHAT HAPPENS WHEN STACK SIZE IS FIXED AND USER INSERTS MORE ELEMENTS?
   - Attempting to insert elements beyond capacity causes a STACK OVERFLOW condition.
   - The program prevents invalid memory writes by checking (top == MAX - 1) 
     and rejects the new insertion with an overflow message.
====================================================
*/
