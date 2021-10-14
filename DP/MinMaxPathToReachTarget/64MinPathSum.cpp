class Solution {
public:
    unordered_map<string,int> memo;
    
    int minPathSum(vector<vector<int>>& grid) {
          return rec(grid,grid.size()-1,grid[0].size()-1);
    }
    
    int rec(vector<vector<int>>& grid,int i, int j)
    {
        if(!i && !j)return grid[i][j];
        if(memo.count(to_string(i) + " " + to_string(j)))return memo[to_string(i)+" "+to_string(j)];
        if(!i)return grid[i][j] + rec(grid,i,j-1);
        if(!j)return grid[i][j] + rec(grid,i-1,j);
        return memo[to_string(i)+" "+to_string(j)] = grid[i][j] + min(rec(grid,i-1,j),rec(grid,i,j-1));
    }
    
    int bUP(vector<vector<int>>& grid)
    {
        int m = grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
        
        for(int i=0;i<m;i++)dp[i][0] = grid[i][0]+(i?dp[i-1][0]:0);
        for(int i=0;i<n;i++)dp[0][i] = grid[0][i]+(i?dp[0][i-1]:0);
        
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                dp[i][j] =  grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
        
        return dp[m-1][n-1]; 
    }
    
};