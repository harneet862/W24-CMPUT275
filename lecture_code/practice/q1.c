#include <stdio.h>

int argmax(int arr[]){
    int len = sizeof(arr)/sizeof(arr[0]);
    int *first = arr;
    int *max;
    for (int i=0; i<len; i++){
        if (arr[i] > max){
            *max = &arr[i];
        }
    return ((*max - *first)/sizeof(arr[0]));
    }
}

int main(){
    printf(argmax[9,8,21,67,4]);
}