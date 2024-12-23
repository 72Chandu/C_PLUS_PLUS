//https://leetcode.com/problems/insert-delete-getrandom-o1/?envType=study-plan-v2&envId=top-interview-150
class RandomizedSet {
public:
    unordered_map<int, int>m;
    vector<int>v;
    RandomizedSet() {}
    bool insert(int val) {
        if(m.find(val)!=m.end()){
            return false;
        } 
        else{
            v.push_back(val);
            m[val]=v.size()-1;
            return true;
        } 
    }
    bool remove(int val) {
        if(m.find(val)==m.end()){
            return false;
        }
        int idx=m[val];//index to remove
        int lastele=v.back();
        
        // Swap the value to remove with the last value
        v[idx]=lastele;
        m[lastele]=idx;

        v.pop_back();
        m.erase(val);
        return true;
    }
    int getRandom() {
        int randIdx=rand()%v.size();
        return v[randIdx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
