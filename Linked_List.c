#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
    int size;
} Node;

// Structure for the queue
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Function to create an empty queue
Queue* initializeQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

// Function to add an item to the queue (enqueue)
void enqueue(Queue* queue, int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    newNode->data = item;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("%d enqueued to queue\n", item);
}

// Function to remove an item from the queue (dequeue)
int dequeue(Queue* queue, int* item) {
    if (isEmpty(queue)) {
        printf("Error: Queue is empty\n");
        return 0; // Indicates failure
    }
    Node* temp = queue->front;
    *item = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return 1; // Indicates success
}

// Function to display the queue
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    Node* current = queue->front;
    printf("Current queue: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory used by the queue
void freeQueue(Queue* queue) {
    if (queue == NULL) {
        return;
    }
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);
}

int main() {
    Queue* queue = createQueue();
    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input\n");
            while (getchar() != '\n');
            continue;
        }


        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input\n");
                    while (getchar() != '\n');
                    continue;
                }
                enqueue(queue, value);
                break;
            case 2:
                value = dequeue(queue);
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
                }
                break;
            case 3:
                displayQueue(queue);
                break;
            case 4:
                freeQueue(queue);
                printf("Queue freed\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
