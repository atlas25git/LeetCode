class Solution {
public:
    int res = 0,empty=1,sx,sy,ex,ey;
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = size(grid),n=size(grid[0]);
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(!grid[i][j])empty++;
                else if(grid[i][j] == 1)
                {
                    sx =i;
                    sy=j;
                }
            }
        dfs(grid,sx,sy);
        return res;
    }
    
    void dfs(vector<vector<int>>& grid,int x,int y)
    {
        if(x<0 || x>=size(grid) || y<0 || y>=grid[0].size() || grid[x][y]<0)
            return;
        if(grid[x][y] == 2)
        {
            if(!empty)res++;
            return;
        }
        grid[x][y] = -2;
        empty--;
        dfs(grid,x+1,y);
        dfs(grid,x-1,y);
        dfs(grid,x,y+1);
        dfs(grid,x,y-1);
        grid[x][y]=0;
        empty++;
             
    }
};