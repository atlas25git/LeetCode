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
    vector<int> in;
    vector<int> pre;
    int k=0;
    
    TreeNode* util(int& k,int s,int e)
    {   
        if(k==in.size())return NULL;
        if(s>e)return NULL;
        TreeNode* root = new TreeNode(pre[k++]);
        if(s == e)return root;
        
        int ind = find(in.begin(),in.begin()+e,root->val) - in.begin();
        
        root->left = util(k,s,ind-1);
        root->right = util(k,ind+1,e);
        
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        inorder.swap(in);
        preorder.swap(pre);
        
        return util(k,0,in.size());
    }
};