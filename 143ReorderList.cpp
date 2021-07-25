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
    void reorderList(ListNode* head) {
        
        if(!head || !head->next)return;
        ListNode* x = head;
        ListNode* y = findMid(head);
        y= rev(y);
        merge(x,y);

    }
    
    ListNode* findMid(ListNode* head)
    {
        ListNode* pre = new ListNode(-1);
        pre->next = head;
        ListNode* cut = pre;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL)
        {
            cut  = cut->next;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if(fast != NULL)
        {
            cut = cut->next;
            slow = slow->next;
        }
        pre->next = NULL;
        cut->next = NULL;
        
        return slow;
        
    }
    
    ListNode* rev(ListNode* head)
    {
        if(head->next == NULL)return head;
        ListNode* node = rev(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return node;
    }
    
    void merge(ListNode* p1, ListNode* p2)
    {
        while(p2!=NULL)
        {
            ListNode* t1 = p1->next;
            ListNode* t2 = p2->next;
            
            p1->next = p2;
            p1=t1;
            
            p2->next = t1;
            p2 = t2;

        }
    }
};