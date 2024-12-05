/*
abcdeabcd
prefix-> a,ab,abc,abcd,abcde,abcdea,abcdeab,abcdeabc 
sufix-> d,cd,bcd,abcd,eabcd,deabcd,cdeabcd,bcdeabcd
longest prefix and sufix is -> abcd lenght 4

t= o(n^2)-> to genrate orefix and suffix and o(n)-> for compare = o(n^3)

int longestProperPrefixSuffix(const string& str) {//o(n^2)
    int n = str.length();
    int length = 0;
    for (int i = 0; i < n - 1; ++i) {
        string prefix = str.substr(0, i + 1);
        string suffix = str.substr(n - i - 1, i + 1);
        if (prefix == suffix) {
            length = i + 1;
        }
    }
    return length;
}
int main() {
    string str = "abab";
    int length = longestProperPrefixSuffix(str);
    cout << "Length of the longest proper prefix which is also a proper suffix: " << length << endl; // Output: 1
}

example 1: kmp algo
 0 1 2 3 4 5 6 7 8 
 a b c d e a b c d         lps[]={0,0,0,0,0,0,0,0,0};
 j i 
 a==b -> no i++, a==c-> no i++, a==d-> no i++, a==e-> no i++, a==e-> no i++, a==a-> yes lps[5]=1, i++,j++ (a     a)
--->                                                                                                          pre   suf
a b c d e a b c d         lps[]={0,0,0,0,0,1,0,0,0};
  j         i 
  b==b -> yes lsp[6]=2, i++, j++ (ab.....ab)
                                  pre   suf
--->  
 a b c d e a b c d         lps[]={0,0,0,0,0,1,2,0,0};
     j         i 
     c==c -> yes lsp[7]=3 i++, j++ (abc....abc)
                                    pre     suf
--->
a b c d e a b c d         lps[]={0,0,0,0,0,1,2,0,0};
      j         i 
     d==d -> yes lsp[8]=4 i++, j++ (abcd....abcd)
                                    pre     suf   
answer is lsp[n-1]=lsp[8]=4 

example 2
0 1 2 3 4 5 6 7 8 
a b c d e a b a b         lps[]={0,0,0,0,0,0,0,0,0};
j i 
a==b-> no i++, a==c-> no i++, a==d-> no i++, a==e-> no i++, a==a-> yes i++, j++ lsp[5]=1;(a...a)
--->
 a b c d e a b a b         lps[]={0,0,0,0,0,1,0,0,0};
   j         i 
b==b -> yes i++, j++ lsp[6]=2 (ab...ab)
---> 
  a b c d e a b a b         lps[]={0,0,0,0,0,1,2,0,0};
      j         i 
c==a -> no now the i is at n-1 move j to initial
--->
 a b c d e a b a b         lps[]={0,0,0,0,0,1,2,0,0};
 j             i 
 a==a-> yes i++,j++ lsp[7]=1 
---> 
 a b c d e a b a b         lps[]={0,0,0,0,0,1,2,1,0};
   j             i 
 b==b-> yes i++,j++ lsp[8]=2   lps[]={0,0,0,0,0,1,2,1,2};
   
*/
int lsp(string s){
    vector<int>lp(s.size(),0);//initialising the lp vector with 0
    int j=0, i=1;
    while(i<s.size()){
        if(s[i]==s[j]){
            lp[i]=j+1;
            i++;
            j++;
        }
        else{
            if(j!=0)  j=lp[j-1];
            else i++;
        }
    }
    return lp.back();
}