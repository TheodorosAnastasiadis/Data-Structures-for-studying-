#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int front;
    int rear;
    int capacity;
}Queue;

/*
Function to make the queue. What do we need to initialize?
1)Allocate memory to store the Queue
2)Initialize the capacity
3)Initialize the front and rear of the queue
4)Allocate memory for the array that is actually going to hold 
the data of the queue
5)Return queue;
*/
Queue* createQueue(int capacity){
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity=capacity;
    queue->front=-1;
    queue->rear=-1;
    queue->array=(int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(Queue*queue){
    return (queue->rear==queue->capacity -1);
    /*
        Function to check if the queue is Full
        If rear reaches the same number as the capacitty of the queue
        you cant enter more data to it.
    */
}

int isEmpty(Queue*queue){
    return(queue->front ==-1 || queue->front > queue->rear);
    /*
        Function to check if the queue is Empty.

        There are 2 possible senarios to know a queue is empty.

        1)Either the front still hasnt changed the value 
        it has been initialized with, that means front is still = -1

        OR

        2) Front is bigger than rear. 
        From theory front is in the begining of the queue and rear 
        is in the end of it.
        If front=rear then  that means that there is still 1 value inside the
        queue. If front surpasses rear then the queue is empty.
    */
}
void enqueue(Queue*queue,int item){
    if (isFull(queue)){
        printf("\nError: Queue is full\n");
        return;
    }
    if (queue->front==-1){
        queue->front=0;
    }
    queue->rear++;
    queue->array[queue->rear]=item;
    printf("\n %d enqueued to the queue \n", item);
} /*
    Function to add an item to the queue 
    and Function to remove and item from the queue.
    This SOS thats how enqueue and dequeue
    works every time you have to work with a queue it doesnt change
*/

int dequeue(Queue*queue){
    if(isEmpty(queue)){
        printf("\nError: Queue is Empty\n");
        return -1;
    }
    int item= queue->array[queue->front];
    //FIFO. First In First Out
    queue->front++;
    if(queue->front > queue->rear){
        queue->front=queue->rear=-1;
        //Reset queue when its empty
    }
    return item;
}
/*
    Funtion to Display queue.
    I made it so it also displays the front and the rear
    but it is a personal preference.
    In case you dont want to write this Function in that way here is an
    Alternative:

    void displayQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Current queue: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}
*/

void displayQueue(Queue*queue){
    if(isEmpty(queue)){
        printf("\n Queue is Empty \n");
        return;
    }
    printf("\nCurrent queue:\n");
    for (int i=queue->front; i<=queue->rear;i++){
        if (i==queue->front && i==queue->rear){
            printf("front->| %d |<-rear",queue->array[i]);
        }
        else if(i==queue->front){
            printf("front->| %d ",queue->array[i]);
        }
        else if (i==queue->rear){
            printf("| %d |<-rear",queue->array[i]);
        }
        else{
            printf("| %d ",queue->array[i]);
        }
    }
    printf("\n");
}

int main() {
    int N, choice, value;
    
    printf("Enter the size of the queue: ");
    scanf("%d", &N);
    
    Queue *queue = createQueue(N);
    
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
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
                free(queue->array);
                free(queue);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}