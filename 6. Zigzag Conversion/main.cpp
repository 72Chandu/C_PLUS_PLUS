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

/*
numRows = 3      s = "PAYPALISHIRING"
arr = ["", "", ""] (An array of empty strings, one for each row)
cr = 0 (Current row)   mod = 0 (Direction modifier)
dir = [1, -1] (Direction array for moving down and up)

i= 0 (i = 0, s[i] = 'P'):  arr = ["P", "", ""]  newRow = 1 (Moving down)

i= 1 (i = 1, s[i] = 'A'):  arr = ["P", "A", ""] newRow = 2 (Moving down)

i= 2 (i = 2, s[i] = 'Y'):  arr = ["P", "A", "Y"] newRow = 3 (Reaches the bottom row, change direction)  mod = 1 (Change direction to up)  newRow = 1

i= 3 (i = 3, s[i] = 'P'):  arr = ["P", "AP", "Y"] newRow = 0 (Moving up)

i= 4 (i = 4, s[i] = 'A'):  arr = ["PA", "AP", "Y"] newRow = -1 (Reaches the top row, change direction)  mod = 0 (Change direction to down)  newRow = 1

i= 5 (i = 5, s[i] = 'L'):  arr = ["PA", "APL", "Y"] newRow = 2 (Moving down)

i= 6 (i = 6, s[i] = 'I'):  arr = ["PA", "APL", "YI"] newRow = 3 (Reaches the bottom row, change direction)  mod = 1 (Change direction to up)  newRow = 1

i= 7 (i = 7, s[i] = 'S'): arr = ["PA", "APLS", "YI"] newRow = 0 (Moving up)

i= 8 (i = 8, s[i] = 'H'): arr = ["PAH", "APLS", "YI"] newRow = -1 (Reaches the top row, change direction) mod = 0 (Change direction to down) newRow = 1

i= 9 (i = 9, s[i] = 'I'):  arr = ["PAH", "APLSI", "YI"] newRow = 2 (Moving down)

i= 10 (i = 10, s[i] = 'R'):  arr = ["PAH", "APLSI", "YIR"] newRow = 3 (Reaches the bottom row, change direction)  mod = 1 (Change direction to up) newRow = 1

i= 11 (i = 11, s[i] = 'I'): arr = ["PAH", "APLSII", "YIR"] newRow = 0 (Moving up)

i= 12 (i = 12, s[i] = 'N'): arr = ["PAHN", "APLSII", "YIR"] newRow = -1 (Reaches the top row, change direction) mod = 0 (Change direction to down)  newRow = 1

i= 13 (i = 13, s[i] = 'G'): arr = ["PAHN", "APLSIIG", "YIR"]  newRow = 2 (Moving down)

Concatenate All Rows to Form the Final Result: res = "PAHNAPLSIIGYIR"
*/
