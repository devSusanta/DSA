#include "linkedlist.h"

int main(){
    lkdlist *st1 = NULL;
    int n = 100;
    for(int i = 0; i < n; i++){
        push_top(&st1,i);
    }
    reverse_list(&st1);
    display(st1);
    if(isExist(st1,10)){
        printf("Element Found.");
    }else{
        printf("Element not Found.");
    }
    return 0;
}