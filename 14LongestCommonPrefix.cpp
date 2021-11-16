class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)return "";
        string pre = strs[0];
        for(int i=1;i<strs.size();i++)
            while(strs[i].find(pre) != 0)
            {
                pre = pre.substr(0,pre.size()-1);
                if(pre.size() == 0)return "";
            }
        return pre;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size())return "";
        return lcp(strs,0,strs.size()-1);
    }
    
    string lcp(vector<string>& strs,int l,int r)
    {
        if(l==r)return strs[l];
        else{
            int m = (l+r)/2;
            string left = lcp(strs,l,m);
            string right = lcp(strs,m+1,r);
            return cp(left,right);
        }
    }
    
    string cp(string left,string right)
    {
        if(left.size()>right.size())swap(left,right);
        
        for(int i=0;i<left.size();i++)
            if(left[i] != right[i])
                    return left.substr(0,i);
        return left;
    }
};