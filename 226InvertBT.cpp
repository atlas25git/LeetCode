class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        iT(root);
        return root;
    }
    
    void iT(TreeNode* root)
    {
         if(!root)return;
        if(!root->left && !root->right)return;
        swap(root->left,root->right);
        iT(root->left);
        iT(root->right);
    }
};