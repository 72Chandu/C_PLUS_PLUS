/*https://atcoder.jp/contests/dp/tasks/dp_a
If the frog is currently on Stone i, jump to Stone i+1 or Stone i+2. Here, a cost of 
|hi-hj| is incurred, where j is the stone to land on.
 minimum possible total cost incurred before the frog reaches Stone N.
 4
10 30 40 20
Sample Output:30
If we follow the path 1 → 2 → 4, the total cost incurred would be ∣10−30∣+∣30−20∣=30

2
10 10
Sample Output:0 If we follow the path 1 → 2, the total cost incurred would be ∣10−10∣=0.
Sample Input 3
6
30 10 60 10 60 50
Sample Output :40If we follow the path 1 → 3 → 5 → 6, the total cost incurred would be 
∣30−60∣+∣60−60∣+∣60−50∣=40.
*/
#include<bits/stdc++.h> 
using namespace std;
vector<int> dp, h; // Declare two global vectors 'dp' and 'h'
int frog(int i){ // Function to calculate minimum energy required for the frog to jump
    if(i==0) return 0; // Base case: If the frog is at the first stone, no energy is required
    if(dp[i]!=-1){ // If minimum energy for stone 'i' is already computed
        return dp[i]; // Return the precomputed value
    }
    // Calculate the minimum energy required for the frog to jump from stone 'i' to stone 'i-1'
    int ans1=abs(h[i]-h[i-1])+frog(i-1);
    int ans2=INT_MAX; // Initialize ans2 with a large value
    if(i>1){ // Check if it's possible to jump from stone 'i' to stone 'i-2'
        ans2=abs(h[i-2]-h[i])+frog(i-2); // Calculate the minimum energy for that jump
    }
    // Store the minimum energy required for stone 'i' in dp array
    dp[i]=min(ans1, ans2); // Choose the minimum energy between the two possible jumps
    return dp[i]; // Return the minimum energy required for stone 'i'
}
int main(){
    int n; 
    cin>>n; // Input the number of stones
    dp.assign(n+1,-1); // Initialize dp[i] to -1 to check if dp[i] is computed or not
    h.resize(n); // Resize vector h to store heights of stones
    for(int i=0;i<n;i++){ // Input the heights of stones
        cin>>h[i];
    }
    cout<<frog(n-1); // minimum energy required for the frog to jump to the last stone
    return 0;
}

//---------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n; // Input the number of stones
    
    vector<int> dp(n+1, 0); // Declare and initialize vector 'dp' to store minimum energy required
    vector<int> h(n); // Declare vector 'h' to store heights of stones
    
    for(int i = 0; i < n; i++){ // Input the heights of stones
        cin >> h[i];
    }
    
    dp[0] = 0;//If the frog is at the first stone, no energy is required

    // Loop through stones to calculate minimum energy required for each stone
    for(int i = 1; i < n; i++){
        // energy required for the frog to jump from stone 'i' to stone 'i-1'
        int ans1 = abs(h[i] - h[i-1]) + dp[i-1];
        
        int ans2 = INT_MAX;// Initialize ans2 with a large value

        if(i > 1){ // Check if it's possible to jump from stone 'i' to stone 'i-2'
            ans2 = abs(h[i-2] - h[i]) + dp[i-2];//the energy required for that jump
        }
        
        dp[i] = min(ans1, ans2);// Store the minimum energy required for stone 'i' in dp array
    }
    cout << dp[n-1]; //minimum energy required for the frog to jump to the last stone
    return 0;
}


//https://leetcode.com/problems/frog-jump/description/
//403. Frog Jump
/*
f the frog's last jump was k units, its next jump must be either k - 1, k,or k + 1 units. The frog can only jump in the forward direction.
stones = [0,1,3,5,6,8,12,17]

privious_jump=2 =pj
currtent_jump=5=cs
  jump    
pj-1  1  6  -> 6 wala stone hai to-> possible
pj    2  7  ->not possible
pj+1  3  8  ->possible

dry run 
 0 1 2 3 4 5 6 7
[0,1,3,5,6,8,12,17]
 i
csi   -> pj=0 cs=0
pj-1   pj   pj +1
 -1x   0x      1 / ->cs=1 , pj=1

0 1 2 3 4 5 6 7
[0,1,3,5,6,8,12,17]
   i
   csi   -> pj=1 cs=1
pj-1   pj   pj +1
 0x    1x     2 / ->cs=3 , pj=2
similarly dry run
*/
int n;
    unordered_map<int,int>mp;//for checking the desire stone is present or not 
    int solve(vector<int>& stones, int curr_stone_idx, int prevjump){
        if(curr_stone_idx==n-1){
            return true;
        }
        bool result=false;
        for(int nextjump=prevjump-1;nextjump<=prevjump+1;nextjump++){
            if(nextjump>0){
                int next_stone=stones[curr_stone_idx]+nextjump;
                if(mp.find(next_stone)!=mp.end()){
                result=result||solve(stones,mp[nextjump],nextjump);
                }
            }
        }
        return result;
    }
    bool canCross(vector<int>& stones) {
        n=stones.size();
        if(stones[1]!=1) return false;
        for(int i=0;i<n;i++){
            mp[stones[i]]=i;
        }
        return solve(stones , 0, 0);   
    }
    
    //---------------------------------------------------------------
    class Solution {
public:
    int n;
    vector<vector<int>> t; // Memoization table
    unordered_map<int, int> mp; // Map to check if the desired stone is present or not

    bool solve(vector<int>& stones, int curr_stone_idx, int prevjump) {
        if (curr_stone_idx == n - 1) {
            return true;
        }
        if (t[curr_stone_idx][prevjump] != -1) {
            return t[curr_stone_idx][prevjump];
        }
        bool result = false;
        for (int nextjump = prevjump - 1; nextjump <= prevjump + 1; nextjump++) {
            if (nextjump > 0) {
                int next_stone = stones[curr_stone_idx] + nextjump;
                if (mp.find(next_stone) != mp.end()) {
                    int next_stone_idx = mp[next_stone];
                    result = result || solve(stones, next_stone_idx, nextjump);
                }
            }
        }
        return t[curr_stone_idx][prevjump] = result;
    }

    bool canCross(vector<int>& stones) {
        n = stones.size();
        if (stones[1] != 1) return false;
        for (int i = 0; i < n; i++) {
            mp[stones[i]] = i;
        }
        t.resize(n, vector<int>(n, -1)); // Resize and initialize the memoization table
        return solve(stones, 0, 0);
    }
};


#include<bits/stdc++.h> 
using namespace std; 

int main(){ 
    int n; // store the number of stones
    cin >> n;
    int k; // store the maximum number of steps the frog can take
    cin >> k;
    
    vector<int> dp(n + 1, INT_MAX); // store dynamic programming values
    vector<int> h(n); // store heights of stones
    
    dp[0] = 0; // If the frog is at the first stone, return 0 energy
    
    for(int i = 0; i < n; i++){ // Loop to input the heights of the stones
        cin >> h[i]; // Input the height of the ith stone
    }
    
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= min(k, i); j++){ // Iterate over possible jump lengths from 1 to minimum of k and i
            dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j])); // Update dp[i] with the minimum energy among possible jumps
        }
    }
    
    cout << dp[n - 1]; // Output the minimum energy required to reach the last stone
    
    return 0;
}


//------------------------------------------------------------
/* Sample Input 1: 5 3    10 30 40 50 20   Sample Output: 30
If we follow the path 1 → 2 → 5, the total cost incurred would be ∣10−30∣+∣30−20∣=30.

Sample Input: 3 1    10 20 10   Sample Output: 20
If we follow the path 1 → 2 → 3, the total cost incurred would be ∣10−20∣+∣20−10∣=20.

Sample Input: 2 100   10 10  Sample Output: 0
If we follow the path 1 → 2, the total cost incurred would be ∣10−10∣=0.

Sample Input: 10 4   40 10 20 70 80 10 20 70 80 60   Sample Output : 40
If we follow the path 1 → 4 → 8 → 10, the total cost incurred would be ∣40−70∣+∣70−70∣+∣70−60∣=40.*/
#include<bits/stdc++.h> 
using namespace std; 
vector<int> dp, h; //store dynamic programming values and heights of stones, respectively
int frog2(int i, int k){ 
    if(i == 0) return 0; // Base case: If the frog is at the first stone, return 0 energy
    if(dp[i] != -1){ // If the energy for stone i is already calculated, return it
        return dp[i];
    }
    int ans1 = abs(h[i] - h[i - 1]) + frog2(i - 1, k); // Calculate energy needed to jump from stone i-1 to i
    int ans2 = INT_MAX;
    for(int j = 2; j <= min(k, i); j++){ // Iterate over possible jump lengths from 2 to minimum of k and i
        ans2 = min(ans2, abs(h[i] - h[i - j]) + frog2(i - j, k)); // Update ans2 with the minimum energy among possible jumps
    }
    return dp[i] = min(ans1, ans2); // Store and return the minimum energy for stone i
}
int main(){ 
    int n; // store the number of stones
    cin >> n;
    int k; // store the maximum number of steps the frog can take
    cin >> k;
    dp.assign(n + 1, -1); // Initialize the dp vector with -1
    h.resize(n); // Resize the h vector to store n elements
    for(int i = 0; i < n; i++){ // Loop to input the heights of the stones
        cin >> h[i]; // Input the height of the ith stone
    }
    cout << frog2(n - 1, k); //minimum energy required to reach the last stone
    return 0;
}


