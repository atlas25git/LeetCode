class Solution {
public:
    
    vector<int> dx = {0,0,1,-1};
    vector<int> dy = {1,-1,0,0};
    
    bool isSafe(int x,int y,int r,int c)
    {
        return(x>-1 && y>-1 && x<r && y<c);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int mx=INT_MIN;
        
        int r = grid.size();
        int c = grid[0].size();
        queue<pair<int,int>> q;
        
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
            {   int mxt = 0;
                if(grid[i][j] == 1)
                {   q.push({i,j});
                    grid[i][j] = 0;
                    mxt+=1;
                }
                while(!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int i=0;i<4;i++)
                    {
                        int dx2 = x + dx[i];
                        int dy2 = y + dy[i];
                        
                        if(isSafe(dx2,dy2,r,c) && grid[dx2][dy2]==1)
                        {
                            grid[dx2][dy2]=0;
                            mxt++;
                            q.push({dx2,dy2});
                        }
                    }
                }
                mx = max(mx,mxt);
            }
        
        return mx;
    }
};