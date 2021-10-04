class Solution {
public:
    int numSquares(int n) {
        //basically the idea here is that our dp[i] will store
        //the min no of squares needed to sum up to it.
        //and hence for every no. i we'll search for all such combinations
        //till its sqrt
        
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=sqrt(i);j++)
                dp[i] = min(dp[i],dp[i-j*j]+1);
        
        return dp[n];
    }
};