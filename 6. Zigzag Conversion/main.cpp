/*https://leetcode.com/problems/zigzag-conversion/description/

*/
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)return s;
        vector<string> arr(numRows, "");// Create an array of strings to hold each row's characters
        int cr = 0; // current row
        int mod = 0; // direction modifier (0 for down, 1 for up)
        int dir[2] = {1, -1}; // direction array
        for (int i = 0; i < s.length(); ++i) { // Iterate over each character in the string
            arr[cr] += s[i];
            int newRow = cr + dir[mod];
            if (newRow < 0 || newRow >= numRows) {// Change direction if we reach the top or bottom row
                mod = (mod + 1) % 2;
                newRow = cr + dir[mod];
            }
            cr = newRow;
        }
        string res = "";// Concatenate all the rows to form the final result
        for (const string &st : arr) {
            res += st;
        }
        return res;
    }
};