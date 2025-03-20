//https://www.geeksforgeeks.org/problems/find-duplicates-in-an-array/1?page=1&sortBy=submissions
vector<int> findDuplicates(vector<int>& arr) {  //tle
        vector<int>ans;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                if(arr[i]==arr[j]){
                    ans.push_back(arr[i]);
                }
            }
        }
        return ans;
    }
//m-2
vector<int> findDuplicates(vector<int>& arr) {
        vector<int>ans;
        unordered_map<int,int>m;
        for(auto i:arr){
            m[i]++;
        }
        for(auto& i:m){
            if(i.second >=2)  ans.push_back(i.first);
        }
        return ans;
    }
