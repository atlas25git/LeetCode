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
    int fill(TreeNode* root,int& dia)
    {
        if(!root)return 0;
        
        int l = fill(root->left,dia);
        int r = fill(root->right,dia);
        
        //since here the question has defined the diameter
        //as the edge length rather than node.
        dia = max(dia,l+r);
        
        
        return 1 + max(r,l);
    }
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=INT_MIN;
        fill(root,dia);
        return dia;
    }
};