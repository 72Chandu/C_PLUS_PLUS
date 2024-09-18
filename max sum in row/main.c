#include<stdio.h>
#include<limits.h>
int main(){
    int n,m;
    printf("enter the order");
    scanf("%d%d",&n,&m);
    printf("enter the element in matrix");
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf(" %d\n",a[i][j]);
        }
        printf("\n");
    }
    int maxsum=INT_MIN;
    int idx1=-1;
     for(int i=0;i<n;i++){
        int Sum=0; 
        for(int j=0;j<m;j++){
           Sum=Sum+a[i][j];
        }
        if(Sum>maxsum){
            maxsum=Sum;
            idx1=i;
           }
    }
   printf("sum=%d row=%d",maxsum,idx1);

}