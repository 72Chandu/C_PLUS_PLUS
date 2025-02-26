//https://leetcode.com/problems/happy-number/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>s; // for avoiding infinite loop
        while(n!=1 && s.find(n)==s.end()){
            s.insert(n);
            int sum = 0;
            while (n > 0) {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            n=sum;
        }
        if(n==1) return true;
        else return false;
    }
};
