//https://leetcode.com/problems/new-21-game/description/
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double>p(n+1,0.0); //p[i]=probability of geting score = i
        p[0]=1; //score=0
        for(int i=1;i<=n;i++){
            for(int j=1; j<=maxPts;j++){ //j->card
                if(i-j>=0 && i-j<k) p[i]=p[i]+p[i-j]/maxPts;
            }
        }
        return accumulate(begin(p)+k, end(p),0.0); //sum from p[k] to p[n]
    }
};
/*
n = 21, k = 17, maxPts = 10

p(21)+p(20)+p(19)+p(18)+p(17) stop

p(21)=p(16)*p(5) + p(15)*p(6) + .... +p(21-10)*p(10) we can not start from p(17) because the game will stop
p(21)=p(16)*p(5) + p(15)*p(6) + .... +p(11)*p(10)
p(21)=p(16)*1/10 + p(15)*1/10 + .... +p(11)*1/10
p(21)=p(k-1)*1/10 + p(k-2)*1/10 + .... +p(k-10)*1/10
*/
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double>p(n+1,0.0); //p[i]=probability of geting score = i
        p[0]=1; //score=0
        double currProbSum=(k==0)?0:1;
        for(int i=1;i<=n;i++){
            p[i]=currProbSum/maxPts;
            if(i<k) currProbSum+=p[i];
            if(i-maxPts>=0 && i-maxPts<k) currProbSum-=p[i-maxPts];
        }
        return accumulate(begin(p)+k, end(p),0.0); //sum from p[k] to p[n]
    }
};
/*
n = 21, k = 17, maxPts = 10
p(16)=p(15)*1/10 + p(14)*1/10 + ....p(16-10)*1/10
     =p(15)*1/10 + p(14)*1/10 + ....p(6)*1/10
p(17)=p(16)*1/10 + p(15)*1/10 + ....p(17-10)*1/10
     =p(16)*1/10 + p(15)*1/10 + ....p(7)*1/10
p(18)=p(16)*1/10 + p(15)*1/10 + ....p(18-10)*1/10  -> p(18)->do  ot need p(17)
     =p(16)*1/10 + p(15)*1/10 + ....p(8)*1/10

p(17)=p(16)-p(6)*1/10
p(17)=p(16)-p(17-10)*1/10
p(i)=p(16)-p(i-maxPts)*1/maxPts
*/
