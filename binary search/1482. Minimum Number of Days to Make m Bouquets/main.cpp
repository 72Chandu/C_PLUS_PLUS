/*
https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

Example 1:

Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
You need 3 bouquets, each containing 1 flower.
After 3 days, the garden looks like this: [x, _, x, _, x], where x means the flower has bloomed.
Now, you can pick three bloomed flowers, one at a time, and make 3 bouquets.
The answer is 3 days.
Example 2:

Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
You need 3 bouquets, but each bouquet requires 2 adjacent flowers.
The total number of flowers required is m * k = 6, but the garden only has 5 flowers. So, it’s impossible to make 3 bouquets with 2 adjacent flowers each.
The answer is -1.


Given Input:
bloomDay = [7, 7, 7, 7, 12, 7, 7]
m = 2 (You need 2 bouquets)
k = 3 (Each bouquet must consist of 3 adjacent flowers)
Understanding the Process:
Day 7:

On day 7, flowers at positions bloomDay[i] <= 7 will bloom. Let’s look at the bloomDay array and mark which flowers have bloomed:

bloomDay = [7, 7, 7, 7, 12, 7, 7]
On day 7: [x, x, x, x, _, x, x] 
Here, x indicates that a flower has bloomed, and _ indicates that the flower has not bloomed yet (like the one at index 4, which will bloom on day 12).

Now, we need to check if it’s possible to make m = 2 bouquets with k = 3 adjacent flowers.

First, check the first 4 flowers: [x, x, x, x]. We can only take the first 3 adjacent flowers from positions 0, 1, and 2 to make 1 bouquet.
The next group of flowers after this is [x, x] (at positions 5 and 6), but these are only 2 adjacent flowers, which is not enough to make a bouquet of size k = 3.
So, on day 7, you can only make 1 bouquet, but you need 2 bouquets. Therefore, day 7 is not the answer.

Day 12:

On day 12, all flowers have bloomed. The garden now looks like:

bloomDay = [7, 7, 7, 7, 12, 7, 7]
On day 12: [x, x, x, x, x, x, x]
Let’s check if we can now make m = 2 bouquets with k = 3 adjacent flowers.

From the first 4 flowers: [x, x, x, x], we can take the first 3 flowers (positions 0, 1, and 2) and make 1 bouquet.
From the last 3 flowers: [x, x, x] (at positions 4, 5, and 6), we can take all 3 and make 1 more bouquet.
So, on day 12, we can make the required 2 bouquets. Therefore, the minimum number of days you need to wait is 12 days.

Why is the Answer 12 Days?
On day 7, not enough flowers are blooming in the right adjacent order to make the required 2 bouquets.
On day 12, all flowers are in bloom, and there are enough adjacent flowers (two groups of 3 adjacent flowers) to make the 2 bouquets.
Thus, the minimum number of days required is 12.

*/
bool kya_bouque_banega(vector<int>& bloomDay,int day, long long m, long long k){
        long long flower=0;
        long long bouquests=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                flower++;
                if(flower==k){
                    bouquests++;
                    flower=0;
                }
            }else{
                flower=0;
            }
            if(bouquests >=m) return true;
        }
        return false;
    }
    int minimumDays(vector<int>& bloomDay, long long m, long long k){
        long long n=bloomDay.size();
        long long mk=m*k;
        if(mk>n) return -1;
        long long lo=*min_element(bloomDay.begin(),bloomDay.end());
        long long hi=*max_element(bloomDay.begin(),bloomDay.end());
        while(lo<hi){
            long long mid=lo+(hi-lo)/2;
            if(kya_bouque_banega(bloomDay,mid,m,k)) hi=mid;
            else lo=mid+1;
        }
        return lo;
    }
    int minDays(vector<int>& bloomDay, long long m, long long k) {
        long long result= minimumDays(bloomDay, m,k);
        if(result!=-1) return result;
        else return -1;
    }