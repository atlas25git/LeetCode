class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int l = strs.size();
        vector<vector<vector<int>>> dp(l+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        
        for(int i=0;i<=l;i++)
        {   
            
            int z = i>0?count(strs[i-1].begin(),strs[i-1].end(),'0'):0;
            int o = i>0?strs[i-1].size() - z:0;
           
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++)
                {
                    if(i==0){
                        dp[i][j][k] = 0;
                    }
                    else if(j>=z && k>=o)
                    {
                        dp[i][j][k] = max(dp[i-1][j][k],dp[i-1][j-z][k-o] + 1);
                    }else
                    {
                        dp[i][j][k] = dp[i-1][j][k];
                    }
                }
            }
        }
        return dp[l][m][n];
    }
};

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
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
};