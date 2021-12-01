class Solution {
public:
    /**
     * @param root: a TreeNode
     * @return: a list of integer
     */
     vector<int> res;
     int c;
    vector<int> boundaryOfBinaryTree(TreeNode * root) {
        int cr=-1;
        c=0;
        if(!root)return res;
        res.push_back(root->val);
        
        fill_left(root->left,0,cr);
        fill_leaves(root);
        cr=-1;
        fill_right(root->right,0,cr);
        // cout<<c<<endl;
        reverse(res.begin()+res.size()-c,res.end());
        return res;
    }

    void fill_left(TreeNode* root,int cr,int& lvl)
    {
        if(!root)return;
        if(!root->left && !root->right){lvl=INT_MAX;return;}
        // cout<<root->val<<" "<<cr<<" "<<lvl<<"\n";
        if(lvl<cr)
            {res.push_back(root->val),
            lvl++;}

        fill_left(root->left,cr+1,lvl);
        fill_left(root->right,cr+1,lvl);
    }

    void fill_right(TreeNode* root,int cr,int& lvl)
    {
        if(!root)return;
        if(!root->left && !root->right){lvl=INT_MAX;return;}
        if(lvl<cr)
           { res.push_back(root->val),c++,
            lvl++;}
        fill_right(root->right,cr+1,lvl);
        fill_right(root->left,cr+1,lvl);
    }

    void fill_leaves(TreeNode* root)
    {   
        if(!root)return;
        fill_leaves(root->left);
        if(!root->left && !root->right)
            res.push_back(root->val);
        fill_leaves(root->right);
    }
};