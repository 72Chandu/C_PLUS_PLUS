	//https://www.geeksforgeeks.org/problems/value-equal-to-index-value1330/1
	vector<int> valueEqualToIndex(int arr[], int n) {
	    vector<int>v;
	    for (int i = 0; i < n; i++) { // Corrected loop starting index
        if (arr[i] == i + 1) { // Adjusted comparison to match index (arrays are 0-indexed)
            v.push_back(i + 1); // Push the index + 1 (since arrays are 0-indexed)
        } 
    }
	    return v;
	}