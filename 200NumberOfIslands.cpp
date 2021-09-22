class Solution {
public:
    
    vector<int> dx = {0,0,1,-1};
    vector<int> dy = {-1,1,0,0};
    
    bool isSafe(int i,int j,int r,int c)
    {
        return (i>-1 && j>-1 && i<r && j<c);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        queue<pair<int,int>> q;
        
        int ans=0;
        int r = grid.size(),c=grid[0].size();
       
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
            {
                if(grid[i][j] == '1')
                {
                    q.push({i,j});
                    grid[i][j] = '0';
                    ans++;
                    
                    while(!q.empty())
                    {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        
                        for(int k=0;k<4;k++)
                        {
                            int ni = x + dx[k];
                            int nj = y + dy[k];
                            
                            if(isSafe(ni,nj,r,c) && grid[ni][nj] == '1')
                            {
                                q.push({ni,nj});
                                grid[ni][nj] = '0';
                            }
                        }
                    }
                }
            }
        
        return ans;
    }
};