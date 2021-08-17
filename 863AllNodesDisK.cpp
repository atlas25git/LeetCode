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
    
    void findDisKNodes(TreeNode* root,int K,vector<int>& dkn)
    {
        if(!root)
            return;
        if(!K)
            dkn.push_back(root->val);
        findDisKNodes(root->left,K-1,dkn);
        findDisKNodes(root->right,K-1,dkn);
    }
    
    int findTargetChild(TreeNode* root,TreeNode* target,int K,vector<int>& dkn)
    {
        if(!root)return -1;
        
        else if(root==target)
        {
            findDisKNodes(root,K,dkn);
            return 0;
        }
        
        else
        {
            int lt = findTargetChild(root->left,target,K,dkn);
            int rt = findTargetChild(root->right,target,K,dkn);
            //eventually the node would be found in one of the calls abv
            //now on first encounter the children k distance apart in its subtree
            //would already have been pushed into the res arr.
            //now subsequent two calls out of which one would be made to get
            //the children in other part of the tree on the other side
            cout<<lt<<" "<<rt<<endl;
            if(lt!=-1)
                {   
                    //the condn when there aren't any overflowing k dis apart children beyond root
                    //From 0 it starts, and currently root is equal to target
                    //if(root->left == target)cout<<"Yea"<<endl;
                    //root->left is the target
                    //if K is 1, then it will culminate at it's root, 
                    //thus no overflow to right subtree
                
                    if(lt+1 == K)dkn.push_back(root->val);
                    else findDisKNodes(root->right,K-lt-2,dkn);
                    //now returning thus the level that we've reached far from the target
                    //intintally we called for k dis overflowing nodes in right subtree
                    //of parent just one level above, now we'll be checking for the parent 
                    //lt+1
                    return lt+1;
                }
            else if(rt!=-1)
                {   
                    //if(root->right == target)cout<<"YeaR"<<endl;                
                    if(rt+1 == K)dkn.push_back(root->val);
                    else findDisKNodes(root->left,K-rt-2,dkn);
                    return rt+1;
                }
        
            else return -1;
            }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> distanceKNode;
        findTargetChild(root,target,K,distanceKNode);
        return distanceKNode;
    }
};