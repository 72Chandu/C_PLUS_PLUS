#include<stdio.h>
void reverse(int arr[],int si,int li){
    for(int i=si,j=li;i<j;i++,j--){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    return;
}
int main(){
    int a[7]={1,2,3,4,5,6,7};
    int n=7;
    int k=3;//rotated 3 times
    k=k%n;//n>k if not than do k=k%n
    reverse(a,0,n-1);//1.reverse whole array(0 to n-1)
    reverse(a,0,k-1);//2.reverse from strting to til k index(0 to k-1)
    reverse(a,k,n-1);//3.reverse remaing(n-k) last element(k to n-1)
    for(int i=0;i<n;i++){
        printf("%d",a[i]);
    }
    return 0;
}

