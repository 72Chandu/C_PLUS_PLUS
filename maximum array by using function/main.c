#include<stdio.h>
//pass by refrence
int returnMax(int array[],int n){// acepted as address of array
    int max=0;
    for(int i=0;i<=n;i++){
        if(array[i]>max){
            max=array[i];
        }
    }
    return max;
}
int main(){
    
    int array[]={2,34,6,7,45,25,98,23};
    int max=returnMax(array,8);
    printf("maximum array in this is%d",max);
    return 0;
}
