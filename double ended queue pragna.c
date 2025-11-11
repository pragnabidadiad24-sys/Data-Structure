#include <stdio.h>
#define MAX 10

int deque[MAX];
int left = -1, right = -1;

// Insert at right end
void insert_right() {
    int val;
    if ((left == 0 && right == MAX - 1) || (left == right + 1)) {
        printf("\nDeque is full.\n");
        return;
    }
    printf("Enter value to insert at right: ");
    scanf("%d", &val);
    if (left == -1) {
        left = right = 0;
    } else if (right == MAX - 1) {
        right = 0;
    } else {
        right++;
    }
    deque[right] = val;
}

// Insert at left end
void insert_left() {
    int val;
    if ((left == 0 && right == MAX - 1) || (left == right + 1)) {
        printf("\nDeque is full.\n");
        return;
    }
    printf("Enter value to insert at left: ");
    scanf("%d", &val);
    if (left == -1) {
        left = right = 0;
    } else if (left == 0) {
        left = MAX - 1;
    } else {
        left--;
    }
    deque[left] = val;
}

// Delete from left end
void delete_left() {
    if (left == -1) {
        printf("\nDeque is empty.\n");
        return;
    }
    printf("Deleted from left: %d\n", deque[left]);
    if (left == right) {
        left = right = -1;
    } else if (left == MAX - 1) {
        left = 0;
    } else {
        left++;
    }
}

// Delete from right end
void delete_right() {
    if (right == -1) {
        printf("\nDeque is empty.\n");
        return;
    }
    printf("Deleted from right: %d\n", deque[right]);
    if (left == right) {
        left = right = -1;
    } else if (right == 0) {
        right = MAX - 1;
    } else {
        right--;
    }
}

// Display the deque
void display() {
    int i;
    if (left == -1) {
        printf("\nDeque is empty.\n");
        return;
    }
    printf("\nDeque elements: ");
    i = left;
    while (1) {
        printf("%d ", deque[i]);
        if (i == right)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Main function
int main() {
    int choice;
    do {
        printf("\n--- Double Ended Queue Menu ---\n");
        printf("1. Insert at right\n");
        printf("2. Insert at left\n");
        printf("3. Delete from left\n");
        printf("4. Delete from right\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insert_right(); break;
            case 2: insert_left(); break;
            case 3: delete_left(); break;
            case 4: delete_right(); break;
            case 5: display(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 6);
}


