class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        //BFS based O(V+E) solution
        //the idea is that initially we'll paint all the nodes 1
        //now as we encounter in a bfs traversal if colors are equal
        //then we'll increment the color of present node, this way only the
        //alternate nodes will face this dichotomy thus, in the case of a cycle
        //it'll be +1, thus portraying out of bound color
      //       0|1
      //      / \
      // 3|4|2    1|2
      //     \      \
      //     3|2___ 2|1
        
        int n=graph.size();
        
        vector<bool>vis(n,0);
        vector<int>color(n,1);
        int mC=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(vis[i])continue;
            vis[i]=true;
            queue<int> q;
            q.push(i);
            while(!q.empty())
            {
                int u = q.front();
                q.pop();
                
                for(int i=0;i<graph[u].size();i++)
                {
                    if(color[u] == color[graph[u][i]])
                            color[graph[u][i]]++;
                    mC = max({mC,color[u],color[graph[u][i]]});
                    if(mC>2)return false;
                    
                    if(!vis[graph[u][i]])
                    {
                        vis[graph[u][i]]=true;
                        q.push(graph[u][i]);
                    }
                }
            }
                
        }
        
        return true;
            
                
        
        
        }       
};

//BFS based solution does, the same task in O(V+E)
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n  = graph.size();
        vector<int>visited(n,0);
        vector<int>color(n,1);
        int maxC = 1;
        for(int sv =1;sv<n;sv++)
        {
            if(visited[sv])continue;
            visited[sv]=1;
            queue<int>q;
            q.push(sv);
            
            while(!q.empty())
            {
                int u = q.front();
                q.pop();
                
                for(int i=0;i<graph[u].size();i++)
                {
                    if(color[u] == color[graph[u][i]])
                            color[graph[u][i]]++;
                    maxC = max({maxC,color[graph[u][i]],color[u]});
                    if(maxC>2)return false;
                    if(!visited[graph[u][i]])
                    {
                        visited[graph[u][i]] = 1;
                        q.push(graph[u][i]);
                    }
                }
                
            }
        }
        for(auto c:color)cout<<c<<" ";
        return true;
    }
};


class Solution {
public:
    //Back Tracking based solution this times out, use this in the case we're
    //sought to produce the color array
    bool isSafe(vector<vector<int>>& graph,int u,int V,int c,vector<int>&color)
    {
        for(int i=0;i<graph[u].size();i++)
        {   //if(i==u)continue;
            if(color[graph[u][i]]==c)return false;
        }
        return true;
    }
    
    bool util(vector<vector<int>>& graph,int u,int V,int m,vector<int>&color)
    {   //cout<<u<<" : "<<V<<endl;
        
        if(u==V)
        {   
            //cout<<"condn"<<endl;
            return true;
        }
        for(int i=1;i<=2;i++)
        {
            if(isSafe(graph,u,V,i,color))
            {
                color[u]=i;
                if(util(graph,u+1,V,2,color))return true;
                color[u]=0;
            }
        }
        
        return false;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        //backtracking based solution
        
        int V = graph.size();
        
        vector<int>color(graph.size(),-1);
        
        return util(graph,0,V,2,color)==false?false:true;
    }
};