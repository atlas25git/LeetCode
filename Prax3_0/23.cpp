class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        while(lists.size()>1)
        {
            auto x = *(--lists.end());
            auto y = *(----lists.end());
            lists.pop_back();
            lists.pop_back(); 
            lists.push_back(merge_x(x,y));
            // lists.back();
        }
        
        return lists.size()?lists.front():0;
    }
    
    ListNode* merge_x(ListNode* y, ListNode* x)
    {   
        ListNode* finalH;
        if(!x)
            return y;
        if(!y)
            return x;
        if(x->val<y->val)
            finalH = x,
            finalH->next = merge_x(x->next,y);
        else
            finalH = y,
            finalH->next = merge_x(x,y->next);
        
        return finalH;
    }
};