#include<stdio.h>
int main(){
  int n;
  int a[n];
  printf("enter n");
  scanf("%d",&n);
  printf("enter the element in array");
  for(int i=0;i<=n;i++){
      scanf("%d",&a[i]);
  }
  //reversing of array
  for(int j=n;j>=0;j--){
      printf("%d ",a[j]);
  }
    
}