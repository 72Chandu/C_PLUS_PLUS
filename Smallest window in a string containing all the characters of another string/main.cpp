s-> d b a e c b b a b d c a a f b d d c a b g b a
p-> a b b c d c (a-1 b-2 c-2 d-1) (cha->freq) 
count=0 increse the count till the freq of s[i] is same as the freq of p[i] ohterwise not if 

d-> count=1 b->count=2 a->count=3 e-> count=3(e is no in p) c-> count=4 b->count=5 b->count=5(p->b-2, here b->3) a->count=5 b->count=5 d->count=5 c->count=6
s-> d b a e c b b a b d c a a f b d d c a b g b a
j   i->                 i  (count=6 stop now try to minimize the window)(d-2 b-4 a-2 c-2)

s-> d b a e c b b a b d c a a f b d d c a b g b a
            j           i  (count=6 stop now try to minimize the window)(d-1 b-3 a-1 c-2)
--------------------------------------------------------------------------------------
s-> d b a e c b b a b d c a a f b d d c a b g b a
              j         i  (count=5 stop now try to minimize the window)(d-1 b-3 a-1 c-2)

s-> d b a e c b b a b d c a a f b d d c a b g b a
              j                       i  (count=6 stop now try to minimize the window)(d-3 b-4 a-3 c-2)

s-> d b a e c b b a b d c a a f b d d c a b g b a
                    j                 i  (count=6 stop now try to minimize the window)(d-3 b-2 a-2 c-2)
--------------------------------------------------------------------------------------
s-> d b a e c b b a b d c a a f b d d c a b g b a
                      j               i  (count=5 stop now try to minimize the window)(d-3 b-1 a-2 c-2)

s-> d b a e c b b a b d c a a f b d d c a b g b a
                      j                   i  (count=6 stop now try to minimize the window)(d-3 b-2 a-2 c-2)
again do same process 

your answer is minimum window which contain at lesat (a-1 b-2 c-2 d-1) in s 


/*#include <iostream>
#include <unordered_map>
#include <string>
#include <climits>

using namespace std;

string smallestWindow(string s, string p) {
    int s_len = s.length();
    int p_len = p.length();

    if (s_len < p_len)
        return "";

    unordered_map<char, int> hash_p; // Hashmap for pattern
    unordered_map<char, int> hash_s; // Hashmap for string

    // Store occurrence count of characters of pattern
    for (char c : p)
        hash_p[c]++;

    int start = 0, min_len = INT_MAX;
    int count = 0;
    int start_index = -1;

    // Traverse the string
    for (int end = 0; end < s_len; end++) {
        // Increment the count of the current character in the string
        if (hash_p.find(s[end]) != hash_p.end()) {
            hash_s[s[end]]++;
            if (hash_s[s[end]] <= hash_p[s[end]]) {
                count++;
            }
        }

        // If all the characters are matched
        while (count == p_len) {
            // Update the minimum window size
            int window_len = end - start + 1;
            if (min_len > window_len) {
                min_len = window_len;
                start_index = start;
            }

            // Try to minimize the window
            if (hash_p.find(s[start]) != hash_p.end()) {
                hash_s[s[start]]--;
                if (hash_s[s[start]] < hash_p[s[start]]) {
                    count--;
                }
            }
            start++;
        }
    }

    // If no window found
    if (start_index == -1)
        return "";

    // Return substring starting from start_index and length min_len
    return s.substr(start_index, min_len);
}

int main() {
    string s = "ADOBECODEBANC";
    string p = "ABC";
    cout << "Smallest window containing all characters of pattern: " << smallestWindow(s, p) << endl;
    return 0;
}
*/
#include <iostream>
#include <string>
#include <climits>
#include <cstring>

using namespace std;

string smallestWindow(string s, string p) {
    int s_len = s.length();
    int p_len = p.length();

    if (s_len < p_len)
        return "-1"; // Return -1 if the string length is less than pattern length

    int hash_p[256] = {0}; // Array for pattern
    int hash_s[256] = {0}; // Array for string

    // Store occurrence count of characters of pattern
    for (char c : p)
        hash_p[c]++;

    int start = 0, min_len = INT_MAX;
    int count = 0;
    int start_index = -1;

    // Traverse the string
    for (int end = 0; end < s_len; end++) {
        // Increment the count of the current character in the string
        if (hash_p[s[end]] > 0) {
            hash_s[s[end]]++;
            if (hash_s[s[end]] <= hash_p[s[end]]) {
                count++;
            }
        }

        // If all the characters are matched
        while (count == p_len) {
            // Update the minimum window size
            int window_len = end - start + 1;
            if (min_len > window_len) {
                min_len = window_len;
                start_index = start;
            }

            // Try to minimize the window
            if (hash_p[s[start]] > 0) {
                hash_s[s[start]]--;
                if (hash_s[s[start]] < hash_p[s[start]]) {
                    count--;
                }
            }
            start++;
        }
    }

    // If no window found
    if (start_index == -1 || min_len == INT_MAX)
        return "-1";

    // Return substring starting from start_index and length min_len
    return s.substr(start_index, min_len);
}

int main() {
    string s = "mpsbqedzsqyskjqydomdanqfmtqri";
    string p = "rrbqrnbbzyijnwfnimshbjimbfe";
    cout << "Smallest window containing all characters of pattern: " << smallestWindow(s, p) << endl;
    return 0;
}
