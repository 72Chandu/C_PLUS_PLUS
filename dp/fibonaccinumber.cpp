//https://leetcode.com/problems/fibonacci-number/ 
 
 int recsolv(int n){
        if(n==1 || n==0){
            return n;
        }
        int ans=recsolv(n-1)+recsolv(n-2);
        return ans;
    }
    int topdown(int n , vector<int>&dp){
        if(n==1 || n==0){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n]=topdown(n-1 , dp)+ topdown(n-2 , dp);
        return dp[n];
    }
    int bottomUp(int n){
        vector<int>dp(n+1 , -1);
        dp[0]=0;
        if(n==0) 
            return dp[0];
        dp[1]=1;
        if(n==1)
            return dp[1];
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    int fib(int n) {
        //int ans=recsolv(n);

        // vector<int>dp(n+1 , -1);//creating dp array
        // int ans=topdown(n, dp);

        int ans=bottomUp(n);
        return ans;
    }
