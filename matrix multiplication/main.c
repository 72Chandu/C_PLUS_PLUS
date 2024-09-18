#include<stdio.h>
int main(){
    int n,m,p,q;//first matrix
    printf("enter row and colum of matrix a\n");
    scanf("%d%d",&n,&p);
    int a[n][p];
    printf("enter the element in matix a\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            printf("enter the element[%d][%d]",i,j);
            scanf("%d",&a[i][j]);
        }
    }//second matrix
    printf("enter row and colum of matrix b\n");
    scanf("%d %d",&q,&m);
    int b[q][m];
    printf("enter the element in matix b\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            printf("enter the element[%d][%d]",i,j);
            scanf("%d",&b[i][j]);
        }
    }
    int ans[n][m];
    int cr=n;//may be n or m
    //multiplying
    if(p!=q){
       printf("multiplication is not happened");
    }
    else{
        printf("resultant matrix \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
//ith row of a and jth colume of b (a[i][0],a[i][1],a[i][2].....)*(a[0][j],a[1][j],a[2][j]...)
        ans[i][j]=0;
        for(int k=0;k<n;k++){
            ans[i][j]+=a[i][k]*b[k][j];
        
        }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
   }
}