class Solution {
public:
    vector<vector<int>> dp;
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        dp.resize(dungeon.size(),vector<int>(dungeon[0].size(),INT_MAX));
        
        return solveBUP1(dungeon);
    }
    
    int solve(vector<vector<int>>& d,int i,int j)
    {
        if(i >= d.size() || j >= d[0].size())return INT_MAX;
        
        if(i==d.size()-1 && j==d[0].size()-1)
                return d[i][j]>0?1:-1*(d[i][j])+1;
        
        if(dp[i][j]!=INT_MAX)
                return dp[i][j];
        
        int r = solve(d,i+1,j);
        int dw = solve(d,i,j+1);
        
        //merge step
        //for positive power value our king will get those as incentives on
        //arriving here hence we can reduce this cost from total
        int mhrc = min(r,dw) - d[i][j];
        
        return dp[i][j] = mhrc>0?mhrc:1;

    }
    
    int solveBUP(vector<vector<int>>& dg)
    {
        int r = dg.size(),c=dg[0].size();
        vector<vector<int>> dp(r+1,vector<int>(c+1,99));
        
        //r-1,c-1 is the destination it's destiation in defined terms
        //hence should have the minimum possible energy to be calculated
        dp[r][c-1] = 1;
        dp[r-1][c] = 1;
        
        
        for(int i=r-1;i>-1;i--)
            for(int j=c-1;j>-1;j--)
            {   
                //since we're iterating from the end thus,
                //increments in i,j are symbolizing the inherently
                //previous states.
                int nd = min(dp[i+1][j],dp[i][j+1]) - dg[i][j];
                dp[i][j] = nd>0?nd:1;
            }
        
         for(auto x: dp)
        {
            for(auto y: x)
                cout<<y<<"   ";
            cout<<endl;
        }
        
        return dp[0][0];
    }
    
};