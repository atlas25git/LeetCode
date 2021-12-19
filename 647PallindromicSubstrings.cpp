class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int start = 0,ml = 1;
        vector<vector<int>> dp(n,vector<int>(n,0));
        int count = n;
        for(int i=0;i<n;i++)dp[i][i] = 1;
        for(int i=0;i<n-1;i++)if(s[i] == s[i+1])dp[i][i+1] = 1,count++;
        
        for(int len=3;len<=n;len++)
        {
            for(int i=0;i<=n-len;i++)
            {
                if(s[i] == s[i+len-1] && dp[i+1][i+len-1 -1])
                {
                    count++;
                    dp[i][i+len-1] = 1;
                    
                }
            }
        }
        return count;
    }
};