class Solution {
public:
    int maximalSquare1(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        
        int m = matrix.size(), n = matrix[0].size(), sz = 0;
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                if (!i || !j || matrix[i][j] == '0') {
                    dp[i][j] = matrix[i][j] - '0';
                } else {
                    //considering minimum coz we are assuming our dp[i][j]
                    // /as having the side len of which square existes corresponding to that cell
                    //now out of the three the one containing the cell in question will have
                    //the min as the commmon intersection side length
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
                sz = max(dp[i][j], sz);
            }
        }
        return sz * sz;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int r = matrix.size();
        int c = size(matrix[0]);
        int sz = 0;
        vector<vector<int>> dp(r,vector<int>(c,0));
        
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
            {
                if(!i || !j || matrix[i][j]=='0')
                    dp[i][j] = matrix[i][j]-'0';
                else{
                    dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]}) + 1;
                }
                sz = max(sz,dp[i][j]);
            }
        return sz*sz;
    }
};