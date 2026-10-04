#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

// 1. ENQUEUE Operation
void enqueue(int x) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue Full! Cannot enqueue %d\n", x);
        return;
    }
    if (front == -1) { // First element insertion
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    queue[rear] = x;
    printf("Enqueued: %d\n", x);
}

// 2. DEQUEUE Operation
void dequeue() {
    if (front == -1) {
        printf("Queue Underflow! Queue is empty\n");
        return;
    }
    printf("Dequeued: %d\n", queue[front]);
    if (front == rear) { // Last element removed
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

// 3. FRONT Operation
void getFront() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element: %d\n", queue[front]);
}

// 4. DISPLAY Operation
void displayQueue() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    printf("--- CIRCULAR QUEUE DEMO ---\n");
    dequeue();      // Underflow check
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);    // Overflow check
    
    displayQueue();
    dequeue();
    enqueue(60);    // Demonstrates circular memory reuse
    displayQueue();

    return 0;
}

/* 
====================================================
ADDITIONAL TASK ANSWERS (THEORY)
====================================================
1. WHY CIRCULAR QUEUE PROVIDES BETTER MEMORY UTILIZATION:
   - In a linear queue, freed positions at the front cannot be reused once REAR 
     reaches the end.
   - A circular queue wraps around using modulo arithmetic ((rear + 1) % SIZE), 
     allowing vacant slots created by DEQUEUE operations to be reused.

2. TIME COMPLEXITY:
   - ENQUEUE : O(1)
   - DEQUEUE : O(1)

3. SPACE COMPLEXITY:
   - O(N) total array space.

4. PROBLEM IN LINEAR QUEUE WHEN REAR REACHES LAST INDEX:
   - When REAR = SIZE - 1 in a linear queue, the queue appears FULL even if 
     positions at the beginning are empty due to DEQUEUE operations.
   - This leads to unused, wasted memory unless all elements are manually shifted.
====================================================
*/
