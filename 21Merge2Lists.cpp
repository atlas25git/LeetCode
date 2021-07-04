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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(!l1)return l2;
        if(!l2)return l1;
        ListNode *h1,*h2,*res;
        h1=l1,h2=l2;
        
        if(h1->val <= h2->val)
        {
            res=h1;
            res->next = mergeTwoLists(h1->next,h2);
            
        }
        else {
            res=h2;
            res->next= mergeTwoLists(h1,h2->next);
        }
        return res;
        
    }
};