class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = l1,*q = l2;
        ListNode* res = new ListNode(0);
        ListNode* head = res;
        int sum=0,x=0,y=0,carry=0;
        while(p || q || carry>0)
        {
            x = p?p->val:0;
            y = q?q->val:0;
            sum = x+y+carry;
            carry = sum/10;
            res->next = new ListNode(sum%10);
            res = res->next;
            if(p)p=p->next;
            if(q)q=q->next;
        }
        return head->next;
    }
};