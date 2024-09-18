#include<stdio.h>
int main(){
    int n,m;
    printf("enter the order of matrix");
    scanf("%d%d",&n,&m);
    int a[n][m];
    printf("enter the element in matrix");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    int p,q,r,s;
    int sum=0;
    printf("enter the cordinate for sum");//(p,q)to(r,s)
    scanf("%d%d%d%d",&p,&q,&r,&s);
    printf("sum of %d,%d to %d,%d\n",p,q,r,s);
    for(int i=p;i<=q;i++){
        for(int j=r;j<=s;j++){
            sum=sum+a[i][j];
        }
    }
    printf("sum=%d",sum);
    return 0;
}