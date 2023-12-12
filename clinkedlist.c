#include "clinkedlist.h"

void main(){
    cl_list *ll1 = NULL, *ll2 = NULL;
    int n = 20;
    for(int i = 0; i < n; i+=2){
        push_top(&ll1,i);
    }
    ll2 = copy_list(ll1);
    cl_list *ll3 = ll1;
    replace(ll1,10,100);
    display(ll1);
    display(ll2);
    display(ll3);
}