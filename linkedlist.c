#include "linkedlist.h"

int main(){
    lkdlist *st1 = NULL;
    int n = 20;
    for(int i = 0; i < n; i++){
        push_top(&st1,i);
    }
    display(st1);
    lkdlist *st2 = st1;
    st1 = NULL;
    display(st1);
    display(st2);
    if(isExist(st1,10)){
        printf("Element Found.");
    }else{
        printf("Element not Found.");
    }
    return 0;
}