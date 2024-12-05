class Solution {
public:
    int calFreqDeff(const map<char,int>&freq){
        int maxfreq=INT_MIN;
        int minfreq=INT_MAX;
        for(auto i:freq){
            if(i.second >maxfreq){
                maxfreq=i.second;
            }
            if(i.second < minfreq){
                minfreq=i.second;
            }
        }
        return maxfreq-minfreq;
    }
    int beautySum(string s) { //aabcb
        int sum_of_freq=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            map<char,int>freq;
            for(int j=i;j<n;j++){
                //cout<<freq[s[j]]++ <<" ";//0 1 0 0 1 0 0 0 1 0 0 1 0 0 0
                freq[s[j]]++;
                sum_of_freq+=calFreqDeff(freq);

            }
        }
        return sum_of_freq;
    }
/* i=0
a a b c b
i
j   ans=0 
a a b c b
i j ans=1-1=0
a a b c b
i   j ans=2-1=1
a a b c b
i     j ans=2-1=1
a a b c b
i       j ans=2-1=1
== i=1
a a b c b
  i       
  j ans=1-1=0
a a b c b
  i j ans=1-1=0
a a b c b
  i   j ans=1-1=0
a a b c b
  i     j ans=2-1=1
== i=2
a a b c b
    i       
    j ans=1-1=0
a a b c b
    i j ans=1-1=0
a a b c b
    i j ans=1-1=0
a a b c b
    i   j ans=2-1=1

== i=3
a a b c b
      i       
      j ans=1-1=0
a a b c b
      i j ans=1-1=0

== i=4
a a b c b
        i       
        j ans=1-1=0
*/
};



