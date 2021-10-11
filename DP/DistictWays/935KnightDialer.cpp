class Solution {
public:
    vector<vector<vector<long>>> memo;
    int m = 1e9+7;
    
    vector<int> dx = {1,1,2,2,-1,-1,-2,-2};
    vector<int> dy = {2,-2,1,-1,2,-2,1,-1};
    
    
    int knightDialer(int n) {
        
        memo.resize(n+1,vector<vector<long>>(4,vector<long>(3,0)));
        long s = 0;
        
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<3;j++)
            {
                s = (s + paths(i,j,n))%m;
            }
        }
        return (int)s;
    }
    
    long paths(int i, int j,int n)
    {
        if(i<0 || j<0 || i>=4 || j>=3 || (i==3 && j!=1))return 0;
        
        
        //trivial case
        if(n==1)return 1;

        if(memo[n][i][j])return memo[n][i][j];
        
        long s=0;
        
        for(int k=0;k<8;k++)
        {
            s = (s + paths(i+dx[k],j+dy[k],n-1))%m;
        }
        return memo[n][i][j] = s;
    }
};