#include<stdio.h>
int main(){
    int a[]={3,1,2,4,0,6};
    int targetsum=6;
    int triplets=0;
    for(int i=0;i<6;i++){
        for(int j=i+1;j<6;j++){
            for(int k=j+1;k<6;k++){
                if(a[i]+a[j]+a[k]==targetsum){
                   triplets++; 
                }
            }
        }
    }
    printf("%d",triplets);
    return 0;
}