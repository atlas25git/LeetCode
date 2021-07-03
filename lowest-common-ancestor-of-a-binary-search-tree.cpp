/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode* lcaUtil(TreeNode* root,int p,int q){
        if(root->val<=p && root->val>=q)return root;
        
        else if(root->val>p)return lcaUtil(root->left,p,q);
        else return lcaUtil(root->right,p,q);

    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //inorder traversal
        if(p->val>q->val)
        return lcaUtil(root,p->val,q->val);
        else return lcaUtil(root,q->val,p->val);
    }
};