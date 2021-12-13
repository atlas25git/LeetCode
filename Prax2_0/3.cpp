class Solution {
public:
    int lengthOfLongestSubstring1(string s) {
        if(!s[0])return 0;
        int i=0,j=0,mx=0;
        unordered_map<char,int> mp;
        
        for(i=0;s[i];i++)
            {if(mp.count(s[i]))
                //since ith char could be present
                //somewhere beyond the starting point of substr
                //hence only considering the ones that'd be in it.
                //We take max of j and last occr of repating char, 
                //so as to forsee the case when there are more than 1 repeating chars.
                //and hence we need to choose it such that both of them are not included.
                //hence the more distant of the two.
                j=max(j,mp[s[i]]+1);
                // j = i;:: Not ths because one occr could be there hence we include he postion of last occ+1
                
            mp[s[i]] = i,
            mx = max(mx,i-j+1);}
        return mx;
    }
    
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int len = 0;
        int j = 0;
        for(int i=0;s[i];i++)
        {
            if(mp.count(s[i]))
                j = max(j,mp[s[i]] + 1);
            mp[s[i]] = i;
            len = max(len,i-j+1);
        }
        return len;
    }
};