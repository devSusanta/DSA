//wirite a program to implement stack using linked list.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void push(struct node **head, int new_data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

int pop(struct node **head) {
    if ((*head)->next == NULL) {
        int value = (*head)->data;
        free(*head);
        *head = NULL;
        return value;
    }

    struct node *temp = *head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    int value = temp->next->data;
    free(temp->next);
    temp->next = NULL;

    return value;
}

void display(struct node *head) {
    struct node *temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main(){
    int op, data;
    struct node* head = NULL;
    while(1){
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter Your choice: ");
        scanf("%d",&op);
        switch(op){
            case 1:
                printf("Enter data of node: ");
                scanf("%d",&data);
                push(&head, data);
                break;
            case 2:
                if(head == NULL){
                    printf("Underflow.");
                }else{
                    printf("%d",head->data);
                    printf("Removed element is %d\n",pop(&head));
                }
                break;
            case 3:
                if(head == NULL){
                    printf("Stack is Empty.\n");
                }else{
                    printf("The elements of stack are: ");
                    display(head);
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

