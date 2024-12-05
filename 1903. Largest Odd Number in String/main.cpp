/*
https://leetcode.com/problems/largest-odd-number-in-string/description/

Input: num = "52"
Output: "5"
Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
Example 2:

Input: num = "4206"
Output: ""
Explanation: There are no odd numbers in "4206".
Example 3:

Input: num = "35427"
Output: "35427"
Explanation: "35427" is already an odd number.
*/



class Solution {
public:
    string largestOddNumber(string num) {
         int n = num.length();
         for (int i = n - 1; i >= 0; i--) {
            int digit = num[i] - '0';
         if (digit % 2 != 0) {
            return num.substr(0, i + 1);
         }
        }
    return "";
    }
};