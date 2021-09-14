class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
            {
                if(!i || !j)
                    dp[i][j] = 0;
                else if(text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        
//         //print lcs
//         int i=n,j=m;
//         string s;
//         while(i>0 && j>0)
//         {
//             if(text1[i-1] == text2[j-1])
//             {
//                 s+=text1[i-1];
//                 i--;j--;
//             }else{
//                 if(dp[i][j-1] > dp[i-1][j])
//                 {
//                     s+=text1[i-1];
//                     i--;
//                 }
//                 else if(dp[i][j-1] < dp[i-1][j])
//                     s+=text2[j-1],
//                     j--;
//                 else i--,j--;
//             }
//         }
        
//         reverse(s.begin(),s.end());
//         cout<<s<<endl;
        
        return dp[n][m];
    }
};