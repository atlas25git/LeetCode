class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(!head || !head->next)return head;
        ListNode* prev = head;
        ListNode* tail = head->next;
        ListNode* sR = reverseList(head->next);
        
        tail->next = prev;
        prev->next = NULL;
        
        return sR;
    }
};