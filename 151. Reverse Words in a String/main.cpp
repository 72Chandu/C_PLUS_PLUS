/*
https://leetcode.com/problems/reverse-words-in-a-string/submissions/1397019693/

*/
class Solution {
public:
    string reverseWords(string s) {
        // Trim leading and trailing spaces and reduce multiple spaces to a single one
        int n = s.length();
        string result = "", word = "";
        vector<string> words;
        for (int i = 0; i < n; ++i) {
            if (s[i] != ' ') {
                word += s[i];//1.the 2.sky
            } else if (word != "") {
                words.push_back(word);//[the,sky]
                word = "";
            }
        }
        if (word != "") {// Add the last word if any
            words.push_back(word);
        }
        // Reverse the order of words
        for (int i = words.size() - 1; i >= 0; --i) {
            result += words[i];
            if (i > 0) result += " ";// Add space between words, except after the last one
        }
        return result;
    }
};
