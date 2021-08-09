/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //simple reverese the list and do the normal addn
        return Reverse(Add(Reverse(l1),Reverse(l2)));
    }
    
    ListNode* Reverse(ListNode* head)
    {
       if(!head)return head;
        if(!head->next) return head;
        
        ListNode* node = Reverse(head->next);
        if(head->next)
            head->next->next = head;
        head->next = NULL;
        
        return node;
    }
    
    ListNode* Add(ListNode* l1, ListNode* l2)
    {
        if(!l1)return l2;
        if(!l2)return l1;
        
        ListNode* head = new ListNode(-1);
        ListNode* result = head;
        int carry = 0;
        
        while(l1 || l2)
        {
            int l1val = l1 == NULL?0:l1->val;
            int l2val = l2 == NULL?0:l2->val;
            
            int sum = l1val + l2val + carry;
            carry = sum/10;
            result->next = new ListNode(sum%10);
            result = result->next;
            
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
            
        }
        
        if(carry>0)result->next = new ListNode(carry);
        return head->next;
    }
};