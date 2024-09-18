#include<stdio.h>
    // int returnMax(int array[],int n){
    //     int max=0;
    //     for(int i=0;i<=n;i++){
    //         if(array[i]>max){
    //             max=array[i];
    //         }
    //     }
    //     return max;
    // }
    int main(){
    int array[]={23,43,54,76,89,709};
    int max=0;
    for(int i=0;i<=6;i++){
        if(array[i]>max){
            max=array[i];
        }
    }
    //int max=returnMax(array,6);
    printf("maximum array %d",max);
    return 0;
    
}