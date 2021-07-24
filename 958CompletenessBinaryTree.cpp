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
    bool isCompleteTree(TreeNode* root) {
        if(!root)return true;
        queue<TreeNode*> q;
        q.push(root);
        bool nullSeen = false;
        while(!q.empty())
        {
            TreeNode* t = q.front();
            q.pop();
            if(t==NULL)
                nullSeen = true;
            else
            {
                if(nullSeen)return false;
            }
            if(t)
            q.push(t->left);
            if(t)
            q.push(t->right);
        }
        return true;
    }
};


class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(!root)return true;
        queue<TreeNode*> q;
        q.push(root);
        bool fl = false;
        while(!q.empty())
        {
            TreeNode* t = q.front();
            q.pop();
            if(!t)fl=true;
            else if(fl) return false;
            if(t)
            q.push(t->left);
            if(t)
            q.push(t->right);
        }
        return true;
    }
};