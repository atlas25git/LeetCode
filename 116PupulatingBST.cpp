/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
   Node* connect(Node *root)
    {
        if(!root)return root;
        //creating queue for level order traversal of tree.
        queue <Node*> q;
        q.push(root);
        
        //prev holds the value of previous node on the particular level.
        Node* prev=NULL;
        
        //end will hold value of last node of a level
        //and nextend will store the same for the next level.
        Node* end = root, *nextend;
        
        
        while(!q.empty())
        {
            //storing the front element of queue in temp and popping it.
            Node* temp = q.front();
            q.pop();
            
            //storing all available nodes in queue and updating nextend.
            if(temp->left) 
            { 
                q.push(temp->left);
                nextend = temp->left;
            }
            if(temp->right)
            { 
                q.push(temp->right);
                nextend = temp->right;
            }
            
            //setting nextRight of previous node of that level.
            if(prev) 
            prev->next = temp;
            
            //if we reach the end of a level, we set nextRight of the 
            //current node and prev to NULL.
            if(temp == end)
            {
                temp->next = NULL;
                prev = NULL;
                //we also set the value of end for next level.
                end = nextend;
            }
            //else we set prev to current node temp. 
            else 
            prev = temp;
        }
       return root;
    } 
    
    Node* connect1(Node* root) {
        if(!root)return root;
        queue<Node*> q;
        q.push(root);
        
        if(q.size()==1)
            {
                Node* t1=q.front();
                q.pop();
                if(t1->left)q.push(t1->left);
                if(t1->right)q.push(t1->right);

            }
        
        while(!q.empty())
        {   
            int ls = q.size();
            while(ls--)
        {   
            
            Node* t = q.front();
            q.pop();
            if(ls!=0)t->next=q.front();
            if(t->left)q.push(t->left);
            if(t->right)q.push(t->right);

        } 
            
        }
        return root;
    }
};