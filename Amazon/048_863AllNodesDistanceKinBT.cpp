/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//HashMap based approach:
//We basically store all the distances on the path containing our target in a decreasing manner.
//Basically we store relative distances of nodes on the path to target so that they could be used,
//when looking for the other side of tree.
class Solution {
    unordered_map<TreeNode*,int> mp;
    vector<int> res;
    public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        fillDis(root,target);
        fill(root,target,k,mp[root]);
        return res;
    }
    
    int fillDis(TreeNode* root,TreeNode* target)
    {   
        if(!root)return -1;
        if(root == target){
            mp[root] = 0;
            return 0;
        }
        int lt = fillDis(root->left,target);
        if(lt!=-1)
        {
            mp[root] = lt+1;
            return lt+1;
        }
        
        int rt = fillDis(root->right,target);
        if(rt!=-1)
        {
            mp[root] = rt+1;
            return rt+1;
        }
        return -1;
    }
    
    void fill(TreeNode* root,TreeNode* target,int k,int len)
    {
        if(!root)return;
        if(mp.count(root))
            len = mp[root];
        if(len == k)res.push_back(root->val);
        fill(root->left,target,k,len+1);
        fill(root->right,target,k,len+1);        
    }
};