#include <stdio.h>
#include <stdlib.h>

typedef struct circular_doubly_linked_list{
    int data;
    struct circular_doubly_linked_list* next;
    struct circular_doubly_linked_list* prev;
}cdl_list;

int isEmpty(cdl_list *head){
    if(!head){
        return 1;
    }
    return 0;
}

int isExist(cdl_list *head, int key){
    if(!head){
        return 0;
    }
    cdl_list *temp = head;
    while(temp->next != head){
        if(temp->data == key){
            return 1;
        }
        temp = temp->next;
    }
    if(temp->data == key){
        return 1;
    }
    return 0;
}

int len(cdl_list *head){
    if(!head){
        return 0;
    }
    int count = 1;
    cdl_list *temp = head;
    while(temp->next != head){
        count++;
        temp = temp->next;
    }
    return count;
}

int count(cdl_list *head, int key){
    if(!head){
        return 0;
    }
    int count = 0;
    cdl_list *temp = head;
    while(temp->next != head){
        if(temp->data == key){
            count++;
        }
        temp = temp->next;
    }
    if(temp->data == key){
        return ++count;
    }
    return count;
}

void push(cdl_list **head, int new_data, int index){
    int l = len(*head);
    if(l < index || index < 0){
        printf("Index out of range.\n");
        return;
    }
    cdl_list *new_node = (cdl_list*)malloc(sizeof(cdl_list));
    new_node->data = new_data;
    if(l == index || index == 0){
        if(!*head){
            new_node->next = new_node;
            new_node->prev = new_node;
            *head = new_node;
            return;
        }
        new_node->next = *head;
        (*head)->prev->next = new_node;
        new_node->prev = (*head)->prev;
        (*head)->prev = new_node;
        if(index == 0){
            *head = new_node;
        }
        return;
    }
    int i = 0;
    cdl_list *temp = *head, *prev;
    while(i < index){
        prev = temp;
        temp = temp->next;
        i++;
    }
    prev->next = new_node;
    new_node->prev = prev;
    temp->prev = new_node;
    new_node->next = temp;
}

void push_top(cdl_list **head, int new_data){
    push(head, new_data, 0);
}

void push_bottom(cdl_list **head, int new_data){
    push(head, new_data, len(*head));
}

int pop_at(cdl_list **head, int index){
    int l = len(*head);
    if(l <= index || index < 0){
        printf("Index out of range.\n");
        return -1;
    }
    int data;
    cdl_list *temp, *prev;
    if(index == 0 || index == l-1){
        if((*head)->next == *head){
            data = (*head)->data;
            *head = NULL;
            return data;
        }
        if(index == 0){
            temp = *head;
            *head = (*head)->next;
        }else{
            temp = (*head)->prev;
        }
        prev = temp->prev;
        prev->next = (*head);
        (*head)->prev = prev;
        data = temp->data;
        free(temp);
        return data;
    }
    int i = 0;
    temp = (*head);
    while(i < index){
        prev = temp;
        temp = temp->next;
        i++;
    }
    prev->next = temp->next;
    temp->next->prev = prev;
    data = temp->data;
    free(temp);
    return data;
}

int pop_top(cdl_list **head){
    return pop_at(head, 0);
}
int pop_bottom(cdl_list **head){
    return pop_at(head, len(*head)-1);
}

// int pop_top(cdl_list **head){
//     if(!*head){
//         printf("List is Empty.(No Element Found)\n");
//         return -1;
//     }
//     int data;
//     if((*head)->next == *head){
//         data = (*head)->data;
//         *head = NULL;
//         return data;
//     }
//     cdl_list *temp = *head, *prev;
//     *head = (*head)->next;
    
//     prev = temp->prev;
//     prev->next = (*head);
//     (*head)->prev = prev;
//     data = temp->data;
//     free(temp);
//     return data;
// }

// int pop_bottom(cdl_list **head){
//     if(!*head){
//         printf("List is Empty.(No Element Found)\n");
//         return -1;
//     }
//     int data;
//     if((*head)->next == *head){
//         data = (*head)->data;
//         *head = NULL;
//         return data;
//     }

//     cdl_list *temp = (*head)->prev, *prev;
    
//     prev = temp->prev;
//     prev->next = (*head);
//     (*head)->prev = prev;
//     data = temp->data;
//     free(temp);
//     return data;
// }

// void push_top(cdl_list **head, int new_data){
//     cdl_list *new_node = (cdl_list*)malloc(sizeof(cdl_list));
//     new_node->data = new_data;
//     if(!*head){
//         new_node->next = new_node;
//         new_node->prev = new_node;
//         *head = new_node;
//         return;
//     }
//     new_node->next = *head;
//     (*head)->prev->next = new_node;
//     new_node->prev = (*head)->prev;
//     (*head)->prev = new_node;
//     *head = new_node;
// }

// void push_bottom(cdl_list **head, int new_data){
//     cdl_list *new_node = (cdl_list*)malloc(sizeof(cdl_list));
//     new_node->data = new_data;
//         if(!*head){
//         new_node->next = new_node;
//         new_node->prev = new_node;
//         *head = new_node;
//         return;
//     }
//     new_node->next = *head;
//     (*head)->prev->next = new_node;
//     new_node->prev = (*head)->prev;
//     (*head)->prev = new_node;
// }

void display(cdl_list *head){
    if(!head){
        printf("List is Empty.(No Element Found)\n");
        return;
    }
    cdl_list *temp = head;
    while(temp->next != head){
        printf("%d <-> ",temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
}

void displayr(cdl_list *head){
    if(!head){
        printf("List is Empty.(No Element Found)\n");
        return;
    }
    cdl_list *temp = head->prev;
    while(temp != head){
        printf("%d <-> ",temp->data);
        temp = temp->prev;
    }
    printf("%d\n",temp->data);
}