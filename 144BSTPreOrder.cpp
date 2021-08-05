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
    
    void fill(vector<int>& ans, TreeNode* root)
    {
        if(!root)return;
        
        ans.push_back(root->val);
        fill(ans,root->left);
        fill(ans,root->right);
        
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        fill(ans,root);
        return ans;

    }
};

//Iterative:
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        //iterative soln:
        vector<int> res;
        if(!root)return res;
        
        stack<TreeNode*> s;
        s.push(root);
        
        while(!s.empty())
        {
            TreeNode* node  = s.top();
            s.pop();
            res.push_back(node->val);
            if(node->right)s.push(node->right);
            if(node->left)s.push(node->left);
        }
        return res;
    }
};