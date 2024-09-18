#include<stdio.h>
int main(){
    int a[10]={1,2,3,4,5,6,7,8,9};
    int n=10;
    int i=0;
    int j=n-1;
    int target=8;
    while(i<j){
        if(a[i]+a[j]==target){
            printf("found");
            break;
        }
        else if(a[i]+a[j]>target){
            j--;
        }
        else{
            i++;
        }
        
    }
}