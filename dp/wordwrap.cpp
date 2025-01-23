/*https://www.geeksforgeeks.org/problems/word-wrap1646/1
a=[3,2,2,5] k=6 3->gfg 2->go 2->cp 5->coder

g f g        -> cost=3*3=9
- - - -  - -
g o   c p          ->1*1=1 cost(onle last space is in count)
- - - - - -
c o d e r    -> ignore last space so, the cost=0
- - - - - -
        total cost=9+1+0=10

a=[3,2,2,5] k=6 3->gfg 2->go 2->cp 5->coder

g f g    g o-> 0 cost
- - - -  - -
c p          -> 4*4=16 cost
- - - -  - -
c o d e r    -> ignore last space of last line so, the cost=0
- - - - - -
 total cost= 0+0+16=16
Example 2:   Input: nums = {3,2,2}, k = 4  Output: 5
Explanation: Given a line can have 4  characters,
Line number 1: From word no. 1 to 1
Line number 2: From word no. 2 to 2
Line number 3: From word no. 3 to 3
Same explaination as above total cost = (4 - 3)2 + (4 - 2)2 = 5.

Your Task: minimise the cost
Expected Time Complexity: O(n2)
Expected Space Complexity: O(n)
 
*/

