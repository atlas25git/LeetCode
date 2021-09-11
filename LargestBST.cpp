struct node1
{
    int isbst;
    int size;
    int mn;
    int mx;
};
struct node1 bst(struct Node *root)
{
    struct node1 x;
    if(root == NULL) {
        x.isbst = 1;
        x.size = 0;
        x.mn = 1000000;
        x.mx = 0;
        return x;
    }
    struct node1 left = bst(root->left);
    struct node1 right = bst(root->right);
    if(left.isbst == 1 && right.isbst == 1 && root->data > left.mx && root->data < right.mn) {
        x.isbst = 1;
        x.size = 1+left.size+right.size;
        x.mx = max(root->data,right.mx);
        x.mn = min(root->data,left.mn);
    }
    else {
        x.isbst = 0;
        x.size = max(left.size,right.size);
        x.mn = 1000000;
        x.mx = 0;
    }
    return x;
};

class Solution{
    public:
    int largestBst(Node *root)
    {
        return bst(root).size;
    }
};