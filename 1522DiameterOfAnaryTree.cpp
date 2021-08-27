class Solution {
public:
    int diameter(Node* root) {
        if(root == NULL) return 0;
        int ans = 0;
        foo(root, ans);
        return ans;
    }
    
    int foo(Node* root, int& ans) {
        if(root == NULL) return 0;
        int prev = 0;
        for(auto c : root->children) {
            int h = foo(c, ans);
            ans = max(ans, h+prev);
            prev = max(prev, h);
        }
        return prev+1;
    }
};