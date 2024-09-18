/*Input: arr[] = {3, 1, 2, 2, 1, 2, 3, 3}, k = 4     Output: {2, 3}
Explanation: Here n/k is 8/4 = 2, therefore 2 appears 3 times  > 2 and 3 appears 3 times > 2
Input: arr[] = {9, 8, 7, 9, 2, 9, 7}, k = 3     Output: {9}
Explanation: Here n/k is 7/3 = 2, therefore 9 appears 3 times >2.

brute force-
for(int i=0;i<n;i++){
    int count=0;
    for(int j=0;j<n;j++){
        if(arr[j]==arr[i]){
            count++;
        }
    }
    if(count>n/k) return arr[i];
}
-----------------------------
hasing
int x=n/k;
unordered_map<int,int>freq;// ele, val
for(int i=0;i<n;i++){
    freq[a[i]]++;//ele , count
}
for(auto i:freq){
    if(i.second>x){
        cout<<freq.first;
    }
}
-----------------------------
int countOccurence(int arr[], int n, int k) {
    int x = n / k;
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
    int count = 0; // Counter for elements that occur more than n/k times
    for (auto i : freq) {
        if (i.second > x) {
            count++; // Increment the count of elements that occur more than n/k times
        }
    }
    return count; // Return the count of such elements
}
-----------------------------
 Moore’s Voting Algorithm:
The idea is to apply Moore’s Voting algorithm, as there can be at max k – 1 elements present
in the array which appears more than n/k times so their will be k – 1 candidates.When we 
encounter an element which is one of our candidates then increment the count else decrement the count.

Illustration:

Consider k = 4, n = 9 
Given array: 3 1 2 2 2 1 4 3 3 

i = 0 temp[] has one element {3} with count 1
i = 1 temp[] has two elements {3, 1} with counts 1 and 1 respectively
i = 2 temp[] has three elements, {3, 1, 2} with counts as 1, 1 and 1 respectively.
i = 3 temp[] has three elements, {3, 1, 2} with counts as 1, 1 and 2 respectively.
i = 4 temp[] has three elements, {3, 1, 2} with counts as 1, 1 and 3 respectively.
i = 5 temp[] has three elements, {3, 1, 2 with counts as 1, 2 and 3 respectively.
i = 6 temp[] has two elements, {1, 2} with counts as 1 and 2 respectively.
i = 7 temp[] has three elements, {3, 1, 2} with counts as 1, 1 and 2 respectively.
i = 8 temp[] has three elements, {3, 1, 2} with counts as 2, 1 and 2 respectively.

struct eleCount {
	int e; // Element
	int c; // Count
};
void moreThanNdK(int arr[], int n, int k){
	if (k < 2)	return;// k must be greater than 1 to get some output

/*Step 1: Create a temporary array (contains element and count) of size k-1.Initialize count of all
	elements as 0 */
	struct eleCount temp[k - 1];
	for (int i = 0; i < k - 1; i++)
		temp[i].c = 0;

	/* Step 2: Process all elements of input array */
	for (int i = 0; i < n; i++) {
		int j;

		/* If arr[i] is already present in the element count array, then increment its count*/
		for (j = 0; j < k - 1; j++) {
			if (temp[j].e == arr[i]) {
				temp[j].c += 1;
				break;
			}
		}

		/* If arr[i] is not present in temp[] */
		if (j == k - 1) {
			int l;

/* If there is position available in temp[], then place arr[i] in the first available position and
set count as 1*/
			for (l = 0; l < k - 1; l++) {
				if (temp[l].c == 0) {
					temp[l].e = arr[i];
					temp[l].c = 1;
					break;
				}
			}
			/* If all the position in the temp[] are filled, then decrease count of every element by 1 */
			if (l == k - 1)
				for (l = 0; l < k - 1; l++)
					temp[l].c -= 1;
		}
	}

	/*Step 3: Check actual counts of * potential candidates in temp[]*/
	for (int i = 0; i < k - 1; i++) {
		// Calculate actual count of elements
		int ac = 0; // actual count
		for (int j = 0; j < n; j++)
			if (arr[j] == temp[i].e)
				ac++;

		// If actual count is more than n/k,  then print it
		if (ac > n / k)
			cout << "Number:" << temp[i].e
				<< " Count:" << ac << endl;
	}
}


*/