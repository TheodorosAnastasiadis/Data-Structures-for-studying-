#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct {
    int array[SIZE];
    int top;
}Stack;

Stack initializeStack(Stack *stack){
    stack->top=-1;
}

int isEmpty(Stack *stack){
    return stack->top==-1;
}

int isFull (Stack *stack){
    return stack->top==SIZE -1;
}

int push(Stack *stack, int value){
    if(isFull(stack)){
        printf("Stack is Full\n");
    }else{
        stack->array[++stack->top] = value;
    }
}

int pop(Stack *stack){
    if(isEmpty(stack)){
        printf("Stack is empty\n");
    } else {
        int value = stack->array[stack->top--];
    }
}

void printStack(Stack *stack){
  if(isEmpty(stack)){
    printf("Stack is empty\n");
  } else{
    for (int i=0; i<stack->top; i++){
        printf(" %d ", stack->array[i]);
    }
  }
}

int main(){
    Stack stack;
    initializeStack(&stack);
    int choice;
    do{
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.Display\n");
        printf("4.Exit\n");

        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            int value;
            printf("insert value:");
            scanf("%d",&value);
            push(&stack,value);
            break;
        case 2:
            printf("Removing %d \n",stack.array[stack.top]);
            pop(&stack);
            break;
        case 3:
            printStack(&stack);
            break;
        case 4:
            printf("program terminated \n");
            exit(1);
        default:
            printf("Wrong choice\n");
            break;
        }
    }while (choice!=4);
    return 0;
}