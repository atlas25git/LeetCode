class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        
        int i = s[0]=='-'?0:0,j=s.size()-1;
        //cout<<s[i]<<endl;
        while(i<=j)
        {
            if(s[i++] != s[j--])return false;
        }
        return true;
    }
};