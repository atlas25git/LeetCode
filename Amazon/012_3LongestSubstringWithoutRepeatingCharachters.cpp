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
    //BruteForce O(n^3), O(n^2)sc
    int lengthOfLongestSubstringBrute(string s) {
        
        auto isPal = [s](int j,int i) -> bool
        {   
            unordered_set<int> st;
            for(int x=j;x<=i;x++)
                if(st.count(s[x]))
                    return false;
                else st.insert(s[x]);
            
            return true;
        };
        
        int len = 0;
        for(int i=0;i<s.size();i++)
        {
            for(int j=0;j<=i;j++)
                {
                    if(isPal(j,i))
                        {   
                            // cout<<" "<<i<<" "<<j<<" "<<s.substr(j,(i-j+1))<<"\n";
                            len = max(len,(i-j+1));
                        }
                }
        }
        
        return len;
    }
    
    //Efficient Approach:
    //TC: O(n)
    //SC: O(n)
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int j=0,len=0;
        
        for(int i=0;i<s.size();i++)
        {
            if(mp.count(s[i]))
                j = max(j,mp[s[i]]+1);
            len = max(len,i-j+1);
            mp[s[i]] = i;
        }
        return len;
    }

};