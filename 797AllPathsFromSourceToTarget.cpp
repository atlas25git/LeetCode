class Solution {
public:
    
    void util(int& pC,vector<vector<int>>& graph,int s,vector<bool>& vis,int p,vector<vector<int>>& res,vector<int> temp)
    {
        vis[s]=true;
        temp.push_back(s);
        if(s==p)
        {
            res.push_back(temp);
            temp.clear();
            //turn;
        }
        else{
            for(auto x:graph[s])
                if(!vis[x])util(pC,graph,x,vis,p,res,temp);
        }
        
        temp.pop_back();
        vis[s]=false;
        return;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
            
        int pC=0;
        vector<vector<int>> res;
        vector<bool> vis(graph.size(),0);
        vector<int> temp;
        util(pC,graph,0,vis,graph.size()-1,res,temp);
        
        return res;
    }
};