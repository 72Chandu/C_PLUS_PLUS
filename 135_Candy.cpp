//https://leetcode.com/problems/candy/description/?envType=problem-list-v2&envId=array
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>candies(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                candies[i]=candies[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                candies[i]=max(candies[i],candies[i+1]+1);
            }
        }
        int count=0;
        for(int c:candies){
            count+=c;
        }
        return count;
    }
};
/*         0  1  2  3  4
ratings = [1, 3, 4, 5, 2]
           0  1  2  3  4
candies = [1, 1, 1, 1, 1].
Pass 1: Left to Right
3 > 1, increase candies[1] to candies[0] + 1. candies = [1, 2, 1, 1, 1]
4 > 3, increase candies[2] to candies[1] + 1. candies = [1, 2, 3, 1, 1]
5 > 4, increase candies[3] to candies[2] + 1. candies = [1, 2, 3, 4, 1]
2 < 5, no change. candies = [1, 2, 3, 4, 1]
           0  1  2  3  4
candies = [1, 2, 3, 4, 1]
Pass 2: Right to Left
5 > 2,candies[3] > candies[4].candies[3] is already 4, so no change.candies = [1, 2, 3, 4, 1]
4 < 5, no change.candies = [1, 2, 3, 4, 1]
3 < 4, no change.candies = [1, 2, 3, 4, 1]
1 < 3, no change.candies = [1, 2, 3, 4, 1]
*/
