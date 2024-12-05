/*     3 3 2 2 2 5 1
two 3s , three 2s, one 5, one 1
23+32+15+11="23321511"
*/
string countAndSay(int n) {
       if(n == 1)  return "1";
        string s = countAndSay(n-1);
        int i = 0, j = 0;
        string r;
        while(i < s.size()) {
            j = i+1;
            while(j < s.size() && s[j] == s[i])  ++j;
            string ct = to_string(j-i);
            r += ct + s[i];
            i = j;
        }
        return r; 
    }