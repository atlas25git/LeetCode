//intuition: Here we basically use a DLL, and from the head node, next is most recently
//used page
//From tail the prev is lest used page
//We define two fn addToHead -> adds a new node next to head
//delete -> deletes a node particularly given it's address, Null safe access ensured as there'll be 
//head and tail nodes present at any given operation state/
//Now we maintain a map, of key vs address, to access pages in constant access time
//If the page size is greater than given limit, we delete a page from last, accessing it using
//tail->prev, and thus adding the new node to the head
//also in update routine, we delete the node from list and bring it at head.


struct Node{
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int key,int value)
    {
        this->key=key;
        this->value=value;
        next=prev=NULL;
    }
};



class LRUCache {
public:
    private:
    static unordered_map<int,Node*> mp;
    static int capacity,count;
    static Node* head;
    static Node* tail;
    
    public:
    //Constructor for initializing the cache capacity with the given value.
    
    LRUCache(int cap)
    {
        unordered_map<int,Node*> temp;
        mp=temp;
        capacity=cap;
        count=0;
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        head->prev=NULL;
        tail->next=NULL;
        tail->prev=head;
    }
    
    static int get(int key)
    {
        if(mp.count(key)>0)
        {
            Node* temp=mp[key];
            int res =temp->value;
            deleteNode(temp);
            addToHead(temp);
            return res;
        }
        return -1;
        
    }
    
    static void addToHead(Node* node)
    {
        node->next=head->next;
        node->next->prev=node;
        node->prev=head;
        head->next=node;
    }
    static  void deleteNode(Node* node){
        node->next->prev=node->prev;
        node->prev->next=node->next;
    }
    
    static void put(int key, int value)
    {
        if(mp.count(key)>0)
        {
            Node* temp = mp[key];
            temp->value = value;
            deleteNode(temp);
            addToHead(temp);
        }
        else{
            Node* temp=new Node(key,value);
            mp[key]=temp;
            if(count<capacity)
            {
                count++;
                addToHead(temp);
            }
            else{
                mp.erase(tail->prev->key);
                deleteNode(tail->prev);
                addToHead(temp);
            }
        }
    }
};

unordered_map<int, Node *> temp;
int LRUCache::capacity = 0;
Node *LRUCache::head = new Node(0, 0);
Node *LRUCache::tail = new Node(0, 0);
int LRUCache::count = 0;
unordered_map<int, Node *> LRUCache::mp = temp;


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


struct Node{
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int key,int value)
    {
        this->key=key;
        this->value=value;
        next=prev=NULL;
    }
};



class LRUCache {
public:
    private:
    static unordered_map<int,Node*> mp;
    static int capacity,count;
    static Node* head;
    static Node* tail;
    
    public:
    //Constructor for initializing the cache capacity with the given value.
    
    LRUCache(int cap)
    {
        unordered_map<int,Node*> temp;
        mp=temp;
        capacity=cap;
        count=0;
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        head->prev=NULL;
        tail->next=NULL;
        tail->prev=head;
    }
    
    static int get(int key)
    {
        if(mp.count(key)>0)
        {
            Node* temp=mp[key];
            int res =temp->value;
            deleteNode(temp);
            addToHead(temp);
            return res;
        }
        return -1;
        
    }
    
    static void addToHead(Node* node)
    {
        node->next=head->next;
        node->next->prev=node;
        node->prev=head;
        head->next=node;
    }
    static  void deleteNode(Node* node){
        node->next->prev=node->prev;
        node->prev->next=node->next;
    }
    
    static void put(int key, int value)
    {
        if(mp.count(key)>0)
        {
            Node* temp = mp[key];
            temp->value = value;
            deleteNode(temp);
            addToHead(temp);
        }
        else{
            Node* temp=new Node(key,value);
            mp[key]=temp;
            if(count<capacity)
            {
                count++;
                addToHead(temp);
            }
            else{
                mp.erase(tail->prev->key);
                deleteNode(tail->prev);
                addToHead(temp);
            }
        }
    }
};

unordered_map<int, Node *> temp;
int LRUCache::capacity = 0;
Node *LRUCache::head = new Node(0, 0);
Node *LRUCache::tail = new Node(0, 0);
int LRUCache::count = 0;
unordered_map<int, Node *> LRUCache::mp = temp;


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */