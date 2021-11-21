class Solution {
public:
    int findCircleNum1(vector<vector<int>>& ic) {
        vector<int> vis(ic.size(),0);
        int cnt = 0;
        for(int i=0;i<ic.size();i++)
            if(!vis[i])
                dfs(ic,vis,i),
                cnt++;
        return cnt;
    }
    
    void dfs(vector<vector<int>>& ic,vector<int>& vis,int i)
    {
        for(int j=0;j<ic[0].size();j++)
            if(ic[i][j] && !vis[j])
                vis[j] = 1,
                dfs(ic,vis,j);
    }
    
    //Union Find
    
    int findCircleNum(vector<vector<int>>& ic){
        parent.resize(201,0);
        int i = 0,j=0,cnt = 0,n=ic.size();
        make_set(ic.size());
        
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
                if(ic[i][j])
                    union_set(i,j);
        
        for(i=0;i<n;i++)
            if(i==parent[i])
                    cnt++;
        return cnt;
    }
    
    vector<int> parent;
    
    void make_set(int n)
    {
        for(int i=0;i<n;i++)
            parent[i] = i;
    }
    
    int findset(int v)
    {
        if(v == parent[v])return v;
        return parent[v] = findset(parent[v]);
    }
    
    void union_set(int a,int b)
    {
        a = findset(a);
        b = findset(b);
        if(a!=b)
            parent[b] = a;
    }

};