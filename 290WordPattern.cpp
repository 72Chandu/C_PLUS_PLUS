//https://leetcode.com/problems/word-pattern/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream iss(s);
        vector<string> words;
        string word;
        while (iss >> word) {
            words.push_back(word);
        }
        if (pattern.size() != words.size()) return false;
        unordered_map<char,string> charToWord;
        unordered_map<string, char> wordToChar;
        for (int i = 0; i < pattern.size(); ++i) {
            char p = pattern[i];
            string w = words[i];
            if (charToWord.count(p)) {
                if (charToWord[p] != w) return false;
            
            }
            if (wordToChar.count(w)) {
                if (wordToChar[w] != p) return false;  
            }
            charToWord[p] = w;
            wordToChar[w] = p;
        }
        return true;
    }
};
