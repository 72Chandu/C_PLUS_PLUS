#include<bits/stdc++.h>
using namespace std;
bool ispalindrome(string s){
	int l = s.length();
	int j;
	for(int i = 0, j = l - 1; i <= j; i++, j--){
		if(s[i] != s[j])
			return false;
	}
	return true;
}
int main(){
	string s;
	cin>>s;
	int cnt = 0;
	int flag = 0;
	while(s.length()>0){
		if(ispalindrome(s)){// if string becomes palindrome then break
			flag = 1;
			break;
		}
		else{
		cnt++;
		s.erase(s.begin() + s.length() - 1);// erase the last element of the string
		}
	}
	if(flag)// print the number of insertion at front
		cout << cnt;
}/*Time complexity: O(n2)
Auxiliary Space: O(1)
Start checking the string each time if it is a palindrome and if not, then delete the last character and check 
again. When the string gets reduced to either a palindrome or an empty string then the number of characters deleted 
from the end till now will be the answer as those characters could have been inserted at the beginning of the original 
string in the order which will make the string a palindrome.*/

//2 pointer
int addMinChar(string s) {
        int n = str1.length();
        int i= 0;
        int j = n - 1;
        int res = 0;
        while (i<j) {  
            if (s[i] == s[j]) {  
                i++;  
                j--;  
            }
            else {
                res++;  // Increment the count of characters to be added
                i= 0;  // Reset the start pointer to the beginning of the string
                j= n - res - 1;  // Reset the end pointer to the end of the string with a reduced number of characters
            }
        }
        return res;  // Return the count of characters to be added
    }
//kmp
/*or string = AACECAAAA
Concatenated String = AACECAAAA$AAAACECAA 
              original string<-|->reverse of original string
LPS array will be {0, 1, 0, 0, 0, 1, 2, 2, 2,  0, 1, 2, 2, 2, 3, 4, 5, 6, 7}
t->o(n)  s->o(n)
*/
vector<int> computeLPSArray(string str){
	int M = str.length();
	vector<int> lps(M);
	int len = 0;
	lps[0] = 0; // lps[0] is always 0
	int i = 1;
	while (i < M){ // the loop calculates lps[i] for i = 1 to M-1
		if (str[i] == str[len]){
			len++;
			lps[i] = len;
			i++;
		}
		else // (str[i] != str[len])
		{
			// This is tricky. Consider the example. AAACAAAA and i = 7. The idea is similar to search step.
			if (len != 0){
				len = lps[len-1];
				// Also, note that we do not increment i here
			}
			else // if (len == 0)
			{
				lps[i] = 0;
				i++;
			}
		}
	}
	return lps;
}

// Method returns minimum character to be added at front to make string palindrome
int getMinCharToAddedToMakeStringPalin(string str){
	string revStr = str;
	reverse(revStr.begin(), revStr.end());
	string concat = str + "$" + revStr;        // Get concatenation of string, special character and reverse string
	vector<int> lps = computeLPSArray(concat);   // Get concatenation of string, special character and reverse string
	return (str.length() - lps.back()); 	// By subtracting last entry of lps vector from string length, we will get our result
}
int main(){
	string str = "AACECAAAA";
	cout << getMinCharToAddedToMakeStringPalin(str);
	return 0;
}

