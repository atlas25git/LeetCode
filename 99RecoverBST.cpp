class Solution {
    TreeNode* fe = NULL,*se=NULL,*pe;
public:
    void recoverTree(TreeNode* root) {
        traverse(root);
        swap(fe->val,se->val);
    }
    
    void traverse(TreeNode* root)
    {
        if(!root)return;
        traverse(root->left);
        //Basically we're doing an inorder traversal
        //and here we check nodes which are out of order
        //we store their addresses and swap them.
        if(!fe && (!pe || pe->val >= root->val))
                fe = pe;
        if(fe && pe->val >= root->val)
            se = root;
        pe = root;
        traverse(root->right);
    }
};