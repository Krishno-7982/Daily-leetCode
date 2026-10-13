class RandomizedSet {
public:
    vector<int>v;
    unordered_map<int, int>mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val)){
            return false;
        }
        mp[val] = v.size();
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(!mp.count(val)){
            return false;
        }
        int idx = mp[val];
        int last = v.back();
        v[idx] = last;
        mp[last] = idx;
        v.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int idx = rand()%v.size();
        return v[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */