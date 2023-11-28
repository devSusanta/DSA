#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insert(struct node **head, int new_data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

void delete(struct node **head, int key) {
    struct node *temp = *head, *prev;

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
    free(temp);
}

void display(struct node *head) {
    struct node *temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct node *list1 = NULL;
    struct node *list2 = NULL;

    insert(&list1, 3);
    insert(&list1, 1);
    insert(&list1, 7);
    insert(&list1, 2);

    printf("Linked list 1: ");
    display(list1);

    delete(&list1, 1);

    printf("\nLinked list 1 after deletion: ");
    display(list1);

    insert(&list2, 5);
    insert(&list2, 9);
    insert(&list2, 4);

    printf("\nLinked list 2: ");
    display(list2);

    delete(&list2, 9);

    printf("\nLinked list 2 after deletion: ");
    display(list2);

    return 0;
}

/*OUTPUT

PS S:\WorkSpace\CollegeWork\DataStructure> gcc .\singly-linked-list-2.c
PS S:\WorkSpace\CollegeWork\DataStructure> ./a
Linked list 1: 2 7 1 3 
Linked list 1 after deletion: 2 7 3 
Linked list 2: 4 9 5 
Linked list 2 after deletion: 4 5 
PS S:\WorkSpace\CollegeWork\DataStructure>
*/