//write a program to implement stack in c using array.

#include <stdio.h>
#include <stdlib.h>

void push(int x);
int pop();
void display();
int stack[10],top = -1;

int main(){
    int op,x;
    while(1){
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\nEnter Your choice: ");
        scanf("%d",&op);
        switch(op){
            case 1:
                if(top == 9){
                    printf("Overflow.\n");
                }else{
                    printf("Enter the item: ");
                    scanf("%d",&x);
                    push(x);
                }
                break;
            case 2:
                if(top == -1){
                    printf("Underflow.\n");
                }else{
                    x = pop();
                    printf("Removed %d from stack",x);
                }
                break;
            case 3:
                if(top == -1){
                    printf("Stack is empty.\n");
                }else{
                    printf("The elements of stack are: ");
                    display();
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Input.\n");
        }
    }
    return 0;
}

void push(int x){
    stack[++top] = x;
}

int pop(){
    return stack[top--];
}

void display(){
    for(int i = 0; i < top;i++){
        printf("%d -> ",stack[i]);
    }
    printf("%d\n",stack[top]);
}