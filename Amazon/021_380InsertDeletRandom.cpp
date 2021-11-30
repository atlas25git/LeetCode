class RandomizedSet {

    private:
    vector<int> list;
    unordered_map<int,int> mp;

public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        //list = vector<int>();
        //mp =  unordered_map<int,int>();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.count(val))return false;
        list.push_back(val);
        mp.insert({val,list.size()-1});
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp.count(val))
        {
            int ind = mp[val];
            int swp = list.back();
            //basically here we put list's last element
            //by the element to be deleted
            //Now we delete the end of the vector
            //And update that swapped element's index in the map.
            //erase element from map
            list[ind] = swp;
            list.erase(list.end()-1);
            mp[swp] = ind;
            mp.erase(val);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int num = rand()%list.size();
        return list[num];
    }
};
