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
    unordered_map<TreeNode*,int> mp;
    vector<int> ans;
    TreeNode* target;
    int k;

    
    public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //Basically our approach here is to mark target's distance as zero
        //and iteratively traversing the tree while increasing the dis, as and when
        //it becomes equal to k we have a valid node.
        //for the nodes above target we store a mapping of them increasing distances from target.
        this->target = target;
        this->k = k;
        fillDis(root);
        fillAns(root,0);
        return ans;
    }
    
    int fillDis(TreeNode* root)
    {
        if(!root)return -1;
        if(root == target)return mp[root] = 0;
        
        int lt = fillDis(root->left);
        int rt = fillDis(root->right);
        
        if(lt!=-1)
            return mp[root] = lt+1;
        if(rt!=-1)
            return mp[root] = rt+1;
        return -1;        
    }
    
    void fillAns(TreeNode* root,int dis)
    {
        if(!root)return;
        //for the nodes interceeding the traversal after target
        //will start with depth count = 0;
        if(mp.count(root))dis=mp[root];
        if(dis == k)ans.push_back(root->val);
        fillAns(root->left,dis+1);
        fillAns(root->right,dis+1);
    }
};