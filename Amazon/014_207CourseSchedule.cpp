class Solution {
public:
    bool canFinish(int nc, vector<vector<int>>& pq) {
        vector<int> indegree(nc,0);
        vector<set<int>> edges(nc);
        
        for(auto x: pq)
            indegree[x[0]]++,
            edges[x[0]].insert(x[1]);
        
        queue<int> q;
        
        for(int i=0;i<nc;i++)
            if(!indegree[i])
                q.push(i);
        cout<<q.front();
        
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            // cout<<x<<": ";
            
            for(int i=0;i<nc;i++)
            {
                
                if(edges[i].count(x))indegree[i]--,edges[i].erase(x);
                if(!indegree[i])
                    indegree[i]--,
                    q.push(i); 
            }
        }
        
        for(auto x: indegree)
            if(x>0)return false;
        return true;
    }
};