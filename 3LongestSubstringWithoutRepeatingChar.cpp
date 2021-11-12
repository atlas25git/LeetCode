class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)return 0;
        unordered_map<char,int>  mp;
        int mx = 0;
        for(int j=0,i=0;s[i];i++)
        {
            if(mp.count(s[i]))
                j = max(j,mp[s[i]]+1);                
            mp[s[i]] = i;
            mx = std::max(mx,i-j+1);
        }
        return mx;
    }
};