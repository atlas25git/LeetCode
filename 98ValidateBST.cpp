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
#define ll long long

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root)return true;
        ll mn = INT_MIN,mx = INT_MAX;
        return isBST(root,mn,mx);
    }
    
    bool isBST(TreeNode* root,ll mn, ll mx)
    {
        if(!root)return true;
        // if(!root->left && !root->right) return true;
        if(root->val > mx ||  root->val < mn)return false;
        
        bool l = isBST(root->left,mn,(ll)root->val-1);
        bool r = isBST(root->right,(ll)root->val+1,mx);
        
        return l&&r;
    }
};