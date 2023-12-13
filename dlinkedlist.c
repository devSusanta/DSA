#include "dlinkedlist.h"

void main(){
    dl_list *ll1 = NULL, *ll2 = NULL;
    for(int i = 19; i > 0; i--){
        push_bottom(&ll1,i);
    }
    push_bottom(&ll1, 10);
    push(&ll1, 10,10);
    push_top(&ll1, 10);
    printf("The no of 13 in this doubly linked list is %d\n",count(ll1,13));
    printf("The bottom of this doubly linked list is %d\n",bottom(ll1));
    printf("The top of this doubly linked list is %d\n",top(ll1));
    printf("the 5 exist in this doubly linked list is %d\n",isExist(ll1,19));
    printf("the len of this doubly linked list is %d\n",len(ll1));
    display(ll1);
    replace_at(ll1, 10, 0);
    display(ll1);
}

