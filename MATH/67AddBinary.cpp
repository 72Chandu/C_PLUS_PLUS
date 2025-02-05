//https://leetcode.com/problems/add-binary/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    string addBinary(string a, string b) {
        int na=a.length();
        int nb=b.length();
        string ans="";
        int carry=0;
        int i=na-1, j=nb-1;
        while(i>=0 || j>=0 || carry){
            int sum=carry;
            if(i>=0){
                sum=sum+a[i]-'0';
                i--;
            } 
            if(j>=0){
                sum=sum+b[j]-'0';
                j--;
            }
            carry=sum>1?1:0;
            ans+=to_string(sum%2); 
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
/*
Initial: a = "1101", b = "1011", carry = 0, ans = ""
1st Iteration:
- sum = carry = 0
- i = 3, a[i] = '1' => sum = 0 + 1 = 1
- j = 3, b[j] = '1' => sum = 1 + 1 = 2
- carry = sum > 1 ? 1 : 0 => carry = 1
- ans = to_string(sum % 2) = "0"
- i = 2, j = 2

2nd Iteration:
- sum = carry = 1
- i = 2, a[i] = '0' => sum = 1 + 0 = 1
- j = 2, b[j] = '1' => sum = 1 + 1 = 2
- carry = sum > 1 ? 1 : 0 => carry = 1
- ans = to_string(sum % 2) = "00"
- i = 1, j = 1

3rd Iteration:
- sum = carry = 1
- i = 1, a[i] = '1' => sum = 1 + 1 = 2
- j = 1, b
*/
