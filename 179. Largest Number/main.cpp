/*
https://leetcode.com/problems/largest-number/description/ 
*/
static bool mycomp(string a,string b){ // 30 , 3 = 3>30 case to become larger no  330>303
        string t1=a+b;
        string t2=b+a;
        return t1>t2;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>s;
        for(auto i:nums){
            s.push_back(to_string(i));
        }
        sort(s.begin(),s.end(),mycomp);
        if(s[0]=="0") return "0";
        string ans="";
        for(auto i:s){
            ans+=i;
        }
        return ans;
    }