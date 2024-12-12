/*
Circular Queue is similar to 
"Regular" Queue with some slight differences
that Im going to highlight
*/
// Im going to highlight with //!!
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array; 
    int front;
    int rear;
    int capacity;           
   int size;  //!!        Added size    
                            /*Difference between Size and Capacity:
                         Capacity:Max items the Queue can hold
                        Size:Current items in Queue */
} CircQ; 
//For simplicity im naming Circular Queue CircQ 

CircQ* createQueue(int capacity){
    CircQ *queue= (CircQ*)malloc(sizeof(CircQ));
    queue->capacity=capacity;
    queue->front=-1;
    queue->rear=-1;
    queue->size=0; //!! initialize size =0;
    queue->array = (int*)malloc(queue->capacity *sizeof(int));
    return queue;
}

int isFull(CircQ*queue){
    return (queue->size == queue->capacity); //!!
    //Difference with the other queue
    // return (queue->rear==queue->capacity -1);
}

int isEmpty(CircQ*queue){
    return(queue->size==0); //!!
    //Difference with the other queue
    //return(queue->front ==-1 || queue->front > queue->rear);
}

int enqueue(CircQ*queue, int item){//!! check Line 101
    if (isFull(queue)){
        printf("\nError: Queue is full\n");
        return -1;
    }
    if(isEmpty(queue)){
        queue->front=0;
    }
    queue->rear= (queue->rear +1) % queue->capacity;
    queue->array[queue->rear]=item;
    queue->size++;
    printf("\n %d Enqueued to queue \n ",item);
}

int dequeue(CircQ*queue){ //!! check line 101
    if (isEmpty(queue)){
        printf("Error: Queue is empty");
        return -1;
    }
    int item= queue->array[queue->front];
    if (queue->size==1){
        queue->front=-1;
        queue->rear=-1;
    }else{
        queue->front=(queue->front +1) % queue->capacity;
    }
    /*
        If there's only one item in the queue (queue->size == 1):
-        We're about to remove the last item,
            so we reset both `front` and `rear` to -1.
            This indicates that the queue will be empty
                after this dequeue operation.

                If there's more than one item in the queue:
-               We move the `front` index to the next item.
-               We use the modulo operation `(queue->front + 1) % queue->capacity`
                to wrap around to the beginning of the array if necessary.
    */
    return item;
}

void displayQueue(CircQ*queue){
    if(isEmpty(queue)){
        printf("\nQueue is Empty\n");
        return;
    }
    printf("\nCurrent queue:\n");
    int count =0;
    int i = queue->front;
    while (count < queue->size){
        printf("%d \n",queue->array[i]);
        i=(i+1) % queue->capacity;
        count++;
    }
    printf("\n");
}
/*
    The line `queue->rear = (queue->rear + 1) % queue->capacity;` 
    and similar lines using the modulo operation (%) are crucial for
     implementing the circular behavior of the queue. 
    Let me explain why this is necessary:
1. Circular nature:
    In a circular queue, we want to reuse 
    the space at the beginning of the array when we reach the end.
    This allows us to efficiently use the entire allocated space.
2. Wrapping around:
    The modulo operation `% queue->capacity`
    ensures that when we increment `rear` or `front`
    , it wraps around to the beginning of the array 
    if it exceeds the capacity.
*/
int main() {
    int N, choice, value;
    
    printf("Enter the size of the circular queue: ");
    scanf("%d", &N);
    
    CircQ *queue = createQueue(N);
    
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