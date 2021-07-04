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
    
    int mps(TreeNode* root, int& res)
    {
        if(!root)return 0;
        //Avoiding negatives
        int l = max(mps(root->left,res),0);
        int r = max(mps(root->right,res),0);
        
        res = max(res,l + r + root->val);
        return max(l+root->val , r+root->val);
    }
    
    
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        mps(root,res);
        return res;
    }
};