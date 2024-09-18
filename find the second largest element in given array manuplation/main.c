#include<stdio.h>
#include<limits.h>
int largestElementIndex(int a[],int n){
    int max=INT_MIN;
    int maxIndex=-1;
    for(int i=0;i<n;i++){
        if(a[i]>max){
            max=a[i];
            maxIndex=i;
        }
    }
    return maxIndex;
    
}
int main(){
    int a[]={2,3,5,7,6,1};
    int indexOfLargest=largestElementIndex(a,6);
    printf("%d\n",a[indexOfLargest]);
    a[indexOfLargest]=-1;
    int indexOfSecondLargest=largestElementIndex(a,6);
    printf("%d",a[indexOfSecondLargest]);
}