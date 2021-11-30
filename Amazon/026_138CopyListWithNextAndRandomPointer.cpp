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