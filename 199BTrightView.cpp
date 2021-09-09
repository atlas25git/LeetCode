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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root)return res;
        int cl=-1;
        fill(root,res,cl,0);
        return res;
    }
    
    void fill(TreeNode* root,vector<int>& res,int& cl,int lvl)
    {
        if(!root)return;
        if(lvl>cl)
            res.push_back(root->val),cl++;
        fill(root->right,res,cl,lvl+1);
        fill(root->left,res,cl,lvl+1);

    }
};