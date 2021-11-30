class Solution {
public:
    int maxArea(vector<int>& ht) {
        // cout<<ht.size();
        int ans = INT_MIN;
        int i=0,j=ht.size()-1;
        while(i<j)
        {   
            int df = j-i;
            if(ht[i] == ht[j])
                ans = max(ans,df*ht[i++]),j--;
            else if(ht[i] < ht[j])
                ans = max(ans,df*ht[i++]);
            else ans = max(ans,df*ht[j--]);
        }
        return ans;
    }
};