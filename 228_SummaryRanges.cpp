class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>res;
        int n=nums.size();
        if(n==0) return res;
        int start=nums[0];
        for(int i=1;i<=n;i++){
            if(i==n || nums[i]!=nums[i-1]+1){//ensuring that the number is not increasing  by 1
                if(start==nums[i-1]){
                    res.push_back(to_string(start));
                }else{
                    res.push_back(to_string(start)+"->"+to_string(nums[i-1]));
                }
                if(i<n) start=nums[i];//updating start
            }
        }
        return res;
    }
};
/*      0  1  2  3  4  5
nums = [0, 1, 2, 4, 5, 7]
start=nums[0]=0
i
1  (1 == 0 + 1)
2  (2 == 1 + 1)
3  (4 != 2 + 1) ->current range ends at nums[2].start & nums[2] are different,add "0->2" to result
start=4
4  (5 == 4 + 1),
5  (7 != 5 + 1) ->current range ends at nums[4].start & nums[4] are different, add "4->5" to result.
start=7
6  start (7) equals nums[5] (7), add "7" to result
*/
