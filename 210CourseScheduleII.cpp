class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //indegree based bfs solution, we keep a count of
        //all the vertices indegrees while making the graph
        //there after we do a dfs traversal from the root, that's
        //discerned by the one with zero indegree
        //while encountering nodes in bfs traversal we keep on reducing the indegree
        //of encountered node, and include it in the queue
        //in every iteration we store the front of queue
        
        vector<vector<int>> graph(numCourses);
        vector<int>inDegree(numCourses);
        
        //considering this order of graph construction as we can envisage
        //that if for a subject a, b is a dependency thus a has an indegree from 
        //an edge been constituted by b
        for(auto x: prerequisites)
            graph[x[1]].push_back(x[0]),
            inDegree[x[0]]++;
        
        queue<int> q;
        vector<int>res;
        int nc = 0;

        //at this step all the nodes with 0 indegree are inserted in the queue and
        //thus are used in reducing indegrees of consequetial nodes in order
        for(int i=0;i<graph.size();i++)
            if(inDegree[i]==0)q.push(i);
        
        //bfs
        
        while(!q.empty())
        {
            int t = q.front();
            q.pop();
            res.push_back(t);
            nc++;
            for(auto u: graph[t])
            {
                inDegree[u]--;
                if(!inDegree[u])
                    q.push(u);
            }
        }
        if(nc==numCourses) return res;
        res.clear();
        return res;
    }
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses);
        
        for(auto edge : prerequisites){
            graph[edge[1]].push_back(edge[0]);
            inDegree[edge[0]]++;
        }
        
        int numChoose = 0;
        queue<int> q;
        vector<int> topoOrder;
        
        for(int i=0;i<numCourses;i++)
        {
            if(inDegree[i]==0)q.push(i);
        }
        
        while(!q.empty())
        {
            int t = q.front();
            q.pop();
            topoOrder.push_back(t);
            numChoose++;
            
            for(int u : graph[t]){
                inDegree[u]--;
                if(inDegree[u] == 0)
                        q.push(u);
            }
        }
        
        if(numChoose == numCourses)return topoOrder;
        topoOrder.clear();
        return topoOrder;
            
    }
};