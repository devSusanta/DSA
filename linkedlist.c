#include "linkedlist.h"

int main(){
    lkdlist *st1 = NULL, *st2 = NULL;
    int n = 20;
    for(int i = 1; i < n; i+=2){
        push_top(&st1,i);
    }
    for(int i = 0; i < n; i+=2){
        push_top(&st2,i);
    }
    lkdlist *st3 = merge(NULL,st2);
    display(st1);
    display(st2);
    display(st3);
    if(isExist(st1,10)){
        printf("Element Found.");
    }else{
        printf("Element not Found.");
    }
    return 0;
}