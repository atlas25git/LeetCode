class Solution {
public:
    int uniquePaths1(int m, int n) {
        vector<vector<long>> dp(m,vector<long>(n,0));
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(!i || !j)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        return dp[m-1][n-1];     
    }
    
    //recursive
    vector<vector<long>> dp;
    
    int uniquePaths(int m, int n){
        dp.resize(m,vector<long>(n,0));
        return rec(m,n);
    }
    
    int rec(int m,int n)
    {
        if(!(m-1) || !(n-1))return 1;
        if(dp[m-1][n-1])return dp[m-1][n-1];
        return dp[m-1][n-1] = rec(m-1,n) + rec(m,n-1);
    }
};