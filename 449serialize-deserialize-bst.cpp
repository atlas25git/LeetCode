/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string str;
        while(q.empty()!=true)
        {
            TreeNode* t=q.front();
            q.pop();
            
            if(!t) str+="#,";
            else{
                q.push(t->left);
                q.push(t->right);
                str+=to_string(t->val) + ",";
            }
            
        }
        return str;
    }

    
    TreeNode* deserialize(string data){
        
        TreeNode* root=NULL;
        queue<TreeNode**> q;
        q.push(&root);
        auto first = data.begin();
        while(first!=data.end())
        {
            TreeNode** pp = q.front();
            if(*first=='#')advance(first,2);
            else{
                auto last=find(first,data.end(),',');
                int val=stoi(string(first,last));
                *pp = new TreeNode(val);
                q.push(&((*pp)->left));
                q.push(&((*pp)->right));
                first=next(last);
            }
            q.pop();
        }
        return root;
        
    }
    // Decodes your encoded data to tree.
    // TreeNode* deserialize(string data) {
    //     TreeNode* root = NULL;
    //     queue<TreeNode**> q;
    //     q.push(&root);
    //     auto first = data.begin();
    //     while(first!=data.end())
    //     {
    //         TreeNode** pp = q.front();
    //         if(*first=='#')advance(first,2);//skips ","
    //         else {
    //             auto last = find(first,data.end(),',');
    //             int val = stoi(string(first,last)); //[val,',')
    //             *pp = new TreeNode(val);
    //             q.push(&((*pp)->left));
    //             q.push(&((*pp)->right));
    //             first=next(last);
    //         }
    //         q.pop();
    //     }
    //     return root;
    // }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;