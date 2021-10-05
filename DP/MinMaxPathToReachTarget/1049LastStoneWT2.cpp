class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        //the idea here basically is that we need to maintain 2 sets
        //and minimize their diff here this could be envisaged as
        //s2,s1 being the 2 sets such that sum = s1 + s2
        //now to minimize the two sets let's say s1>=s2;
        //since s1 = sum -s2
        //substituting sum-s2-s2>=0
        //sum-2*s2>=0 should be as close to zero as it could be
        //for this we need to divise maximum sum that could be made bounded by sum/2'
        int n = stones.size();
        int total=0;
        for(auto x: stones)total+=x;
        int sum = total>>1;
        vector<vector<int>> dp(n+1,vector<int>(sum+1,INT_MIN));
        // dp[0][0] = 0;
        
        for(int i=0;i<=n;i++)
            for(int j=0;j<=sum;j++)
            {
                if(!i || !j)dp[i][j]=0;
                else if(stones[i-1] <= j)
                    dp[i][j] = max(dp[i-1][j],dp[i-1][j-stones[i-1]] + stones[i-1]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        
        return total - 2*dp[n][sum];
    }
};