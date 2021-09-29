class Solution {
public:
    vector<int> getRow(int rowIndex) {
        rowIndex++;
        vector<vector<int>> dp(2,vector<int>(rowIndex,0));
        
        dp[0][0]=1;
        
        for(int i=1;i<rowIndex;i++)
        {
            for(int j=0;j<=i;j++)
            {
                dp[i%2][j] = dp[(i+1)%2][j] + ((j>0)?dp[(i+1)%2][j-1]:0);
            }
        }
        
        ;return dp[(rowIndex+1)%2];
    }
};