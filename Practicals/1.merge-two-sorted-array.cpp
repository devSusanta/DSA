//merge two sorted array in a new sorted array. 

#include <bits/stdc++.h>
using namespace std;

void sort_merge(int arr[], int arr1[], int arr2[],int l1, int l2){
    int l = l1+l2;
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < l){
        if(j >= l1 || k >= l2){
            if(j >= l1){
                while(k > l2){
                    arr[i] = arr2[k];
                    k++;
                    i++;
                }
            }else{
                while(j < l1){
                    arr[i] = arr1[j];
                    j++;
                    i++;
                }
            }
            return;
        }
        if(arr1[j] < arr2[k]){
            arr[i] = arr1[j];
            j++;
        }else{
            arr[i] = arr2[k];
            k++;
        }
        i++;
    }
}

int main(){
    int arr[10];
    int arr1[] = {1,3,5,9,10};
    int arr2[] = {2,3,4,6,8};
    int l1 = sizeof(arr1)/sizeof(arr1[0]);
    int l2 = sizeof(arr2)/sizeof(arr2[0]);
    sort_merge(arr,arr1,arr2,l1,l2);
    int i = 0;
    while(i < 10){
        cout << arr[i] << " ";
        i++;
    }
    return 0;
}