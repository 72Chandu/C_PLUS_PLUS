/*Input: N = 7 a[] = {2,6,1,9,4,5,3} Output: 6
Explanation: The consecutive numbers here are 1, 2, 3, 4, 5, 6. These 6 numbers form the longest consecutive
subsquence.
Example 2: Input: N = 7 a[] = {1,9,3,10,4,20,2} Output: 4
Explanation:1, 2, 3, 4 is the longest consecutive subsequence.
int lcse=1;
for(int i=0;i<n;i++){
    int x=a[i];
    int count=1;
    while(lenearSearch(a,x+1)){
        x=x+1;
        count++;
    }
   lcse=max(lcse,count)
}
a=1 1 1 2 2 2 3 3 4 100 100 101 101 102
  |->
 countCurr=0->1->2->3->4
 lastSmaller=INT_MIN->1->2->3
 largest=1->2->3



sort(a,a+n);
int countCurr=0;
int lastSmaller=INT_MIN;
int largest=1;
for(int i=0;i<n;i++){
    if(a[i]-1==lastSmaller){
        countCurr++;
        lastSmaller=a[i];
    }
    else if(a[i]!=lastSmaller){
        countCurr=1;
        lastSmaller=a[i];
    }
    longest=max(longest,countCurr);
}
return longest;

*/
int findLongestConseqSubseq(int arr[], int n){
    // If there are no elements in the array, return 0
    if(n == 0) return 0;
    
    // Initialize variable to store the length of the longest consecutive subsequence found so far
    int longest = 1;
    
    // Declare an unordered set to store unique elements from the array
    unordered_set<int> st;
    
    // Insert elements from the array into the set
    for(int i = 0; i < n; i++){
        st.insert(arr[i]);
    }
    
    // Iterate through each element in the set
    for(auto i:st){
        // Check if the previous element is not present in the set
        if(st.find(i - 1) == st.end()){
            // Initialize variables to track the length and starting element of the current subsequence
            int count = 1;
            int first_ele = i;
            
            // Increment the starting element and count as long as the next consecutive element is found
            while(st.find(first_ele + 1) != st.end()){
                first_ele++;
                count++;
            }
            
            // Update the longest consecutive subsequence length if needed
            longest = max(longest, count);
        }
    }
    
    // Return the length of the longest consecutive subsequence
    return longest;
}

