
#include "linkedlist.h"

int main(){
    lkdlist *st1 = NULL;
    push_top(&st1,10);
    push(&st1,11,0);
    push(&st1,14,2);
    push(&st1,12,2);
    display(st1);
    push_bottom(&st1,100);
    display(st1);
    int index = 4;
    printf("the element at index %d is %d",index,item_at(st1,index));
    return 0;
}