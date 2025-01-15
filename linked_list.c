//Υλοποιηση της Stack με συνδεδεμενη λιστα

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct{
    Node* top;
}Stack;

void initStack(Stack *stack){
    stack->top =NULL;
}

int isEmpty(Stack *stack){
    return stack->top == NULL;
}

void push(Stack *stack, int value){
    Node *newNode=(Node*)malloc(sizeof(Node));
    if (newNode == NULL){
        printf("Memory Error: Failed to insert item\n");
        return;
    }
    newNode->data = value;
    newNode->next= stack->top;
    stack->top=newNode; //Update Stack's top
}

int pop(Stack *stack){
    if(isEmpty(stack)){
        printf("Stack is Empty\n");
        return -1;
    }else{
        Node *temp =stack->top; //Saving the node that is going to get removed
        int value = temp->data; //Saving the value of the node
        stack->top= stack->top->next; //Updating the Stack's form
        free(temp); //Freeing the memory that was holding the node removed
        return value;
    }
}

void printStack(Stack *stack){
    if (isEmpty(stack)){
        printf("Stack is empty\n");
        return;
    }
    Node *current = stack->top;
    while(current != NULL){
        printf(" %d ",current->data);
        current = current->next;
    }
    printf("\n");
}
int main(){
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printStack(&stack);

    printf("Αφαίρεση στοιχείου: %d\n", pop(&stack));
    printf("Αφαίρεση στοιχείου: %d\n", pop(&stack));

    push(&stack, 40);
    push(&stack, 50);

    printStack(&stack);

    while (!isEmpty(&stack)) {
        printf("Αφαίρεση στοιχείου: %d\n", pop(&stack));
    }

    printStack(&stack);
    return 0;
}