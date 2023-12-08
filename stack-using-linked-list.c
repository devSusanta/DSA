//write a program to implement stack using a linked list.

#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int data;
    struct stack* next;
}stack;

stack *head = NULL;

void push(int x){
    stack *new_stack = (stack*)malloc(sizeof(stack));
    new_stack->data = x;
    new_stack->next = head;
    head = new_stack;
}


int pop(){
    stack *temp = head;
    head = head->next;
    int data = temp->data;
    free(temp);
    return data;
}

void display(){
    stack *temp = head;
    while(temp){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int isEmpty(){
    if(!head){
        return 1;
    }
    return 0;
}

int len(){
    int count = 0;
    stack *temp = head;
    while(temp){
        count++;
        temp = temp->next;
    }
    return count;
}

int bottom(){
    stack *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    return temp->data;
}

int top(){
    return head->data;
}



void main(){
    int op,x;
    while(1){
        printf("1.Push, 2.Pop, 3.Display, 4. Length, 5. isEmpty, 6. isFull, 7. Top, 8, bottom, 9.Exit.\nEnter Your choice: ");
        scanf("%d",&op);
        switch(op){
            case 1:
                printf("Enter the item: ");
                scanf("%d",&x);
                push(x);
                break;
            case 2:
                if(isEmpty()){
                    printf("Underflow.\n");
                }else{
                    printf("Removed %d from stack\n",pop());
                }
                break;
            case 3:
                if(isEmpty()){
                    printf("Stack is empty.\n");
                }else{
                    printf("The elements of stack are: ");
                    display();
                }
                break;
            case 4:
                printf("%d\n",len());
                break;
            case 5:
                if(isEmpty()){
                    printf("Stack is Empty\n");
                }else{
                    printf("Stack is Not Empty\n");
                }
                break;
            case 6:
                printf("Don't worry stack is never going to be full, you have enough space remain.\n");
                break;
            case 7:
                if(isEmpty()){
                    printf("Stack is Empty\n");
                }else{
                    printf("%d\n",top());
                }
                break;
            case 8:
                if(isEmpty()){
                    printf("Stack is Empty\n");
                }else{
                    printf("%d\n",bottom());
                }
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid Input.\n");
        }
    }
}