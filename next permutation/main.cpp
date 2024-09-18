//https://leetcode.com/problems/next-permutation/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==1) return;//no next permutation is possible
        set<pair<int,int>> s;//store pairs of integers (element, index)
        bool found=false; //check if a next permutation is found
// Insert the last element of the vector along with its index into the set
        s.insert({nums[nums.size()-1],nums.size()-1});
        for(int i=nums.size()-2;i>=0;i--){//Iterate over the vector from 2ndlast ele to the 1st
            int current_no=nums[i];
// Pair to store the smallest element greater than current element and its index
            pair<int,int> z={INT_MAX,INT_MAX};
            bool flag=false;
            for(auto it:s){//find the next greater element
                if(it.first>current_no){
                    flag=true;
                    z=min(z,it);//Update the smallest next greater element found so fa
                }
            }
            if(flag){// If a next greater element is found
                found=true;
                s.erase(z);// Remove the next greater element from the set
                s.insert({current_no,i});//Insert the curr ele and its ind into the set
                nums[i]=z.first;//Update the curr ele with the next greater element
// Rearrange the elements after the current index in ascending order
                int j=i+1;
                for(auto it:s){
                    nums[j]=it.first;
                    j++;
                }
                // Break the loop as next permutation is found
                break;
            }
// If no next greater element is found, insert the current element into the set
            s.insert({nums[i],i});
        }
 // If no next permutation is found, sort the vector in ascending order
        if(!found){
            return sort(nums.begin(),nums.end());
        }
// The same functionality can be achieved using the standard library function std::next_permutation(nums.begin(),nums.end());
    }
};
/*n = 4   nums = [1, 2, 3, 4].
As n is not equal to 1, the function proceeds.
Setup:

A set s is initialized to store elements along with their indices. Initially, s = {(4, 3)}.
Iterative Process:

Starting from the second-to-last element (i = 2), the function iterates backward.
At i = 2, the current element is 3.
It searches for the smallest element greater than 3 in the set s. It finds (4, 3) which is greater than 3, so it updates z to (4, 3).
Since a next greater element is found, it updates nums[2] with z.first, so nums[2] becomes 4.
The set s is now updated to contain s = {(3, 2)}.
The function rearranges elements after index 2 in ascending order, so nums becomes [1, 2, 4, 3].
The loop breaks since the next permutation is found.
Post-processing:

Since a next permutation is found, the function returns [1, 2, 4, 3].*/

/*methode 2
123-> permutation-> 132,213,231,321,123-> next permutation of 123 is 132
321-> it is is decending order so, no permutation is just greater then 321 so, the lowest permutation
for this is 123 as answer

2 3 9 8 5 2 
    -------  -> this is in decending order no elements is just greater then this
2 3 9 8 5 2
  i-> swap 3 with just greater then 3 from right side 
2 5 9 8 3 2
    ------- -> convert in decending order
2 5 2 3 8 9 -> this is next permutaion of 2 3 9 8 5 2
    
*/
void nextpermutation(vector<int>&v){
    int n=v.size();
    int index=n-2;//last elements is alwase in sorted order so we start from 2nd last elements
    while(index> 0 && v[index]>=v[index+1]){//showing that the elements are in decending order
        index--;
    }//2 5 9 8 3 2 index is at 5
    if(index==-1){//means all elements are is in decending order
        reverse(v.begin(), v.end());
        return;
    }
    int hi=n-1;
    while(hi>=0 && v[hi]<=v[index]){
        hi--;
    }
    swap(v[index],v[hi]);
    index++;//now index is at 9
    hi=n-1;
    while(index<hi){
        swap(v[index], v[hi]);
        index++;
        hi--;
    }
    
}



