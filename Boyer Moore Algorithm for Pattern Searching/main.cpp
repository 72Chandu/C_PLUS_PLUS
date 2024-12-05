/*Input:  txt[] = "THIS IS A TEST TEXT"
        pat[] = "TEST"
Output: Pattern found at index 10

Input:  txt[] =  "AABAACAADAABAABA"
        pat[] =  "AABA"
Output: Pattern found at index 0
        Pattern found at index 9
        Pattern found at index 12*/
Boyer Moore algorithm starts matching from the last character of the pattern.
Bad Character Heuristic: The idea of bad character heuristic is simple. The character of the text which 
doesn’t match with the current character of the pattern is called the Bad Character. Upon mismatch, we shift the pattern until – 
The mismatch becomes a match.
Pattern P moves past the mismatched character.
Case 1 – Mismatch become match 
We will lookup the position of the last occurrence of the mismatched character in the pattern, and if 
the mismatched character exists in the pattern, then we’ll shift the pattern such that it becomes a
ligned to the mismatched character in the text T. 
Boyer Moore Algorithm for Pattern Searching
case 1


Explanation: In the above example, we got a mismatch at position 3. Here our mismatching character is “A”. Now we will search for last occurrence of “A” in pattern. We got “A” at position 1 in pattern (displayed in Blue) and this is the last occurrence of it. Now we will shift pattern 2 times so that “A” in pattern get aligned with “A” in text.

Case 2 – Pattern move past the mismatch character 
We’ll lookup the position of last occurrence of mismatching character in pattern and if character does not exist we will shift pattern past the mismatching character. 
 

Boyer Moore Algorithm for Pattern Searching
case2


Explanation: 

Here we have a mismatch at position 7. The mismatching character “C” does not exist in pattern before position 7 so we’ll shift pattern past to the position 7 and eventually in above example we have got a perfect match of pattern (displayed in Green). We are doing this because “C” does not exist in the pattern so at every shift before position 7 we will get mismatch and our search will be fruitless.

In the following implementation, we preprocess the pattern and store the last occurrence of every possible character in an array of size equal to alphabet size. If the character is not present at all, then it may result in a shift by m (length of pattern). Therefore, the bad character heuristic takes O(n/m)                      time in the best case. 

#include <bits/stdc++.h>
using namespace std;
# define NO_OF_CHARS 256 
 
// The preprocessing function for Boyer Moore's 
// bad character heuristic 
void badCharHeuristic( string str, int size, int badchar[NO_OF_CHARS]){ 
    int i; 
    // Initialize all occurrences as -1 
    for (i = 0; i < NO_OF_CHARS; i++) 
        badchar[i] = -1; 
    // Fill the actual value of last occurrence  of a character 
    for (i = 0; i < size; i++) 
        badchar[(int) str[i]] = i; 
} 
 
/* A pattern searching function that uses Bad Character Heuristic of Boyer Moore Algorithm */
void search( string txt, string pat) { 
    int m = pat.size(); 
    int n = txt.size(); 
    int badchar[NO_OF_CHARS]; 
    /* Fill the bad character array by calling the preprocessing function badCharHeuristic() for given pattern */
    badCharHeuristic(pat, m, badchar); 
    int s = 0; // s is shift of the pattern with  respect to text 
    while(s <= (n - m)) { 
        int j = m - 1; 
        /* Keep reducing index j of pattern while 
        characters of pattern and text are 
        matching at this shift s */
        while(j >= 0 && pat[j] == txt[s + j]) 
            j--; 
 
        /* If the pattern is present at current 
        shift, then index j will become -1 after 
        the above loop */
        if (j < 0) 
        { 
            cout << "pattern occurs at shift = " <<  s << endl; 
 
            /* Shift the pattern so that the next 
            character in text aligns with the last 
            occurrence of it in pattern. 
            The condition s+m < n is necessary for 
            the case when pattern occurs at the end 
            of text */
            s += (s + m < n)? m-badchar[txt[s + m]] : 1; 
 
        } 
 
        else
            /* Shift the pattern so that the bad character 
            in text aligns with the last occurrence of 
            it in pattern. The max function is used to 
            make sure that we get a positive shift. 
            We may get a negative shift if the last 
            occurrence of bad character in pattern 
            is on the right side of the current 
            character. */
            s += max(1, j - badchar[txt[s + j]]); 
    } 
} 
 
/* Driver code */
int main() 
{ 
    string txt= "ABAAABCD"; 
    string pat = "ABC"; 
    search(txt, pat); 
    return 0; 
} 