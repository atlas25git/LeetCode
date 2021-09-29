/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int,int> mp;
    int mc=0;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int> res;
        for(auto &e :mp)
                if(e.second == mc)
                    res.push_back(e.first);
        return res;
    }
    
    int dfs(TreeNode* root)
    {
        if(!root)return 0;
        int s = dfs(root->left) + dfs(root->right) + root->val;
        mc = max(mc,++mp[s]);
        return s;
    }
};