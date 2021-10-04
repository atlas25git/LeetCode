class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        
        for(auto x: coins)
            for(int i=1;i<=amount;i++)
            {
                if(x<=i)
                    if(dp[i-x]!=INT_MAX)
                    dp[i] = min(dp[i-x]+1,dp[i]);
            }
        return dp[amount]==INT_MAX?-1:dp[amount];
    }
};