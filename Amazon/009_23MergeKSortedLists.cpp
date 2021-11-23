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

#define data val
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())return nullptr;
        
        while(lists.size()>1)
        {
            lists.push_back(mtl(lists[0],lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }
    
    ListNode* mtl(ListNode* l1, ListNode* l2)
    {
        ListNode* head;
        if(!l1)return l2;
        if(!l2)return l1;
        
        if(l1->data<=l2->data)
                head = l1,
                l1->next = mtl(l1->next,l2);
        if(l1->data>l2->data)
                head = l2,
                l2->next = mtl(l1,l2->next);
        return head;
    }
};