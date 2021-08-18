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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        unordered_map<TreeNode*,TreeNode*> map;
        queue<TreeNode*> q;
        vector<TreeNode*> leaves;
            
        q.push(root);
        map[root]= NULL;
        
        while(!q.empty())
        {
            int sz = q.size();
            leaves.clear();
            for(int i=0;i<sz;i++)
            {
                TreeNode* t = q.front();
                q.pop();
                leaves.push_back(t);
                
                if(t->left)
                    map[t->left] = t,
                    q.push(t->left);
                
                if(t->right)
                    map[t->right] = t,
                    q.push(t->right);
            }
        }
        
        unordered_set<TreeNode*> par;
        
        while(leaves.size()>1)
        {
            for(auto x:leaves)
            {
                if(par.find(map[x]) == par.end())
                        par.insert(map[x]);
            }
            
            leaves.clear();
            leaves = vector<TreeNode*>(par.begin(),par.end());
            par.clear();
        }
        return leaves[0];
    }
};