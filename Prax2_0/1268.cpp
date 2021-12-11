//TC:: O(nlogn + mlogn) n->len of array
//      m->len of search string.
//SC:: O(n) -> sorting + O(m) -> for output.

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        sort(products.begin(),products.end());
        string prefix;
        int n = products.size();
        int explored = 0;
        for(auto ch : searchWord)
        {   
            res.push_back({});
            prefix += ch;
            int start = lower_bound(products.begin() + explored,products.end(),prefix) - products.begin();
            explored = start;
            
            for(int i = start;i<min(n,start+3) && !products[i].compare(0,prefix.size(),prefix);i++)
                res.back().push_back(products[i]);
        }
        return res;
    }
};