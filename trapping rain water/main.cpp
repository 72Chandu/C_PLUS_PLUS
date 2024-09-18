/*https://www.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1
Input: N = 6 arr[] = {3,0,0,2,0,4} Output:10  (3+3+1+3)~0,0,2,0 
      3,0,0,2,0,4
maxl= 3 3 3 3 3 4 -> maimum ele in left of current element
maxr= 4 4 4 4 4 4 -> maximum ele in right of current element
min(l,r)=3 3 3 3 3 4
original=3 0 0 2 0 4
subtract=0 3 3 1 3 0--> 3+3+1+3=10

Input: N = 4 arr[] = {7,4,0,9} Output: 10
Explanation:Water trapped by above 
block of height 4 is 3 units and above 
block of height 0 is 7 units. So, the 
total unit of water trapped is 10 units.
Example 3: Input: N = 3 arr[] = {6,9,9} Output: 0
Explanation: No water will be trapped.*/

long long trappingWater(int arr[], int n){
    // Declare arrays to store maximum height to the left and right of each element
    long long mxl[n], mxr[n];
    
    // Initialize the maximum height to the left array
    mxl[0] = arr[0];
    
    // Loop through the array to calculate the maximum height to the left of each element
    for(int i = 1; i < n; i++){
        // Store the maximum of previous maximum and current element's height
        mxl[i] = max(mxl[i - 1], (long long)arr[i]); // Casting arr[i] to long long to avoid comparison issues
    }
    
    // Initialize the maximum height to the right array
    mxr[n - 1] = arr[n - 1];
    
    // Loop through the array to calculate the maximum height to the right of each element
    for(int i = n - 2; i >= 0; i--){
        // Store the maximum of previous maximum and current element's height
        mxr[i] = max(mxr[i + 1], (long long)arr[i]); // Corrected variable name and casting
    }
    
    // Declare an array to store water trapped at each element
    long long water[n];
    
    // Loop through the array to calculate the water trapped at each element
    for(int i = 0; i < n; i++){
        // Calculate the water trapped at the current element as the difference between minimum of maximum height to left and right and current element's height
        water[i] = min(mxl[i], mxr[i]) - (long long)arr[i]; // Casting arr[i] to long long
    }
    
    // Initialize a variable to store the total trapped water
    long long sum = 0;
    
    // Loop through the array to calculate the total trapped water
    for(int i = 0; i < n; i++){
        // Add the water trapped at each element to the total sum
        sum = sum + water[i];
    }
    
    // Return the total trapped water
    return sum; // Added semicolon at the end
}
