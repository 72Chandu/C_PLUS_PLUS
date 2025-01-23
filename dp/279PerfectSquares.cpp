/*
https://leetcode.com/problems/perfect-squares/description/ 
return the least number of perfect square numbers that sum to n.
A perfect square is an integer that is the square of an integer; 
Input: n = 12
Output: 3
                        12     all perfect square less then 12(1,4,9)
                  1  /  4| 9 \
                   /     |     \
                  11     8      3   similarly we do with 11,8,3
             1,4,9     1,4     1     jab ans=0 the minimum step taken to reach to 0 is ans. 
bahot sara potion recursion ka repete ho raha hai so, we can use dp
*/

int solve(int n){
    if(n==0) return 0;
    int min_count=INT_MAX;
    for(int i=1;i*i<=n;i++){
        int res=1+solve(n-i*i);//i*i=1,4,9....1->at each iteration 1 is inc in each step
        min_count=min(min_count,res);
    }
    return min_count;
}
int numSquares(int n) {
    return solve(n);
}

//---------------------------------------------------
int dp[10001];
int solve(int n){
    if(n==0) return 0;
    if(dp[n]!=-1){
        return dp[n];
    }
    int min_count=INT_MAX;
    for(int i=1;i*i<=n;i++){
        int res=1+solve(n-i*i);//i*i=1,4,9....1->at each iteration 1 is inc in each step
        min_count=min(min_count,res);
    }
    return dp[n]=min_count;
}
int numSquares(int n) {
    memset(dp,-1,sizeof(dp));
    return solve(n);
}
