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
    
    int fill(TreeNode* root,int& res,int l,int h)
    {
        if(!root)return 0;
        
        //inorder traversal
        if(root->val >= l && root->val <= h)
                res+=root->val;
        fill(root->left,res,l,h);
        fill(root->right,res,l,h);
        return 0;
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root)return 0;
        int res=0;
        fill(root,res,low,high);
        return res;
    }
};