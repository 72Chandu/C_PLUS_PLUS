/*indentification of dp-> 
1>choice yes/no
2>recursive me 2 function call 
3>minimum/maximum(optimal)
how to write dp-
1> write recurrsive fnction-> memoize karo> top-down me change kar do-> draw matrix

subset sum
equal sum partition 
count of subset sum
minimum subset sum
target sum
of subset & gain 
Q)                             knapsack -> bag 
item1 item2 item3 item4
i/p: weight_arr[]:-> contain the weight of each item
value_arr[];-> contain the value of each item
W:-> capacity of bag
o/p:-> choose the item and keep them in bag so that profit is maximum and sum of weight of item <=W
item move to bag totaly or not
wr[]:1 3 4 5-> point by i
vr[]:1 4 5 7
W=7
wr[i]<=W -> yes/no   wr[i]>=W -> no
*/

recurrsive function->
int knapsack(int wr[], int val[], int W, int n){
    if(n==0||W==0) return 0; //0 profit
    if(wr[n-1]<=W){//weight of (n-1)th item is less the the weight of bag
        return max(val[n-1]+knapsack(wr,val,W-wr[n-1],n-1), knapsack(wr,val, W, n-1));
        //val[n-1]+knapsack(wr,val,W-wr[n-1],n-1)->including the (n-1)th item to bag(yes) 
        //knapsack(wr,val, W, n-1)-> not including the (n-1)th item to bag (no)
    }
    else if(wr[n-1]>W) return knapsack(wr,val, W, n-1);
}

memoization->
make a matrix of (pxq) what will be the value of p and q in the above varaiable onley wr,val is not changining , W, n is changining make a dp matrix with changing variable
so, dp[n+1][W+1]-> intialise with -1 (if -1 present then call recurrsive function if not then do not call(means value is allready calculated))

int dp[100][100];//also we can globalise with vector memset(dp, -1, sizeof(dp))-> in main fn
int knapsack(int wr[], int val[], int W, int n){
    if(n==0||W==0) return 0; 
    if(dp[n][W]!=-1) return dp[n][W];
    if(wr[n-1]<=W){
    return dp[n][W]=max(val[n-1]+knapsack(wr,val,W-wr[n-1],n-1), knapsack(wr,val, W, n-1));
    }
    else if(wr[n-1]>W) return dp[n][W]=knapsack(wr,val, W, n-1);
}

top down approach-> to avoid stack overflow error
1. intialise the dp[n+1][W+1], 1st row and 1st colum  with base condition of recurrsive fn
->each box of mtrix represent the sub problem of knapsack
ex:- dp[2][3]-> ar[]={1,3}, val[]={1,4} , W=3 inside that box represnt answer
so, intialise 1st row and 1st colum with 0
2.convert recurrsive function in itrative way

int dp[100][100];
for(int i=0;i<n+1; i++){
    for(int j=0;j<W+1;j++){
        if(i==0 ||j==0){
            dp[i][j]=0;
        }
    }
}
if(wr[n+1]<=W){
    dp[n][W]=max(val[n-1]+dp[n-1][W-wr[n+1]],  dp[n+1][W]);
}
else{
    dp[n][W]=dp[n+1][W];
}
-> final code
int dp[100][100];
for(int i=0;i<n+1; i++){
    for(int j=0;j<W+1;j++){
        if(i==0 ||j==0){
            dp[i][j]=0;
        }
    }
}
for(int i=0;i<n+1;i++){
    for(int j=0;j<W+1;j++){
        if(wr[n+1]<=W){
    dp[i][j]=max(val[i-1]+dp[i-1][W-wr[i+1]],  dp[i+1][j]);
    }
     else{
        dp[i][j]=dp[i+1][j];
      }
    }
}
/*arr[]=2 3 7 8 10->n
sum=11 does this array contain the subset of sum=11 (3,8){ each ele has 2 option y/n in subset}
simalar to knapsach problem
dp[n+1][s+1] -> marix//row-> size of array  colum-> sum  size=0(row=0) sum alwayse 0-> false(no set is possible) if sum=0(colum=0) sum alwase possible-> true( set is possible)
initialiasion
  0 1 2 3 .....11
0 t f f f f...
1 t
2 t
3 t
.
5
*/
dp[n+1][s+1]//n-> i s->j
for(int i=0;i<n;i++){
    for(int j=0;j<s;j++){
        if(i==0) dp[i][j]=false;
        if(j==0) dp[i][j]=true;
        if(arr[i+1]<j=){
    dp[i][j]=dp[i][j-arr[i+1]]||dp[i-1][j];
}
else{
    dp[i][j]=dp[i-1][j];
}
    }
}
//equal sum partion  sumof two partion array is equal or not
/*arr[]={1,5,11,3} -> {1,5,3} or {11}  o/p=yes
if sum of array is even then in can be divided in 2 partion-> if we get even sum then we get one 
more information that is sum=x;
now->
arr[]={1,5,11,3}   sum=22*/
sum=0;
for(int i=0;i<n;i++){
    sum=sum+arr[i];
}
if(sum%2==0) return 0;
else return subsetSum(arr,sum/2, n);//->t->found f->not found

