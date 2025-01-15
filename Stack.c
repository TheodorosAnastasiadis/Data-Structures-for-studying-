#include <stdio.h>
#include <stdlib.h>

typedef struct { //Structure that represents the stack
    int *array;
    int top;
    int capacity;
}Stack;

Stack* createStack(int capacity){
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity=capacity;
    stack->top=-1;
    stack->array = (int*)malloc(stack->capacity *sizeof(int));
    return stack;
} //Function to Create Stack

int isFull(Stack *stack){
    return stack->top == stack->capacity -1;
} // Function to check if Stack is full

int isEmpty(Stack *stack){
    return stack->top ==-1;
}// Function to check if Stack is Empty

void push(Stack *stack, int item){
    if (isFull(stack)){
        printf("Error: Stack Overflow\n");
        return;
    }
    stack->array[++stack->top]=item;
}// Function for Push. It pushes item in the stack

int pop(Stack *stack){
    if(isEmpty(stack)){
        printf("Stack is Underflow");
        return -1;
    }
    return stack->array[stack->top--];
} //Function for Pop. It removes item from the stack

void DisplayStack(Stack *stack){
    if(isEmpty(stack)){
        printf("Stack is empty\n");
        return;
    }
    printf("Current Stack:\n");
    for (int i=0;i<=stack->top; i++){
        printf("%d \n",stack->array[i]);
    }
    printf("\n");
}//Function to display Stack
//###############################################################

//Main
int main(){
    int N,choice,value;

    printf("Enter size for the stack");
    scanf("%d",&N);

    Stack *stack =createStack(N);

    //Asks the user for the size of the Stack and calls createStack()

    while(1){
        printf("\n1.push\n2.pop\n3.Display\nExit\n");
        //Prints menu of choices
        printf("Enter your choice:");
        scanf("%d",&choice);


        //Im going to use a Switch for each choice

        switch (choice) {

            case 1:
                printf ("Enter value to Push:");
                scanf("%d",&value);
                push(stack,value);
                break;
            case 2:
                value=pop(stack);
                if (value != -1){
                    printf("Popped value: %d\n",value);
                }
                break;
            case 3:
                DisplayStack(stack);
                break;
            case 4:
                free(stack->array);
                free(stack);
                exit(0);
            default:
                printf("Error: Expected Choices 1-4. Please try again");
        }
    }
    return 0;
}

