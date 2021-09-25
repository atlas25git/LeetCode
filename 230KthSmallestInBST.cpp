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

#define data val
class Solution {
public:
    int ans = INT_MAX;
    vector<int> res;
    
    int find(TreeNode* root,int &k)
    {
        if(k==0)return ans;
        // if(!root->left)   
        k--;
        ans = min(ans,root->data);
        return find(root->left,k);
     
    }
    
    void inOrder(TreeNode* root)
    {
        if(!root)return;
        inOrder(root->left);
        res.push_back(root->val);
        inOrder(root->right);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        //k++;
        inOrder(root);
        //r(auto x: res)cout<<x<<" ";
        return res[k?k-1:0];
    }
};