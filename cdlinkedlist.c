#include "cdlinkedlist.h"

void main(){
    cdl_list *ll1 = NULL;
    sort_push(&ll1, 8);
    push_top(&ll1,10);
    push_top(&ll1,12);
    push_top(&ll1,13);
    push_bottom(&ll1,100);
    push_bottom(&ll1,100);
    push_bottom(&ll1,100);
    push(&ll1,300,len(ll1));
    push_top(&ll1,15);
    push(&ll1,123,8);
    printf("The len of this list is %d\n",len(ll1));
    display(ll1);
    display(ll1);
    display(ll1);
    display(ll1);
    printf("%d\n",count(ll1, 10));
    printf("index %d is %d\n",0,item_at(ll1,6));
    printf("The top and bottom of this list is %d, %d\n",top(ll1),bottom(ll1));
    sort_list(&ll1);
    display(ll1);
    cdl_list *ll2 = sort_merge(ll1,ll1);
    display(ll2);
    replaceAll(ll2,100,12);
    display(ll2);
}