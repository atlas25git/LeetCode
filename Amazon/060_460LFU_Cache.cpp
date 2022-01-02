class LFUCache {
private:
    //maps needed:
    //------------
    //key->val,freq
    //freq->keyS
    //key->iterator
    
    //variables:
    //----------
    //capacity: max size
    //size: capacity filled atm
    
    //key->val,freq
    unordered_map<int,pair<int,int>> kTOv;
    //freq->keys
    unordered_map<int,list<int>> freqBkt;
    //key->iteartor
    unordered_map<int,list<int>::iterator> kTOit;
    int capacity,size,lfu;
    void update(int key)
    {
        //value updated;
        //update freq
        //move the key to updated freq.
            //erase the old iterator from freq bkt intial/
            //add the new iterator to the freq+1 bkt.
        
        kTOv[key].second+=1;
        freqBkt[kTOv[key].second-1].erase(kTOit[key]);
        freqBkt[kTOv[key].second].push_back(key);
        kTOit[key] = --freqBkt[kTOv[key].second].end();
        
        if(freqBkt[lfu].size() == 0)lfu++;        
    }
    
public:
    
    LFUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
    }
    
    int get(int key) {
        if(kTOv.count(key))
        {   
            update(key);
            return kTOv[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(!capacity)return;
        if(kTOv.count(key))
        {
            kTOv[key].first = value;
            update(key);
        }
        else
        {
            if(size == capacity)
            {
                int evict = freqBkt[lfu].front();
                freqBkt[lfu].pop_front();
                kTOv.erase(evict);
                kTOit.erase(evict);
            }
            else{
                size++;
            }
            //1 being default freq atq
            kTOv[key] = {value,1};
            freqBkt[1].push_back(key);
            kTOit[key] = --freqBkt[1].end();
            //since everytime it's been added the lowest
            //freq bkt will have a member to be evicted.
            lfu = 1;
            
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */