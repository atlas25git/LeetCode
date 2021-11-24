class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s[0])return 0;
        int i=0,j=0,mx=0;
        unordered_map<char,int> mp;
        
        for(i=0;s[i];i++)
            {if(mp.count(s[i]))
                //since ith char could be present
                //somewhere beyond the starting point of substr
                //hence only considering the ones that'd be in it.
                j=max(j,mp[s[i]]+1);
            mp[s[i]] = i,
            mx = max(mx,i-j+1);}
        return mx;
        
    }
};