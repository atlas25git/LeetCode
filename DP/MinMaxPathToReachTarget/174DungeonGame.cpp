class Solution {
public:
    map<pair<int,int>,int> memo;
    int calculateMinimumHP(vector<vector<int>>& dg) {
        //recursive approach:
        //since we need the answer at 0,0 hence calling the fn 
        //for 0,0 as initial states.
        
        // return rec(dg,0,0);
        
        vector<vector<int>>dp (dg.size()+1,vector<int>(dg[0].size()+1,INT_MAX));
        
        //dp[i][j] will have the min energy required to reach this cell
        int r = dg.size();
        int c = dg[0].size();
        
        dp[r-1][c] = 1;
        dp[r][c-1] = 1;
        
        for(int i=r-1;i>-1;i--)
            for(int j=c-1;j>-1;j--)
            {     
                    int nd = min(dp[i+1][j],dp[i][j+1]) - dg[i][j];
                    dp[i][j] = nd>0?nd:1;
            }
        
        return dp[0][0];
    }
    
    int rec(vector<vector<int>>& dg,int i,int j)
    {
        if(i==dg.size() || j==dg[0].size())
                return 1e9+7;
        
        if(i==dg.size()-1 && j == dg[0].size()-1)
                return dg[i][j]>0?1:-1*(dg[i][j])+1;
        
        if(memo.count({i,j}))
                return memo[{i,j}];
        int rw = rec(dg,i+1,j);
        int dw = rec(dg,i,j+1);
        
        int mhrc = min(rw,dw) - dg[i][j];
        
        return memo[{i,j}] = mhrc>0?mhrc:1;
    }
};