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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        //basically here our approach is to do a lvl order
        //traversal to get the deepest leaves
        //while traversing the tree nodes we store each one's
        //parent in a hashMap
        //We keep a leaves vector which we clear on every iteration of bfs
        //thus it culminates with just the leave nodes, the last level
        //now these could be from more than one parent, and thus we aim to
        //get their ancestor, hence alternatively, we store parents of leaves in leaves vector
        //in a set, and thus transfer them to leaves array and re run the iteration,
        //this continues till there is just one node present, and thus we've found
        //the acestor.
        
        unordered_map<TreeNode*,TreeNode*> map;
        queue<TreeNode*> q;
        vector<TreeNode*> leaves;
        
        q.push(root);
        map[root]=NULL;
        
        while(!q.empty())
        {
            int sz = q.size();
            leaves.clear();
            for(int i=0;i<sz;i++)
            {
                TreeNode* t = q.front();
                q.pop();
                leaves.push_back(t);
                
                if(t->left)
                    map[t->left]=t,
                    q.push(t->left);
                if(t->right)
                    map[t->right]=t,
                    q.push(t->right);
            }
        }
        
        //leaves contain the deepest leaves
        
        unordered_set<TreeNode*> parent;
        
        while(leaves.size()>1)
        {
            for(auto n:leaves)
                    if(parent.find(map[n])==parent.end())
                            parent.insert(map[n]);
            
            leaves.clear();
            leaves = vector<TreeNode*>(parent.begin(),parent.end());
            parent.clear();
            
        }
        return leaves[0];
        
    }
};


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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root == NULL)return root;
        
        unordered_map<TreeNode*,TreeNode*> map;
        queue<TreeNode*> q;
        vector<TreeNode*> lastlvl;
        
        
        q.push(root);
        map[root] = NULL;
        
        while(!q.empty())
        {
            int sz = q.size();
            lastlvl.clear();
            
            for(int i=0;i<sz;i++)
            {
                TreeNode* t = q.front();
                q.pop();
                lastlvl.push_back(t);
                
                if(t->left)
                    map[t->left] = t,
                    q.push(t->left);
                if(t->right)
                    map[t->right] = t,
                    q.push(t->right);
            }
        }
        unordered_set<TreeNode*> par;
        int iter = 1;
        while(lastlvl.size()>1)
        {
            for(auto n : lastlvl)
            {
                if(par.find(map[n])==par.end())
                        par.insert(map[n]);
            }
            lastlvl.erase(lastlvl.begin(),lastlvl.end());
            
            //copy(par.begin(),par.end(),lastlvl.begin()); 
            for(auto x:par)lastlvl.push_back(x);
            //lastlvl = vector<TreeNode*>(par.begin(),par.end());
            par.clear();
        }
        
        
        return lastlvl[0];
        
    }
    
};