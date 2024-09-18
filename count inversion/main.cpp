/*https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 
has three inversions (2, 1), (4, 1), (4, 3).
Example 2:

Input: N = 5
arr[] = {2, 3, 4, 5, 6}
Output: 0
Explanation: As the sequence is already 
sorted so there is no inversion count.
Example 3:

Input: N = 3, arr[] = {10, 10, 10}
Output: 0
Explanation: As all the elements of array 
are same, so there is no inversion count.
*/
/*
count=0;
for(int i=0;i<n-10;i--){
    for(int j=i+1;j<n;j++){
        if(a[i]<a[j]){
            count++;
        }
    }
}*/
// C++ program for Merge Sort 
#include <iostream> 
using namespace std; 

// Merges two subarrays of array[]. 
// First subarray is arr[begin..mid] 
// Second subarray is arr[mid+1..end] 
void merge(int array[], int const left, int const mid, int const right){ 
	auto const subArrayOne = mid - left + 1; 
	auto const subArrayTwo = right - mid; 
	// Create temp arrays 
	auto *leftArray = new int[subArrayOne], 
		*rightArray = new int[subArrayTwo]; 

	// Copy data to temp arrays leftArray[] and rightArray[] 
	for (auto i = 0; i < subArrayOne; i++) 
		leftArray[i] = array[left + i]; 
	for (auto j = 0; j < subArrayTwo; j++) 
		rightArray[j] = array[mid + 1 + j]; 
	auto indexOfSubArrayOne = 0, 	// Initial index of first sub-array 
		indexOfSubArrayTwo = 0; 	// Initial index of second sub-array 
	int indexOfMergedArray = left; 	// Initial index of merged array 
	// Merge the temp arrays back into array[left..right] 
	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) { 
		if (leftArray[indexOfSubArrayOne] <=rightArray[indexOfSubArrayTwo]) 	{ 
			array[indexOfMergedArray] = leftArray[indexOfSubArrayOne]; 
			indexOfSubArrayOne++; 
		} 
		else{ 
			array[indexOfMergedArray]=rightArray[indexOfSubArrayTwo]; 
			ans+=(mid-left+1);
			indexOfSubArrayTwo++; 
		} 
		indexOfMergedArray++; 
	} 
	// Copy the remaining elements of left[], if there are any 
	while (indexOfSubArrayOne < subArrayOne) { 
		array[indexOfMergedArray] =leftArray[indexOfSubArrayOne]; 
		indexOfSubArrayOne++; 
		indexOfMergedArray++; 
	} 
	// Copy the remaining elements of right[], if there are any 
	while (indexOfSubArrayTwo < subArrayTwo) { 
		array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo]; 
		indexOfSubArrayTwo++; 
		indexOfMergedArray++; 
	} 
} 

// begin is for left index and end is right index of the sub-array of arr to be sorted */ 
void mergeSort(int array[], int const begin, int const end) { 
	if (begin >= end) 	return; 
	auto mid = begin + (end - begin) / 2; 
	mergeSort(array, begin, mid); 
	mergeSort(array, mid + 1, end); 
	merge(array, begin, mid, end); 
} 

int main() { 
	int arr[] = { 12, 11, 13, 5, 6, 7 }; 
	auto arr_size = sizeof(arr) / sizeof(arr[0]); 
	mergeSort(arr, 0, arr_size - 1); 
	cout<<ans;
	return 0; 
} 
/*
                         3 2 4 1
            5 3 2                     4 1
    5 3               2         4              1
    now merge
[3 5]  [2]->
*/
