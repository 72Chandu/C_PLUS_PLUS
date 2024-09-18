#include<stdio.h>
#include<limits.h>
int main(){
    int n,m;
    printf("enter the order");
    scanf("%d%d",&n,&m);
    printf("enter the element in matrix onely 0 and 1");
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf(" %d",a[i][j]);
        }
        printf("\n");
    }
    //finding the no of 1 in row
    int maxcount=0;
    int idx=-1;
    for(int i=0;i<n;i++){
        int count1=0;
        for(int j=0;j<m;j++){
            count1++;
        }
    
    //storing the count1 to maxcount
       if(maxcount<count1){
        maxcount=count1;
        idx=i;//row that contain max 1
        }
    }
    printf("%d %d",maxcount,idx);
}