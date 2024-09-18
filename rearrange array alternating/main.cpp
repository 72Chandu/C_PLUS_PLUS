/*The problem can be easily solved if O(n) extra space is allowed.
We can store the positive values and negative values in two separate data structures.
We will start filling the original array with alternating negative and positive values in the same order 
in which it appears in the original array.

The idea is to process the array from left to right. While processing, find the first out-of-place element in the remaining unprocessed array.
An element is out of place if it is negative and at odd index (0-based index), or if it is positive and at even index (0-based index). 
Once we find an out-of-place element, we find the first element after it with an opposite sign.
We right rotate the subarray between these two elements (including these two).

arr[] = { -5, -2, 5, 2, 4, 7, 1, 8, 0, -8 }

First iteration: 

{ -5, -2, 5, 2, 4, 7, 1, 8, 0, -8 } , -2 appears on odd index position and is out of place.
We will look for the first element that appears with an opposite sign
{ -5, -2, 5, 2, 4, 7, 1, 8, 0, -8 } => perform rotation of subarray between this two elements
{ -5, 5, -2, 2, 4, 7, 1, 8, 0, -8 }
Second iteration: 

{ -5, 5, -2, 2, 4, 7, 1, 8, 0, -8 } , 4 is out of place.
{ -5, 5, -2, 2, 4, 7, 1, 8, 0, -8 } => -8 is of different sign 
{ -5, 5, -2, 2, -8, 4, 7, 1, 8, 0 } => after performing right rotation between 4 to -8
resultant array arr[] = { -5, 5, -2, 2, -8, 4, 7, 1, 8, 0 }
*/
#include <bits/stdc++.h>
using namespace std;

// Utility function to right rotate all elements between [outofplace, cur]
void rightrotate(int arr[], int n, int outofplace, int cur){
	char tmp = arr[cur];
	for (int i = cur; i > outofplace; i--)
		arr[i] = arr[i - 1];
	arr[outofplace] = tmp;
}
void rearrange(int arr[], int n){
	int outofplace = -1;
	for (int index = 0; index < n; index++) {
		if (outofplace >= 0) {
			if (((arr[index] >= 0) && (arr[outofplace] < 0))|| ((arr[index] < 0)&& (arr[outofplace] >= 0))) {rightrotate(arr, n, outofplace, index);
				// the new out-of-place entry is now 2 steps ahead
				if (index - outofplace >= 2) outofplace = outofplace + 2;
				else outofplace = -1;
			}
		}
		// if no entry has been flagged out-of-place
		if (outofplace == -1) {
			// check if current entry is out-of-place
			if (((arr[index] >= 0) && (!(index & 0x01)))|| ((arr[index] < 0) && (index & 0x01))) {
				outofplace = index;
			}
		}
	}
}

void printArray(int arr[], int n){
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main(){

	int arr[] = { -5, -2, 5, 2, 4, 7, 1, 8, 0, -8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Given array is \n";
	printArray(arr, n);
	rearrange(arr, n);
	cout << "Rearranged array is \n";
	printArray(arr, n);

	return 0;
}
