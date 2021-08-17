class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        
        if(!grid.size() || !grid[0].size())return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<pair<int,int>>> bridges;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,-1,1};
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 && vis[i][j]==false)
                {
                    vis[i][j]=true;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vector<pair<int,int>> tmp;
                    while(!q.empty())
                    {
                        auto p = q.front();
                        q.pop();
                        tmp.push_back({p.first,p.second});
                        for(int d=0;d<4;d++)
                        {
                            int x = dx[d] + p.first;
                            int y = dy[d] + p.second;
                            
                            if(x>=0 && x<m && y>=0 && y<n && !vis[x][y] && grid[x][y])
                            {
                                q.push({x,y});
                                vis[x][y] = true;
                            }
                        }
                    }
                    bridges.push_back(tmp);
                }
            }
        int dis = INT_MAX;
        for(auto b1 : bridges[0])
            for(auto b2 : bridges[1])
                //-1 because 2 cells are added redundantly one in horizontal and in vertical
                // 1------#
                //        |
                //        |
                // #------2 
                dis = min(dis, abs(b1.first - b2.first) + abs(b1.second - b2.second)-1);
        
        return dis;
    }
};

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        
        if(!grid.size() || !grid[0].size())return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<pair<int,int>>> bridges;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,-1,1};
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 && vis[i][j]==false)
                {
                    vis[i][j]=true;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vector<pair<int,int>> tmp;
                    while(!q.empty())
                    {
                        auto p = q.front();
                        q.pop();
                        tmp.push_back({p.first,p.second});
                        for(int d=0;d<4;d++)
                        {
                            int x = dx[d] + p.first;
                            int y = dy[d] + p.second;
                            
                            if(x>=0 && x<m && y>=0 && y<n && !vis[x][y] && grid[x][y])
                            {
                                q.push({x,y});
                                vis[x][y] = true;
                            }
                        }
                    }
                    bridges.push_back(tmp);
                }
            }
        int dis = INT_MAX;
        for(auto b1 : bridges[0])
            for(auto b2 : bridges[1])
                dis = min(dis, abs(b1.first - b2.first) + abs(b1.second - b2.second) - 1);
        
        return dis;
    }
};

class Solution {
public:
    int ShortestBridge(vector<vector<int>>& A){
        if (A.size() == 0 || A[0].size() == 0) {
            return 0;
        }
        int m = A.size(); 
        int n = A[0].size();
        vector< vector<pair<int,int>> > bridge;
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        int op1[] = {1,-1,0,0};
        int op2[] = {0,0,1,-1};
        
        for(int i = 0; i < m; i++){
            
            for(int j = 0; j < n; j++){
                
                if (A[i][j] == 1 && visited[i][j] == false){
                    visited[i][j] = true;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vector<pair<int,int>> tmp;
                    while(!q.empty()){
                        auto p = q.front(); q.pop();
                        tmp.push_back({p.first,p.second});
                        for( int move = 0; move < 4; move++){
                            int x = op1[move] + p.first;
                            int y = op2[move] + p.second;
                            if (x >=0 && x < m && y >=0 && y < n && visited[x][y] == false && 
                               A[x][y] == 1){
                                q.push({x,y});
                                visited[x][y] = true;
                            }
                        }  
                    }
                    bridge.push_back(tmp);
                } 
            }
        }
            
        int distance = INT_MAX;    
        for(auto& b1 : bridge[0]){
            for(auto&b2  : bridge[1]){   
                distance = min(distance, abs(b1.first - b2.first) + abs(b1.second - b2.second) - 1);
            }
        }
        return distance;
    }
};