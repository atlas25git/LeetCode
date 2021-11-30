//The answer is stored at dp[0], and while computing it builds solution in top down manner
//starting from ind = 0, it looks up for first word that is in dict and hence makes a call
//for the remaining string, once i == s.size() : means the string could be partitioned

class Solution {
    unordered_set<string> dict;
    string s;
    vector<bool> dp;
    public:
    bool wordBreak(string s1, vector<string>& wordDict) {
        unordered_set<string> d(wordDict.begin(),wordDict.end());
        swap(dict,d),swap(s,s1);
        dp.resize(s.size()+1,0);
        //bottom up
        dp[0] = 1;
        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>-1;j--)
            {
                if(dp[j])
                {
                    dp[i] =dp[i] || dict.count(s.substr(j,i-j));
                    // if(dp[i])
                    // break;
                }
            }
        }
        return dp.back();
        // return work(0);
    }
    
    bool work(int ind)
    {
        if(ind == s.size())return 1;
        if(dp[ind] != -1)return dp[ind];
        string sub;
        for(int i=ind;i<s.size();i++)
            if(dict.count(sub+=s[i]) && work(i+1))return dp[ind]=1;
        return dp[ind] = 0;
    }
};