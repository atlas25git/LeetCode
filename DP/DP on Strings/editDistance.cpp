class Solution {
    map<pair<int,int>,int> memo;
public:
    int minDistance(string word1, string word2) {
        // int ans = rec(word1,word2,word1.size(),word2.size());
        int ans = dpBased(word1,word2);
        return ans;
    }
    
    int rec(string& word1,string& word2,int m,int n)
    {
        if(!n)return m;
        if(!m)return n;
        if(memo.count({m,n}))return memo[{m,n}];
        if(word1[m-1] == word2[n-1])
            return memo[{m,n}] = rec(word1,word2,m-1,n-1);
        
        return memo[{m,n}] = 1 + min({rec(word1,word2,m-1,n),
                  rec(word1,word2,m,n-1),
                  rec(word1,word2,m-1,n-1)});
    }
    
    int dpBased(string& word1,string& word2)
    {
        int m = word1.size();
        int n = word2.size();
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        //dp[i][j] -> will tell us the minimum edits required for string 1's initial i letters
        //and string 2's j
        
        //recurrence relation:
        //if no edit required then answer will simply be the smaller state dp[i-1][j-1]
        
        //in all the other contingencies we'll check for the minimum among all the three
        //options available to us.
        
        //base case:
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(!i)
                    dp[i][j] = j;
                else if(!j)
                    dp[i][j] = i;
                else if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else 
                    dp[i][j] = 1 + min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
            }
        }
        return dp[m][n];
    }
};