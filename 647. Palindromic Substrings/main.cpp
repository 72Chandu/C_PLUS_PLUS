//https://leetcode.com/problems/palindromic-substrings/description/

/*
Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
*/
 int expandaroundindex(string s, int left, int right){
    int count =0;
    // jab tak match karega , tab tk count increment karega and i piche or j aage kardo
    while(left>=0 && right<s.length() && s[left]==s[right]){
        count++;
        left--;
        right++;
    }
    return count;
}
int countSubstrings(string s) {
        int n=s.length();
        int count=0;
        for(int center=0;center<n;center++){
            //odd
            int oddans=expandaroundindex(s,center,center);
            count=count + oddans;
            //even
            int evenans=expandaroundindex(s,center,center+1);
            count=count + evenans;
        }
        return count;
}