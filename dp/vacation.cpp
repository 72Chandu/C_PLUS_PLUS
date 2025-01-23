/*dp[i][j]-> maximum point that i can get in the starting i days such that ith activatiy is done on the ith */
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    for(int i = 1; i <= n; i++) {
        dp[i][0] = a[i] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = b[i] + max(dp[i-1][2], dp[i-1][0]);
        dp[i][2] = c[i] + max(dp[i-1][0], dp[i-1][1]);
    }
    int ans = max({dp[n][0], dp[n][1], dp[n][2]});
    cout << ans;
    return 0;
}

/*Sample Input 1
3->n(no of days)
a  b  c(a,b,c are the vacation )cannot do the same vacation for two or more consecutive days
10 40 70(point belong to respective vacation)
20 50 80
30 60 90
Sample Output: 210 If Taro does activities in the order C, B, C, he will gain 
70+50+90=210 points of happiness.
Sample Input 2
1
100 10 1
Sample Output: 100
Sample Input 3
7
6 7 8
8 8 3
2 5 2
7 8 6
4 6 8
2 3 4
7 5 1
Sample Output: 46 Taro should do activities in the order C, A, B, A, C, B, A.
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> memo; // store the point for vacation
vector<int> a, b, c; // arrays to store points for each day

int dp(int i, int j){
    if(i == 0) return 0;
    else if(memo[i][j] != -1) return memo[i][j];
    
    if(j == 0) memo[i][0] = a[i] + max(dp(i-1,1), dp(i-1,2)); // point for vacation a
    if(j == 1) memo[i][1] = b[i] + max(dp(i-1,0), dp(i-1,2)); // point for vacation b
    if(j == 2) memo[i][2] = c[i] + max(dp(i-1,0), dp(i-1,1)); // point for vacation c
    return memo[i][j];
}

int main(){
    int n; // no of days
    cin >> n;
    
    a.resize(n+1); // resize the array to store points for each day
    b.resize(n+1);
    c.resize(n+1);
    memo.resize(n+1, vector<int>(3, -1)); // resize and initialize memoization table
    
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i] >> c[i]; // input points for each day for each vacation
    }
    
    int ans = max({dp(n,0), dp(n,1), dp(n,2)}); // 0->a vacation 1->b vacation 2->c vacation
    cout << ans;
    
    return 0;
}
/*
a[i] represents the points obtained on the i-th day for vacation 'a'.
max(dp(i-1,1), dp(i-1,2)) finds the maximum points from the previous day for vacations 'b' and 'c', as the person cannot choose vacation 'a' on consecutive days.


b[i] represents the points obtained on the i-th day for vacation 'b'.
max(dp(i-1,0), dp(i-1,2)) finds the maximum points from the previous day for vacations 'a' and 'c', as the person cannot choose vacation 'b' on consecutive days.

c[i] represents the points obtained on the i-th day for vacation 'c'.
max(dp(i-1,0), dp(i-1,1)) finds the maximum points from the previous day for vacations 'a' and 'b', as the person cannot choose vacation 'c' on consecutive days.
Finally, return memo[i][j]; returns the total points for the current vacation option on the i-th day.
*/
