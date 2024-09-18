#include<stdio.h>
int main(){
    int i,n;
    int sum=0;
    float av;
int a[10];
printf("enter element of  array");
for(i=0;i<10;i++){
    scanf("%d",&a[i]);
}
for(i=0;i<10;i++){
    sum=sum+a[i];
}
printf("sun=%d",sum);
for(i=0;i<10;i++){
    av=sum/10;
}
printf("av=%f",av);
return 0;
}