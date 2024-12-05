/*Input:  T[] = “THIS IS A TEST TEXT”, P[] = “TEST”
Output: Pattern found at index 10

Input:  T[] =  “AABAACAADAABAABA”, P[] =  “AABA”
Output: Pattern found at index 0
              Pattern found at index 9
              Pattern found at index 12

Step 1: Choose a suitable base and a modulus:

Select a prime number ‘p‘ as the modulus. This choice helps avoid overflow issues and ensures a good 
distribution of hash values. Choose a base ‘b‘ (usually a prime number as well), which is often the 
size of the character set (e.g., 256 for ASCII characters).
Step 2: Initialize the hash value: Set an initial hash value ‘hash‘ to 0.
Step 3: Calculate the initial hash value for the pattern:

Iterate over each character in the pattern from left to right.
For each character ‘c’ at position ‘i’, calculate its contribution to the hash value as ‘c * (bpattern_length – i – 1) % p’ and add it to ‘hash‘.
This gives you the hash value for the entire pattern.
Step 4: Slide the pattern over the text:

Start by calculating the hash value for the first substring of the text that is the same length as the pattern.
Step 5: Update the hash value for each subsequent substring:

To slide the pattern one position to the right, you remove the contribution of the leftmost character and add the contribution of the new character on the right.
The formula for updating the hash value when moving from position ‘i’ to ‘i+1’ is:
hash = (hash - (text[i - pattern_length] * (bpattern_length - 1)) % p) * b + text[i]
Step 6: Compare hash values:

When the hash value of a substring in the text matches the hash value of the pattern, it’s a potential match.
If the hash values match, we should perform a character-by-character comparison to confirm the match, as hash collisions can occur.
Below is the Illustration of above algorithm:

given text=315265 pattern=26 
   choose b=11
   p%b=26%11= 4
   
   3 1 5 2 6 5 -> 31%11=9 not equal to 4
   3 1 5 2 6 5 -> 15%11=4 -> Spurious hit
   3 1 5 2 6 5 -> 52%11=8 not equal to 4
   3 1 5 2 6 5 -> 26%11=4 equal TO 4 -> EXACT match
   3 1 5 2 6 5 -> 65%11=9 not equal to 4
*/
#include <bits/stdc++.h>
using namespace std;
#define d 256// d is the number of characters in the input alphabet

// pat -> pattern  txt -> text   q -> A prime number

void search (char pat[], char txt[], int q) {
  int M = strlen (pat);
  int N = strlen (txt);
  int i, j;
  int p = 0;					// hash value for pattern
  int t = 0;					// hash value for txt
  int h = 1;

  for (i = 0; i < M - 1; i++)             // The value of h would be "pow(d, M-1)%q"
	h = (h * d) % q;

  
  for (i = 0; i < M; i++){            // Calculate the hash value of pattern and first window of text
	  p = (d * p + pat[i]) % q;
	  t = (d * t + txt[i]) % q;
	}

 
  for (i = 0; i <= N - M; i++){            // Slide the pattern over text one by one
//Check the hash values of current window of text and pattern. If the hash values match then only  check for characters one by one
	  if (p == t){
		  for (j = 0; j < M; j++){           /* Check for characters one by one */
			  if (txt[i + j] != pat[j]) {
				  break;
				}
			}

		  // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]

		  if (j == M)  cout << "Pattern found at index " << i << endl;
		}

	  // Calculate hash value for next window of text: Remove leading digit, add trailing digit
	  if (i < N - M){
		  t = (d * (t - txt[i] * h) + txt[i + M]) % q;

		  // We might get negative value of t, converting it to positive
		  if (t < 0)  t = (t + q);
		}
	}
}

int main () {
  char txt[] = "GEEKS FOR GEEKS";
  char pat[] = "GEEK";
  // we mod to avoid overflowing of value but we should take as big q as possible to avoid the collison
  int q = INT_MAX;
  search (pat, txt, q);
  return 0;
}
/*
Time Complexity:O (n + m), but its worst - case time is
O (nm).
Limitations of Rabin - Karp Algorithm
Spurious Hit:When the hash value of the pattern matches with the hash value of a window of the text 
but the window is not the actual pattern then it is called a spurious hit.Spurious hit increases the
time complexity of the algorithm. In order to minimize spurious hit, we use good hash function.It greatly reduces the spurious hit.

  