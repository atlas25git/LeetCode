class RandomizedSet {
public:
    unordered_map<int,int> indMap;
    vector<int> list;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(indMap.count(val))
            return false;
        else{
            indMap[val] = list.size();
            list.push_back(val);
            return true;
        }
    }
    
    bool remove(int val) {
        if(!indMap.count(val))
            return false;
        else{
            int ind = indMap[val];
            list[ind] = list.back();
            indMap[list[ind]] = ind;
            indMap.erase(val);
            list.erase(--list.end());
            return true;
        }
    }
    
    int getRandom() {
        
        return list[rand()%list.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */