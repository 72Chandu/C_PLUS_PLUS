//https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
         if (points.empty()) return 0;
    
    // Sort balloons based on their end coordinate
    sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });
    
    int arrows = 1;  // At least one arrow is needed
    int prev_end = points[0][1];
    
    for (const auto& balloon : points) {
        if (balloon[0] > prev_end) {  // Need a new arrow
            arrows++;
            prev_end = balloon[1];
        }
    }
    
    return arrows;
    }
};
/*
Before sorting:
[[10,16], [2,8], [1,6], [7,12]]
After sorting:
[[1,6], [2,8], [7,12], [10,16]]

Now, we process the balloons in this order.
Step 2: Initialize
Start with 1 arrow and set prev_end = 6 (end of the first balloon).
Step 3: Process Each Balloon
Balloon [2,8]
Since 2 ≤ 6, this balloon overlaps with the previous one.
No new arrow needed.

Balloon [7,12]
7 > 6 (start is beyond prev_end), so we need a new arrow.
Increase arrows = 2.
Update prev_end = 12.

Balloon [10,16]
Since 10 ≤ 12, this balloon overlaps with the previous one.
No new arrow needed.
Total arrows required = 2.
*/
