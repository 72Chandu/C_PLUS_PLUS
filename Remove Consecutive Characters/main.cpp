/*Input:
S = aabb
Output:  ab 
Explanation: 'a' at 2nd position is
appearing 2nd time consecutively.
Similiar explanation for b at
4th position.

Example 2:

Input:
S = aabaa
Output:  aba
Explanation: 'a' at 2nd position is
appearing 2nd time consecutively.
'a' at fifth position is appearing
2nd time consecutively.*/
string removeConsecutiveCharacter(string s) {
    string ans = "";
    for (int i = 0; i < s.length(); i++) {
        if (i==s.length()-1||s[i]!=s[i + 1]) {// Check if the current character is not the same as the next one
            ans += s[i];
        }
    }

    return ans;
}