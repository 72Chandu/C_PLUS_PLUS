//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/
/*
Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
*/
string removeDuplicates(string s) {
        string ans="";
        int i=0;
        while(i<s.length()){
            if(ans.length()>0){
                if(ans[ans.length()-1]==s[i]){
                    ans.pop_back();
                }else{
                    ans.push_back(s[i]);
                }
            }else{
                ans.push_back(s[i]);
            }
            i++;
        }
        return ans;
}

//-------------
    string removeDuplicates(string s) {
        string ans="";
        int i=0;
        while(i<s.length()){
                if(ans.length()>0 && ans[ans.length()-1]==s[i]){
                    ans.pop_back();
                }else{
                    ans.push_back(s[i]);
                }
            i++;
        }
        return ans;
}
//-------------
