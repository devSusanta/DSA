#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int new_data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
}

void delete(int key) {
    struct node *temp = head, *prev;

    if (temp != NULL && temp->data == key) {
        head = temp->next;
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
    free(temp);
}

void display() {
    struct node *temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    insert(3);
    insert(1);
    insert(7);
    insert(2);

    printf("Linked list: ");
    display();

    delete(1);

    printf("\nLinked list after deletion: ");
    display();

    return 0;
}
