#include<stdio.h>
#include<limits.h>
int largestelementindex(int a[],int n ){
    int max=INT_MIN;
    int maxindex;
    for(int i=0;i<=n;i++){
        if(a[i]>max){
            max=a[i];
        maxindex=i;
        }
    }
    return maxindex;
}
int main(){
    int a[]={4,6,24,7,8,9};
    int indexoflargestelement=largestelementindex(a,5);
    //index of largest element 
    printf("%d\n",indexoflargestelement);
    //largest element
    printf("%d\n",a[indexoflargestelement]);
    //for second largest element
    a[indexoflargestelement]=-1;
    int indexofsecondlargeste=largestelementindex(a,5);
    //index of second largest element 
    printf("%d\n",indexofsecondlargeste);
    //second largest element
    printf("%d",a[indexofsecondlargeste]);
}

