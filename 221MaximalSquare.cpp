class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(!matrix.size())return 0;
        
        int m = matrix.size(),n = matrix[0].size(),sz=0;
        
        vector<vector<int>> dp(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(!i || !j | matrix[i][j] == '0')
                    dp[i][j] = matrix[i][j]-'0';
                else
                    //i,j contains 1, and if all three behind it are also 1
                    //it becomes 2, in other cases remains 1 as adding 1 
                    dp[i][j] = min({dp[i-1][j-1], dp[i-1][j] ,dp[i][j-1]}) + 1;
                sz = max(dp[i][j],sz);
            }
        // for(auto x: dp)
        // {
        //     for(auto y : x)
        //         cout<<y;
        //     cout<<endl;
        // }
        
        return sz*sz;
    }
};

// 1 0 1 0 0 
// 1 0 1 1 1 
// 1 1 1 2 2 
// 1 0 1 2 3 