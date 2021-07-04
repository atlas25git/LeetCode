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
    int mdH(TreeNode* root)
    {   //Base case
        //1.Dealing with null case could be avoided since if would do that implictly
        //if(!root)return 0;
        
        //Leaf Node
        if(!root->left && !root->right) return 1;
        //Assumption step here we presume that l and r are the respective 
        //heights of the sub trees under root
        int l=INT_MAX,r=INT_MAX;
        if(root->left)
            l=mdH(root->left);
        if(root->right)
            r=mdH(root->right);
        
        //res = min(res,min(l,r));
        //returning the value root's height(+1)
        return min(l,r)+1;
    }
    
    int minDepth(TreeNode* root) {
        
        if(!root)return 0;
        int res=INT_MAX;
        int res1 = mdH(root);
        return res1;
        
    }
};