//Using Kahn's bfs algorithm for topological sort.
//TC :: O(v+e)
//SC :: O(v+e)

class Solution {
public:
    bool canFinish(int nC, vector<vector<int>>& pQ) {
        vector<vector<int>> adj(nC,vector<int>());
        vector<int> deg(nC,0);
        
        //making adjacency list and whilst also calculating the indegree
        int nc1 = pQ.size();
        for(int i=0;i<nc1;i++)
        {
            //since we'll need to decrease indegree of each of the
            //elements which were dependent on the completed task.
            //for this we can maitain indgree based list.
            //in adj list adj[v1] contains all the vertices for which v1 is a dependency
            adj[pQ[i][1]].push_back(pQ[i][0]);
            deg[pQ[i][0]]++;
        }
        
        queue<int> q;
        
        for(int i=0;i<nC;i++)
        {
            if(!deg[i])q.push(i);
        }
        
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            nC--;
            
            //reducing the indegree of all the vertices dependent on curr
            for(auto x: adj[curr])
                if(--deg[x] == 0)
                    q.push(x);
        }
        return nC==0;
    }
};