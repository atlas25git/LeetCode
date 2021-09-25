class Solution {

    public:
    bool flag=true;

    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)return head;
        
        ListNode* prev = head;
        ListNode* nxt = head->next; 
        ListNode* curr = swapPairs(head->next->next);
        
        prev->next = nxt->next;
        nxt->next = prev;
        prev->next = curr;
        
        return nxt;
    }
};