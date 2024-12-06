 int search(vector<int>&v, int tar) {
    int lo = 0;
    int hi = v.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (v[mid] == tar) return mid;
        if (v[lo] <= v[mid]) { // Left half is sorted
            if (tar >= v[lo] && tar < v[mid]) hi = mid - 1;
            else lo = mid + 1;
        } else { // Right half is sorted
            if (tar > v[mid] && tar <= v[hi]) lo = mid + 1;
            else hi = mid - 1;
        }
    }
    return -1;
    }