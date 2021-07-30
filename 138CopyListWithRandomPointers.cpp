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