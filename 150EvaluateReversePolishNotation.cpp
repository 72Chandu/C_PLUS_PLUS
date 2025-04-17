//https://leetcode.com/problems/evaluate-reverse-polish-notation/description/?envType=study-plan-v2&envId=top-interview-150
// In RPN:
// You push numbers to the stack
// When you find an operator, you pop the top two elements, apply the operator, then push the result back.

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(string t: tokens){
            if(t=="+" || t=="-" || t=="*" || t=="/"){
                int b=s.top(); s.pop();
                int a=s.top();s.pop();
                int res;
                if(t=="+") res=a+b;
                else if(t=="-") res=a-b;
                else if(t=="*") res=a*b;
                else  res=a/b;
                s.push(res);
            }else{
                s.push(stoi(t));
            }
        }
        return s.top();
    }
};
