#include <stdio.h>
#include <stdlib.h>
#define insert(x,y) push(x,y)
#define delete(x) pop_top(x)

typedef struct linkedlist {
    int data;
    struct linkedlist *next;
}lkdlist;

int isEmpty(lkdlist *head){
    if(!head){
        return 1;
    }
    return 0;
}

int len(lkdlist *head){
    lkdlist *temp = head;
    int count = 0;
    while(temp){
        temp = temp->next;
        count++;
    }
    return count;
}

int count(lkdlist *head){
    
}

int item_at(lkdlist *head,int index){
    if(index >= len(head)){
        printf("index out of range.\n");
        return -1;
    }
    int count = 1;
    lkdlist *temp = head;
    while(count <= index){
        temp = temp->next;
        count++;
    }
    return temp->data;
}

int top(lkdlist *head){
    item_at(head,0);
}

int bottom(lkdlist *head){
    item_at(head,len(head)-1);
}

void push(lkdlist **head, int new_data, int index){
    if(len(*head) < index || index < 0){
        printf("Index Out of Range %d\n",len(*head));
        return;
    }

    lkdlist *new_node = (lkdlist*)malloc(sizeof(lkdlist));
    new_node->data = new_data;

    if(index == 0){
        new_node->next = *head;
        *head = new_node;
        return;
    }
    int i = 0;
    lkdlist *temp = *head, *prev;
    do{
        prev = temp;
        temp = temp->next;
        i++;
    }while(i < index);
    prev->next = new_node;
    new_node->next = temp;
}
void push_top(lkdlist **head, int new_data) {
    push(head,new_data,0);
}

void push_bottom(lkdlist **head, int new_data){
    int l = len(*head);
    push(head,new_data,l);
}

void pop_at(lkdlist **head, int index){

}

void pop(lkdlist **head, int key) {
    lkdlist *temp = *head, *prev;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Key not found\n");
        return;
    }

    prev->next = temp->next;
    printf("Removed %d\n",temp->data);
    free(temp);
}

int pop_top(lkdlist **head) {
    if(isEmpty(*head)){
        return -1;
    }
    lkdlist *temp = *head;
    int data = (*head)->data;
    *head = temp->next;
    free(temp);
    return data;
}

int pop_bottom(lkdlist **head){
    if(isEmpty(*head)){
        return -1;
    }

    if (!(*head)->next) {
        int data = (*head)->data;
        *head = NULL;
        return data;
    }

    lkdlist *current = *head;
    while (current->next->next) {
        current = current->next;
    }

    int data = current->next->data;
    free(current->next);
    current->next = NULL;
    return data;
}

void display(lkdlist *head) {
    lkdlist *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}



