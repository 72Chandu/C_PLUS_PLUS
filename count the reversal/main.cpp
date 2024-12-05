//https://www.geeksforgeeks.org/problems/count-the-reversals0401/1
int countRev (string S){
    int n=S.length();
    if (n%2!=0) return -1; // If the length of the string is odd, it can't be balanced
    stack<char>stk;
    for (int i=0;i<n;++i){ // If the current character is a closing bracket and the stack is not empty and the top of the stack is an opening bracket, then pop the stack
        if(S[i]=='}'&&!stk.empty() && stk.top()=='{') stk.pop();
        else stk.push(S[i]);// Otherwise, push the current character into the stack
    }
    int unbalanced = stk.size();
    int opening = 0;
    while (!stk.empty() && stk.top() == '{') {
        stk.pop();
        opening++;
    }
    return (unbalanced / 2 + opening % 2); // The number of reversals required would be half the unbalanced brackets plus half the opening brackets

}