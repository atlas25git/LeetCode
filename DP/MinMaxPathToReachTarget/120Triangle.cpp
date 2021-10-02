class Solution {
public:
    
    vector<vector<int>> cache;
    
    int minimumTotal(vector<vector<int>>& triangle) {
        if(!triangle.size())return 0;
        
        //cache
        cache.resize(triangle.size(),vector<int>(triangle.size(),INT_MAX));
        return BUP(triangle);
    }
    
    int BUP(vector<vector<int>>& tri)
    {
        for(int i=0;i<tri.size();i++)
            cache[tri.size()-1][i] = tri[tri.size()-1][i];
        
        for(int i = tri.size()-2;i>-1;i--)
            for(int j=0;j<=i;j++)
                cache[i][j] = tri[i][j] + min(cache[i+1][j+1],cache[i+1][j]);
        
        return cache[0][0];
    }
    
    int rec(int i,int j,vector<vector<int>>& tri)
    {
        if(i+1 >= tri.size()) return tri[i][j];
        
        return tri[i][j] + min(rec(i+1,j,tri),rec(i+1,j+1,tri));
    }
    
    int recCache(int i,int j, vector<vector<int>>& tri)
    {
        
        if(i+1>=tri.size())return tri[i][j];
        
        if(cache[i][j]!=INT_MAX)return cache[i][j];
        
        cache[i][j] = tri[i][j] + min(recCache(i+1,j,tri),recCache(i+1,j+1,tri));
        return cache[i][j];
        
    }
};