#include <stdio.h>
#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;

// Check if the queue is full
int isFull() {
    return ((front == rear + 1) || (front == 0 && rear == SIZE - 1));
}

// Check if the queue is empty
int isEmpty() {
    return (front == -1);
}

// Add an element to the queue
void enQueue(int element) {
    if (isFull()) {
        printf("\nQueue is full!\n");
    } else {
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        printf("\nInserted -> %d\n", element);
    }
}

// Remove an element from the queue
int deQueue() {
    int element;
    if (isEmpty()) {
        printf("\nQueue is Empty!!\n");
        return -1;
    } else {
        element = items[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        printf("\nDeleted element -> %d\n", element);
        return element;
    }
}

// Display the queue
void display() {
    int i;
    if (isEmpty()) {
        printf("\nEmpty Queue\n");
    } else {
        printf("\nFront -> %d", front);
        printf("\nItems -> ");
        for (i = front; i != rear; i = (i + 1) % SIZE)
            printf("%d ", items[i]);
        printf("%d ", items[i]); // Print the last item
        printf("\nRear -> %d\n", rear);
    }
}

// Main function with user-defined interaction
int main() {
    int choice, value;

    while (1) {
        printf("\n\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enQueue(value);
                break;
            case 2:
                deQueue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
