#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

// Recursive function to calculate the number of ways to reach step i
// without setting foot on the broken steps
long long countWays(int i, const vector<bool>& broken, vector<long long>& dp) {
    
    if (broken[i]) return 0;//if step i is a broken step, return 0

    if (i == 0) return 1; // if step i is the first or second step
    if (i == 1) return 1;
    
    if (dp[i] != -1) return dp[i];// If dp[i] has been calculated before, return it

    // Calculate dp[i] using the recurrence relation
    return dp[i] =(countWays(i - 1, broken, dp) + countWays(i - 2, broken, dp)) % MOD;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<bool> broken(N + 1, false);
    vector<long long> dp(N + 1, -1);
    
    for (int i = 0; i < M; ++i) {   // Mark the broken steps
        int a;
        cin >> a;
        broken[a] = true;
    }

    // Calculate the number of ways to reach the top step (N)
    long long ways = countWays(N, broken, dp);
    cout << ways << endl;
    return 0;
}/
/*
n=6 m=1  3   ->o/p=4
broken=[false, false,true,false,false,false]
         0      1     2    3     4     5
dp=[-1,-1,-1,-1,-1,-1]
*/


/*https://atcoder.jp/contests/abc129/tasks/abc129_c
Sample Input 1:
6 1
3
Sample Output 1: 4
There are four ways to climb up the stairs, as follows:
0→1→2→4→5→6
0→1→2→4→6
0→2→4→5→6
0→2→4→6
Sample Input 2:
10 2
4
5
Sample Output 2: 0
There may be no way to climb up the stairs without setting foot on the broken steps.
Sample Input 3:
100 5
1
23
45
67
89
Sample Output 3: 608200469
Be sure to print the count modulo 
1 000 000 007.*/
#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000007;
int main() {
    int N, M;//n->no of stairs  m->no of broken stairs
    cin >> N >> M;
    vector<long long> dp(N + 1, 0);
    vector<bool> broken(N + 1, false);
    for (int i = 0; i < M; ++i) {  // Mark the broken steps
        int a;
        cin >> a;
        broken[a] = true;
    }
    dp[0] = 1; // Base cases
    
    if (!broken[1]) dp[1] = 1;
    
    for (int i = 2; i <= N; ++i) {//itrating over each stair
        if (!broken[i - 1]) dp[i] += dp[i - 1];
        if (!broken[i - 2]) dp[i] += dp[i - 2];
        dp[i] %= MOD;
    }
    cout << dp[N] << endl;

    return 0;
}



