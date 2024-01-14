//write a program to implement circular queue using array.

#include <stdio.h>
#define max 10
int queue[max], rear = -1, front = -1;

int isEmpty(){
    return (rear == -1);
}
int isFull(){
    return (rear+1)%max == front;
}
int len(){
    int l = rear - front + 1; 
    if(rear < front){
        max + l;
    }
    return l; 
}

void enqueue(int data){
    rear %= max;
    front %= max;
    queue[++rear] = data;
    if(front == -1)
        front++;
}

int dequeue(){
    int data = queue[front++];
    if(rear == front-1)
        rear = front = -1;
    return data;
}

void displsay(){
    if(rear == -1){
        printf("Empty Queue.\n");
        return;
    }
    int i = front;
    while(i <= rear){
        printf("%d",queue[i]);
        i++;
        if(i > rear){
            break;
        }
        printf(" -> ");
    }
    printf("\n");
}

void display(){
    if(isEmpty()){
        printf("Empty Queue.\n");
        return;
    }
    int i;
    if(front <= rear){
        for(i = front; i <= rear; i++){
            printf("%d -> ",queue[i]);
        }
    }else{
        for(i = front; i < max; i++){
            printf("%d -> ",queue[i]);
        }
        for(i = 0; i <= rear; i++){
            printf("%d -> ",queue[i]);
        }
    }
    printf("NULL\n");
}

void main(){
    int op;
    int data;
    while(1){
        printf("1. Push, 2. Pop, 3. Display, 4. isEmpty, 5. Length, 6. Exit\nEnter your choice: ");
        scanf("%d",&op);
        switch(op){
            case 1:
                if(isFull()){
                    printf("Overflow.\n");
                }else{
                    printf("Enter the Data: ");
                    scanf("%d",&data);
                    enqueue(data);
                }
                break;
            case 2:
                if(isEmpty())
                    printf("The Queue is Empty.\n");
                else
                    printf("Removed %d.\n",dequeue());
                break;
            case 3:
                display();
                break;
            case 4:
                if(isEmpty())
                    printf("The Queue is Empty.\n");
                else
                    printf("The Queue is not Empty.\n");
                break;
            case 5:
                printf("The Len of the Queue is %d\n",len());
                break;
            case 6:
                printf("Oops.. Program Terminated.");
                return;
            default:
                printf("Invalid Input.\n");
        }
    }
}