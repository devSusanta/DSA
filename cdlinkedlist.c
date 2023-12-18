#include "cdlinkedlist.h"

void main(){
    cdl_list *ll1 = NULL;
    push_top(&ll1,10);
    push_top(&ll1,12);
    push_top(&ll1,13);
    push_bottom(&ll1,100);
    push_bottom(&ll1,100);
    push_bottom(&ll1,100);
    push(&ll1,100,0);
    push(&ll1,300,len(ll1));
    push_top(&ll1,15);
    push(&ll1,123,8);
    printf("The len of this list is %d\n",len(ll1));
    display(ll1);
    pop_top(&ll1);
    display(ll1);
    pop_bottom(&ll1);
    display(ll1);
    pop_at(&ll1,2);
    display(ll1);
    for(int i = 0; i < 301; i++){
        if(isExist(ll1, i)){
            printf("%d is Exist in this List.\n",i);
        }
    }
    printf("%d\n",count(ll1, 10));
    display(ll1);
}