#include<stdio.h>
#include<limits.h>
//second method for finding thr second largest element in array
//wheather the array is increasing ,decresing,or mixed 
int main(){
   int b[7]={1,2,3,54,5,6,7};
   int max=INT_MIN;
   int smax=INT_MIN;
    for(int i=0;i<7;i++){
       if(max<b[i]){
        smax=max;//smax is now privious max
        max=b[i];//max is now a new max
       }
       else if(smax<b[i] && max!=b[i]){
        smax=b[i];
       }
    }
    printf("%d",smax);
    return 0;
}