//https://leetcode.com/problems/basic-calculator/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        int num=0, res=0, sign=1, n=s.length();
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                num=num*10+(s[i]-'0'); // number bnao
            }else if(s[i]=='+'){
                res+=num*sign;
                num=0;
                sign=1;
            }else if(s[i]=='-'){
                res+=num*sign;
                num=0;
                sign=-1;
            }else if(s[i]=='('){
                st.push(res);
                st.push(sign);
                res=0;
                num=0;
                sign=1;
            }else if(s[i]==')'){
                res+=num*sign; //bracket ke ander ka res 
                num=0;
                int st_sign=st.top();st.pop();
                int last_res=st.top();st.pop();
                res*=st_sign;
                res+=last_res;
            }
        }
        res+=num*sign;
        return res;
    }
};
/*
digit -> nuber banao
+-> res me add karo num=0,s=1
--> res me add karo num=0,s=-1
(-> stack me res ko push ksro then sine ko push karo, r=0,s=1
)-> res me add kar do (close bracket ke ander ka sara solved hona chiye.res=res+num*sine), num=0  res=res*s.top s.pop till s is empty

0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17
1 0 - ( 4 + 5 + 2 )  -  3  +  (  6  +  8  )

num=0, res=0 sine=1

i=0 -> n=n*10 + (s[i]-'0)=0*10+1=1
i=1 -> n=n*10 + (s[i]-'0)=1*10+1=10
i=2 '-' -> means before it number is form 
n=10  r=r+n*s=0+10*1=10 s=-1

i=3 '(' -> now store previous res in statc=[10,-1]
r=0 n=0 s=1

i=4 '4 -> n=n*10 + (s[i]-'0)=0*10+4=4
i=5 '+' -> means before it number is form 
         n=4  r=r+n*s=0+4*1=4
         n=0 r=4 s=1
i=6 '5 -> n=n*10 + (s[i]-'0)=0*10+5=5
i=7 '+' -> means before it number is form 
         n=5  r=r+n*s=4+5*1=9
         n=0 r=9 s=1
i=8 '2' -> n=n*10 + (s[i]-'0)=0*10+2=2
i=9 ')' -> r=r+n*s=9+2*1=11
           n=0 r=11 s=1
           r=r*s.top(); s.pop(); r=11*-1=-11
           r=r*s.top(); s.pop(); r=-11+10=-1
i=10 '-' -> means before it number is form 
          r=r+n*s=-1+0*1=-1    s=-1
i=11 '3' -> n=n*10 + (s[i]-'0)=0*10+3=3
i=12 '+' -> means before it number is form 
          r=r+n*s=-1+3*-1=-4
          n=0 r=-4 s=1
i=13 '(' -> now store previous res in statc=[-4,1]
r=0 n=0 s=1  

i=14 '6 -> n=n*10 + (s[i]-'0)=0*10+6=6
i=15 '+' -> means before it number is form 
         n=6  r=r+n*s=0+6*1=6
         n=0 r=6 s=1
i=16 '8' -> n=n*10 + (s[i]-'0)=0*10+8=8
i=9 ')' -> r=r+n*s=6+8*1=14
           n=0 r=14 s=1
           r=r*s.top(); s.pop(); r=14*1=14
           r=r*s.top(); s.pop(); r=14-4=10
*/
