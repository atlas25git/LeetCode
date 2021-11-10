class Solution {
public:
    
    //Bottom up:
    
    int findMaxForm1(vector<string>& strs, int m, int n) {
        //it's a problem on the lines of 0 1 knapsack
        //just that rather than considering just one restraint of wt
        //here we act under the duress of 2 factors m and n
        
        vector<vector<vector<int>>>dp(strs.size()+1,vector<vector<int>>(n+1,vector<int>(m+1)));
        
        for(int i = 0;i<=strs.size();i++)
        {
            int z = i>0?count(strs[i-1].begin(),strs[i-1].end(),'0'):0;
            int o = i>0?strs[i-1].size()-z:0; 
            
            for(int j=0;j<=n;j++)
                for(int k=0;k<=m;k++)
                {
                    if(!i)dp[i][j][k]=0;
                    else if(j>=o && k>=z)
                        dp[i][j][k] = max(dp[i-1][j][k],dp[i-1][j-o][k-z]+1);
                    else
                        dp[i][j][k] = dp[i-1][j][k];
                }
        }
        return dp[strs.size()][n][m];
    }
    
     //Recursive + Memoized
     vector<pair<int,int>> convert(vector<string>& strs)
     {
         vector<pair<int,int>> wts;
         for(auto x: strs)
         {
             int z = count(x.begin(),x.end(),'0');
             int o = x.size() - z;
             wts.push_back({z,o});
         }
         return wts;
     }
    vector<vector<vector<int>>> kp;
     int findMaxForm(vector<string>& strs, int m, int n)
     {
         vector<pair<int,int>> wts =convert(strs);
         kp.resize(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        
         return solve(m,n,wts,strs.size());
     }
    
    int solve(int m,int n,vector<pair<int,int>>& wts,int itr)
    {
        if((!n && !m) || itr==0)
            return 0;
        if(kp[itr][m][n]!=-1)return kp[itr][m][n];
        if(wts[itr-1].first<=m && wts[itr-1].second<=n)
                return kp[itr][m][n] = max(
                    solve(m,n,wts,itr-1),
                    1+solve(m-wts[itr-1].first,n-wts[itr-1].second,wts,itr-1)
        );
        else 
                return kp[itr][m][n] = solve(m,n,wts,itr-1);
    }
};