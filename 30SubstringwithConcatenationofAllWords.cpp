//https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty() || s.empty()) return res;

        int wordLen = words[0].length();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        unordered_map<string, int> wordfreq;
        for (string &w : words) wordfreq[w]++;

        for (int i = 0; i < wordLen; i++) { // sliding window starting at different offsets
            int l = i, r = i, count = 0;
            unordered_map<string, int> window;

            while (r + wordLen <= s.size()) {
                string w = s.substr(r, wordLen);
                r += wordLen;

                if (wordfreq.count(w)) {
                    window[w]++;
                    count++;

                    while (window[w] > wordfreq[w]) {
                        string left_w = s.substr(l, wordLen);
                        window[left_w]--;
                        count--;
                        l += wordLen;
                    }

                    if (count == wordCount) {
                        res.push_back(l);
                    }
                } else {// Not a valid word, reset window
                    window.clear();
                    count = 0;
                    l = r;
                }
            }
        }
        return res;
    }
};

/*
s = "barfoofoobarthefoobarman"
words = ["bar", "foo", "the"]
wordFreq = {"bar": 1,"foo": 1, "the": 1}

s =  b  a  r  f  o  o  f  o  o  b  a  r  t  h  e  f  o  o  b  a  r  m  a  n
     ↑           ↑           ↑           ↑           ↑           ↑
    left        r=0         r=3         r=6         r=9         r=12

       |---"bar"---| => word in `words`
       → window = {"bar":1}, count = 1

       |---"foo"---| => word in `words`
       → window = {"bar":1, "foo":1}, count = 2

       |---"foo"---| => word in `words`, but "foo" now seen twice
       → overused! start shrinking from left:
          - remove "bar", left += 3 → left=3
          - remove "foo", left += 3 → left=6
          → seen = {"foo":1}, count = 1

       |---"bar"---| => word in `words`
       → window = {"foo":1, "bar":1}, count = 2

       |---"the"---| => word in `words`
       → window = {"foo":1, "bar":1, "the":1}, count = 3
       match found at `left = 6`

Index:     0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3
s     =  [ b a r f o o f o o b a r t h e f o o b a r m a n ]
window =            [ f o o | b a r | t h e ]  valid (index 6)


Continuing Traversal:
s[9:18] = "barthefoo" →  valid
→ seen = {"bar":1, "the":1, "foo":1}
→ add index 9

s[12:21] = "thefoobar" →  valid
→ seen = {"the":1, "foo":1, "bar":1}
→ add index 12

[6, 9, 12]
*/
