struct Node{
  int key,value;
  Node* next,*prev;
    
    Node(int key,int value)
    {
        this->key = key;
        this->value = value;
    }
};

//Thought procesS::
//1. DLL struct consisting of key, value;
//2. Init fn, we'll add at head and delete from tail.
//3. Get-> if exists in map->delete->addToHead->return value/
//         else return -1;
//4. addToHead -> Insert node right in front of the start.
//5. delete -> make it's corresponding neighbours skip the node.
//6. Put-> if key exists -> replace value, delete, addTohead.
//          elif: create node, and entry in map.
//              if: capacity not reached: addToHead;
//              else: delete tail->prev, remove tail->prev form the map.
//                    add to head.

class LRUCache {
private:
    unordered_map<int,Node*> mp;
    int count;
    int capacity;
    Node* head,*tail;
    
public:
    
    LRUCache(int capacity) {
       this->capacity = capacity;
       this->count = 0;
        head = new Node(0,0);
        tail = new Node(0,0);
        
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.count(key))
        {
            deleteNode(mp[key]);
            addToHead(mp[key]);
            return mp[key]->value;
        }
        else return -1;
    }
    
    void deleteNode(Node* node)
    {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        // delete(node);
    }
    
    void addToHead(Node* node)
    {
        head->next->prev = node;
        node->next = head->next;
        node->prev = head;
        head->next = node;
    }
    
    void put(int key, int value) {
        if(mp.count(key))
        {
            mp[key]->value = value;
            deleteNode(mp[key]);
            addToHead(mp[key]);                
        }
        else{
            mp[key] = new Node(key,value);
            if(count<capacity)
            {
                count++;
                addToHead(mp[key]);
            }
            else{
                mp.erase(tail->prev->key);
                deleteNode(tail->prev);
                addToHead(mp[key]);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */