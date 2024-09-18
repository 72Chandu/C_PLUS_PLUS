#include<stdio.h>
int main(){
    int n,m;
    printf("enter the order");
    scanf("%d%d",&m,&n);
    printf("enter the element in matrix");
    int a[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]); 
        }
    }    
    //spiral :-colume wise  i=row j=col r=row  c=col
        int minr=0;
        int maxr=m-1;
        int minc=0;
        int maxc=n-1;
        int tne=m*n;
        int count=0;
        while(count<tne){
            for(int j=minc;j<=maxc;j++){ //print the minimum row
                printf("%d",a[minr][j]);
                count++;
            }
            minr++;
            if(count>=tne) break;                              //inpute   output      
            //print the maximum colum                          //123      123698745
            for(int i=minr;i<=maxr;i++){                      //456  => 
                printf("%d",a[i][maxc]);                      //789 
                count++;
            }
            maxc--;
            if(count>=tne) break;
            for(int j=maxc;j>=minc;j--){  //print maximum row
                printf("%d",a[maxr][j]);
                count++;
            }
            maxr--;
            if(count>=tne) break;
            for(int i=maxr;i>=minr;i--){ //print minimu colum
                printf("%d",a[i][minc]);
                count++;   
            }
            minc++;
            if(count>=tne) break;
        }
        return 0;
}    

//spiral print a matrix ->leetcode
1 2 3
4 5 6
7 8 9
o/p=1 2 3 6 9 8 7 4 5
printing
1 starting row  
2 endining col   
3 endining row  
4 starting col 
1 2 3 3 6 9 
9 8 7 7 4 1 => 1 2 3 6 9 8 7 4 removing duplicate element
vector<int>spiralMatrix(vector<vector<int>>a){
    vector<int>ans;
    int r=a.size();
    int n=a[0].size();
    int totle_ele=n*n;
    int starting_row=0;
    

}
