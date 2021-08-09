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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> v;
    if(!root)return v;
    stack<TreeNode*> cl,nl;
    cl.push(root);
    bool lToR = true;
    vector<int> temp; 

    while(!cl.empty())
    {
        
        TreeNode* curr = cl.top();
        cl.pop();
        temp.push_back(curr->val);
        
            if(lToR)
            {
                if(curr->left)nl.push(curr->left);
                if(curr->right)nl.push(curr->right);
            }
            else {
                if(curr->right)nl.push(curr->right);
                if(curr->left)nl.push(curr->left);
                 }
            
        
        
        if(cl.empty())
        {   v.push_back(temp);
            temp.clear();
         
            lToR = !lToR;
            swap(cl,nl);
        }
        
    }
    
    return v;
    }
};