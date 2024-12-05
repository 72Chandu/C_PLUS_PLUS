/*Input: S = "aaaabbaa"  Output: aabbaa      Explanation: The longest Palindromic  substring is "aabbaa".

Input: S = "abc"  Output: a   Explanation: "a", "b" and "c" are the longest palindromes with same length.
The result is the one with the least starting index.*/

//r a c e c a r
	bool isPalindrome(string s) {
    int n = s.size();
    int i = 0;
    int j = n - 1;
    while (i < j) {
        if (s[i] != s[j]) {
            return false; // If characters at current positions are not equal, return false immediately.
        }
        i++;
        j--;
    }
    
    return true; // If the loop completes without returning false, it means the string is a palindrome.
}
string longestPalindrome(string s){
    if(s.length()<=1) return s;
    int maxlen=1;
    string maxstr=s.substr(0,1);
    for(int i=0;i<s.length();i++){//try for all substring that it is palindromes of longest
        for(int j=maxlen;j<s.length();j++){
            if(j-i>maxlen && ispalindromes(s.substr(i,j-i))){
                maxlen=j-i;
                maxstr=s.substr(i,j-i);
            }
        }
    }
    return maxstr;
}
//time =o(n^3)
/*  r  a  c  e  c  a  r
    l->             <-r
*/
int dp[1001][1001];
bool solve(string &s, int l, int r){
    if(l>=r) return 1;
    if(dp[l][r]!=-1) return dp[l][r];
    if(s[l]=s[r]) return dp[l][r]=solve(s,l+1,r-1);
    return dp[l][r]=false;
}
string longestPalindrome(string s){
    int maxlen=INT_MIN;
    int stringIndex=0;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(solve(s,i,j)){
                if(j-i+1>maxlen){
                   stringIndex=i;
                   maxlen=j-i+1;
                }
            }
            
        }
    }
    return s.substr(stringIndex,maxlen);
}
//t=o(n^2)  s=o(n^2)
//bootom up approch
string palindromes(string s){
    int n = s.length();
    if (n <= 1)
        return s;
    int maxlen = 1;
    int startingIndex = 0;
    int end = 0;
    vector<vector<bool>> dp(n, vector<bool>(n, false)); // Corrected initialization
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
        for (int j = 0; j < i; j++) {
            if (s[j] == s[i] && (i - j + 1 <= 2 || dp[j + 1][i - 1])) {
                dp[j][i] = true;
                if (i - j + 1 > maxlen) {
                    maxlen = i - j + 1;
                    startingIndex = j;
                    end = i;
                }
            }
        }
    }
    return s.substr(startingIndex, end - startingIndex + 1);
}
//2 pointer
string longestPalindrome(string s){
    int n=s.length();
    if(n<=1)return s;
    auto expand_from_center=[&](int l,int r){
        while(l>=0 && r<n && s[l]==s[r]){
            l--;
            r++;
        }
        return s.substr(l+1, r-l-1);
    };
    string maxstr=s.substr(0,1);
    for(int i=0;i<n-1;i++){
        string odd=expand_from_center(i,i);
        string even=expand_from_center(i,i+1);
        if(odd.length()>maxstr.length()) maxstr=odd;
        if(even.length()>maxstr.length())maxstr=even;
    }
    return maxstr;
}
