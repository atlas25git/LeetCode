class Solution {
public:
    multiset<int> s;
    
    void inOrder(TreeNode* root)
    {
        if(!root)return;
        inOrder(root->left);
        s.insert(root->val);
        inOrder(root->right);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        // vector<int> res;
        inOrder(root1);
        inOrder(root2);
        return vector<int>(s.begin(),s.end());
    }
};