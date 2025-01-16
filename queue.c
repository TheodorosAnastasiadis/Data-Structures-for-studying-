#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct{
    int array[SIZE];
    int front;
    int rear;
}Queue;

Queue initqueue(Queue *queue){
    queue->front=-1;
    queue->rear=-1;
}

int isFull(Queue *queue){
    return queue->rear== SIZE -1;
}

int isEmpty(Queue *queue){
    return queue->front== -1 || queue->front > queue->rear;
}

int Enqueue(Queue *queue,int value){
    if(isFull(queue)){
        printf("Queue is Full\n");
    }else{
        if(queue->front=-1){
            queue->front=0;
        }
        queue->rear++;
        queue->array[queue->rear]=value;
    }
}

int Dequeue(Queue *queue){
    if (isEmpty(queue)){
        printf("Queue is empty\n");
    }else{
        queue->front++;
        if(queue->front > queue->rear){
            queue->front=queue->rear=-1;
        }
    }
}

void printQueue(Queue *queue){
    if(isEmpty(queue)){
        printf("Queue is Empty\n");
    }else{
        for(int i=queue->front;i<queue->rear;i++){
            printf(" %d ", queue->array[i]);
        }
        printf("\n");
    }
}

int main(){
    Queue queue;
    initqueue(&queue);
    int choice;

    do{
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");

        printf("Enter choice:");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            int value;
            printf("Enter value:");
            scanf("%d",&value);
            Enqueue(&queue,value);
            break;
        case 2:
            printf("Removing %d",queue.array[queue.front]);
            Dequeue(&queue);
            break;
        case 3:
            printQueue(&queue);
            break;
        case 4:
            exit(1);
        default:
            printf("Error");
            break;
        }
    }while (choice!=4);

}