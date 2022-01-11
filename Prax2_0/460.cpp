class LFUCache {

    private:
    int lfu,size,capacity;
    
    //mappings
    //key->{val,freq}
    unordered_map<int,pair<int,int>> kv;
    //key->iterator
    unordered_map<int,list<int>::iterator> ki;
    //freq->keys
    unordered_map<int,list<int>> fk;
    
    void update(int key)
    {
        kv[key].second++;
        fk[kv[key].second].push_back(key);
        fk[kv[key].second-1].erase(ki[key]);
        ki[key] = --fk[kv[key].second].end();
        if(fk[lfu].empty())
            lfu++;
    }
    
    public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        // lfu = 1;
    }
    
    int get(int key) {
        if(kv.count(key))
        {
            update(key);
            return kv[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(capacity == 0)return;
        if(kv.count(key))
        {
            kv[key].first = value;
            update(key);
            return;
        }
        if(size == capacity)
        {
            int evict = fk[lfu].front();
            kv.erase(evict);
            fk[lfu].pop_front();
            ki.erase(evict);
        }
        else
        {
            size++;
        }
        
        kv[key] = {value,1};
        fk[1].push_back(key);
        ki[key] = --fk[1].end();
        lfu = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */