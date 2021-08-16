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
public:
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        //there are two condn only, if the given node has right child
        //then it'll be it's inorder successor, else the root node of 
        //last greater order

        if(!root || !p)return 0;
        
        TreeNode* parent = root;
        while(p->val != root->val)
        {
            if(p->val<root->val)
            {
                parent = root;
                root = root->left;
            }
            else root=root->right;
        }

        if(p->right)
        {
            p=p->right;
            while(p->left)p=p->left;
            return p;
        }
        //no right child
        else return parent->val>p->val?parent:0;
    }
};

class Solution {
public:
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        // write your code here
        if(!root || !p)return 0;
        TreeNode* parent = root;
        while(root->val != p->val)
        {
            if(p->val < root->val)
            {
                parent = root;
                root = root->left;
            }
            else root = root->right;
        }

        if(p->right)
            {
                p=p->right;
                while(p->left)p=p->left;
            
            return p;
            }
    else return parent->val>p->val?parent:0;
    }
};