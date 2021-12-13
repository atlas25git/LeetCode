class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode* subRes = reverseList(head->next);
        //linking the tail to remaining part
        head->next->next = head;
        head->next = NULL;
        return subRes;
    }
};