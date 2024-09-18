#include<stdio.h>
int main(){
    int a[5]={1,2,3,1,4};
    int check=0;
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
           if(a[i]==a[j]){
               printf(" dublicate found");
               check=1;
               break;
           }
        }
    }
    if(check==0){
        printf("not found");
    }
    else(" dublicate found");
}