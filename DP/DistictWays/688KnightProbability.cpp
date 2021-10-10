class Solution {
public:
    map<pair<pair<int,int>,int>,double> memo;
    vector<int> dx = {1,1,2,2,-1,-1,-2,-2};
    vector<int> dy = {2,-2,1,-1,2,-2,1,-1};
    
    double knightProbability(int n, int k, int row, int column) {
        // memo.resize(n,vector<vector<double>>(n,vector<double>(k+1,0)));
        return find(n,k,row,column);
    }
    
    double find(int n,int k,int r,int c)
    {
        if(r<0 || r>n-1 || c<0 ||c>n-1)return 0;
        if(k==0)return 1;
        
        double rate = 0;
        if(memo.count({{r,c},k}))return memo[{{r,c},k}];
        
        for(int i=0;i<8;i++)
        {   
            rate += 0.125*find(n,k-1,r+dx[i],c+dy[i]);

        }
        
        return memo[{{r,c},k}] = rate;
        
    }
};