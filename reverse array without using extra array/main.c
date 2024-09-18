#include<stdio.h>
void reverse(int b[]){
    int i=0;// if want to reverse some particular part of array than
    int j=6;//we should intisalize i and j from that part(i=2,j=5) 
    while(i<j){// for for loop(i=0,i=6;i<j;i++,j--)
    int temp=b[i];
    b[i]=b[j];
    b[j]=temp;
    i++;
    j--;
    }
}
int main(){
    int a[7]={1,2,3,4,5,6,7};
    reverse(a);
    for(int i=0;i<7;i++){
        printf("%d ",a[i]);
    }
}