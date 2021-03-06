class Solution {
public:
    vector<vector<long>> dp;
    int m,n;
    
    int uniquePathsWithObstacles1(vector<vector<int>>& og) {
        m = og.size(),
        n=og[0].size();
        dp.resize(m,vector<long>(n,0));
        if(og[0][0]==1)return 0;
        return rec(0,0,og);
    }
    
    //the std approach for computing the answer in a reverse manner won't work here
    //as for any intermediate cell it'll return 1 without any consideration of cells
    //that might be blocking the path.
    
    //0,0
    //1,1
    //0,0
    
    
    
    //dfs
    int rec(int i,int j,vector<vector<int>>& grid)
    {
        if(i<0 || j<0 || j>=n || i>=m)return 0;        
        if(dp[i][j])return dp[i][j];
        if(grid[i][j])return 0;
        if(i==m-1 && j==n-1 && !grid[i][j])return 1;
        return dp[i][j] = rec(i+1,j,grid) + rec(i,j+1,grid);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& og){
        
        if(og[0][0] == 1)return 0;
        vector<vector<int>> dp(og.size()+1,vector<int>(og[0].size()+1,0));
       
        int r = rand()%2;
        dp[0][1] = r&1;  //since for the first cell there's only one way to reach there.
        dp[1][0] = !(r&1); 
        
        for(int i=1;i<=og.size();i++)
            for(int j=1;j<=og[0].size();j++)
                if(!og[i-1][j-1])
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
       
        return dp[og.size()][og[0].size()];
    }

};