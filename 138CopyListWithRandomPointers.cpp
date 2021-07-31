/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return head;
        Node* t = head;
        
        //adding aux nodes
        while(t)
        {
            Node* aux = new Node(t->val);
            aux->next = t->next;
            t->next = aux;
            
            t = aux->next;
        }
        
        //populating the random pointers
        Node* ans = head->next;
        t = head;
        while(t)
        {
            if(t->random)
                t->next->random = t->random->next;
            else
                t->next->random = NULL;
            
            t= t->next->next;
        }
        
        //removing the orginal links
        t=head;
        //seperating the two lists
        Node* nextOG;
        while(t)
        {
            nextOG =  t->next->next; // holds pointer to next node of og list
            
            if(nextOG)//end not reached for the OG LIst
                t->next->next = nextOG->next;//next pointer of aux list 
            else
                t->next->next = NULL;
            
            //fixing the og list's node
            t->next = nextOG;
            t = nextOG;
        }
        
        return ans;
        
    }
};


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //base case
        if(!head)return head;
        Node* t = head;
        while(t)
        {
            Node* aux = new Node(t->val);
            aux->next = t->next;
            t->next = aux;
            
            t = aux->next;
        }
        
        //fixing the random ptrs
        t = head;
        while(t)
        {
            if(t->random)
                t->next->random = t->random->next;//shifted by one node
            else
                t->next->random = NULL;
            
            t = t->next->next;
        }
        
        //seperating the nodes
        Node* nxtOG;
        t=head;
        Node* ans = head->next;
        
        while(t)
        {
            nxtOG = t->next->next;
            
            if(nxtOG)//not the end
                t->next->next = nxtOG->next;
            else
                t->next->next = NULL;
            
            //fixing the og
            t->next = nxtOG;
            t = nxtOG;
        }
        
        return ans;
    }
};


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return head;
        Node* t = head;
        while(t)
        {
            Node* n = new Node(t->val);
            n->next = t->next;
            t->next = n;
            
            //moving fwd the iterator 
            t=n->next;
        }
        
        t = head;
        Node* head2 = head->next;
        while(t)
        {
            if(t->random== NULL)
                    t->next->random = NULL;
            else 
                t->next->random = t->random->next;//since decoy linked list is one shifted
            
             t = t->next->next;
        }
        
        t = head;
        while(t)
        {
            head = t->next->next;
            
            if(head)
                t->next->next = head->next;
            else
                t->next->next = NULL;
            
            t->next = head;
            t=head;
        }
        return head2;
    }
};