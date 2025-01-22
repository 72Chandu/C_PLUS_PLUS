class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n=s.size();
        vector<int>ans(n,n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(s[j]==c){
                    ans[i]=min(ans[i],abs(j-i));
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(s[j]==c){
                    ans[i]=min(ans[i],abs(j-i));
                }
            }
        }
        return ans;
    }
};
