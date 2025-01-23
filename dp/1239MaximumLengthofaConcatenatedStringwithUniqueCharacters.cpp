/*
https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/

Input: arr = ["un","iq","ue"]
               i----------i
        cae1   in    in   ex   in=include , ex=exclude
        cae2   ex    in   ex   in=include , ex=exclude
               
temp1="" -> checking temp me or i me dublicate element hai ki nahi if no then add, other wise skip
     "un"
     "uniq" ("un" + "iq") ->4
temp2=""
      "iq"
      "ique" ("iq" + "ue") ->4
here we include or exclude the "un" we also do for all . therefor we conclude that there is 2 choice for 
each 
Output: 4
Explanation: All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.
                        ["un","iq","ue"]
                          i temp=""
                         /\
            temp=un I   /  \ E
                       /    \
                {iq,ue}      {iq,ue} temp=""
                  i            i
               I /\ E        I/\E
               after traversing all recurion it will return max(include, exclude);
*/
bool hasDuplcate(string &s1, string &s2){
    int arr[26]={0};
    for(char &ch:s1){
        if(arr[ch-'a']>0) return true;
        arr[ch-'a']++;
    }
    for(char &ch:s2){
        if(arr[ch-'a']>0) return true;
    }
    return false;
}
int solve(int i, vector<string>&arr, string temp, int n){
    if(i>=n) return temp.length();
    int include=0;
    int exclude=0;
    if(hasDuplcate(arr[i], temp)){ // duplicate hai to exclude
        exclude=solve(i+1, arr, temp,n);
    }else{
        exclude=solve(i+1, arr, temp,n);
        include=solve(i+1, arr, temp+arr[i],n); // i or temp change ho raha hai
    }
    return max(include,exclude);
}
int maxLength(vector<string>& arr) {
        string temp="";
        int n=arr.size();
        int i=0;
        return solve(i,arr,temp,n);
}
//------------------------------Dp---------------------

bool hasDuplcate(string &s1, string &s2){
    int arr[26]={0};
    for(char &ch:s1){
        if(arr[ch-'a']>0) return true;
        arr[ch-'a']++;
    }
    for(char &ch:s2){
        if(arr[ch-'a']>0) return true;
    }
    return false;
}
unordered_map<string,int>dp;
int solve(int i, vector<string>&arr, string temp, int n){
    if(i>=n) return temp.length();
    int include=0;
    int exclude=0;
    if(dp.find(temp)!=dp.end()){
        return dp[temp];
    }
    if(hasDuplcate(arr[i], temp)){ // duplicate hai to exclude
        exclude=solve(i+1, arr, temp,n);
    }else{
        exclude=solve(i+1, arr, temp,n);
        include=solve(i+1, arr, temp+arr[i],n);
    }
    return dp[temp]=max(include,exclude);
}
int maxLength(vector<string>& arr) {
        string temp="";
        dp.clear();
        int n=arr.size();
        int i=0;
        return solve(i,arr,temp,n);
}
