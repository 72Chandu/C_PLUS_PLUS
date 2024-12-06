/*
https://leetcode.com/problems/koko-eating-bananas/

Example 1:
Input: piles = [3, 6, 7, 11], h = 8
Goal: Find the minimum speed k such that Koko can finish eating all the bananas within 8 hours.

Step 1: Initialize Binary Search
lo = 1 hi = 11  mid =(1 + 11) / 2 = 6
Pile 3: ceil(3 / 6) = 1 hour
Pile 6: ceil(6 / 6) = 1 hour
Pile 7: ceil(7 / 6) = 2 hours
Pile 11: ceil(11 / 6) = 2 hours
Total hours: 1 + 1 + 2 + 2 = 6 hours
Since 6≤ 8  So, try a smaller  right = mid = 6.

Step 3: Update Binary Search Range
Now lo= 1 and hi= 6.   mid =(1 + 6) / 2 = 3
Pile 3: ceil(3 / 3) = 1 hour
Pile 6: ceil(6 / 3) = 2 hours
Pile 7: ceil(7 / 3) = 3 hours
Pile 11: ceil(11 / 3) = 4 hours
Total hours: 1 + 2 + 3 + 4 = 10 hours
10 hours > 8 hours,  So lo = mid + 1 = 4.

Step 5: Update Binary Search Range
Now lo = 4 and hi = 6.   mid =(4 + 6) / 2 = 5
Pile 3: ceil(3 / 5) = 1 hour
Pile 6: ceil(6 / 5) = 2 hours
Pile 7: ceil(7 / 5) = 2 hours
Pile 11: ceil(11 / 5) = 3 hours
Total hours: 1 + 2 + 2 + 3 = 8 hours
Since 8 hours = 8 hours So  right = mid = 5.

Step 7: Update Binary Search Range
Now lo= 4 and hi= 5. mid =(4 + 5) / 2 = 4
Pile 3: ceil(3 / 4) = 1 hour
Pile 6: ceil(6 / 4) = 2 hours
Pile 7: ceil(7 / 4) = 2 hours
Pile 11: ceil(11 / 4) = 3 hours
Total hours: 1 + 2 + 2 + 3 = 8 hours
Since 8 hours = 8 hours, Koko can finish in time at speed k = 4. So, try a smaller speed by updating right = mid = 4.

Step 9: Conclusion
Now left = right = 4. The binary search ends, and the minimum speed k = 4 is returned.
Final Output:
The minimum speed k such that Koko can eat all the bananas in 8 hours is 4.
*/

int calculateHours(vector<int>& piles, int k){
        int h=0;
        for(int i:piles){
            h+=ceil((double)i/k);
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo=1;
        int hi=*max_element(piles.begin(),piles.end());
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            int hours=calculateHours(piles,mid);
            if(hours<=h) hi=mid;
            else lo=mid+1;
        }
        return lo;
    }
