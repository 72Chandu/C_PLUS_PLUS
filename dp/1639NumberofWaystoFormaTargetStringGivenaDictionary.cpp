//https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/description/
class Solution {
public:
    int m;
    int k;
    const int MOD=1e9+7;
    int dp[1001][1001];
    int solve(int i, int j, vector<vector<long long>>& freq, string & tar){
        if(i==m) return 1;
        if(j==k) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int not_taken=solve(i,j+1,freq,tar);
        int taken=(freq[tar[i]-'a'][j] * solve(i+1,j+1,freq,tar))%MOD;
        return dp[i][j]=(not_taken+taken)%MOD;
    }
    int numWays(vector<string>& words, string target) {
        k=words[0].size();
        m=target.length();
        vector<vector<long long>> freq(26, vector<long long>(k));
        for(int col = 0; col < k; col++) {
            for(string &word : words) {
                freq[word[col] - 'a'][col]++;
            }
        }
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, freq, target);
    }
};
/*      
Input: words = ["acca","abbb","caca"], target = "aba"
                 j                               i
  0 1 2 3 
0 a c c a
1 a b b b
2 c a c a

acca,abba,caca             acca,abba,caca 
i-> (cca,bba,aca)               i-> (cca,bba,aca)
     
there is same while choosing the 'a' of 0th idx of a , so for a -> 2
   0 1 2 3  
a  2 1 0 2
b  0 . . . 
c  1 . . . 
d . . .
.
.
z
frq of a at o idx=2
*/
