#define ll long long

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        //bounded knapsack problem
        int m=stations.size();
        //vector<vector<ll>> dp(m+1,vector<ll>(m+1,0));
        
        //dp[i][j] : maximum distance reachable by using j out of i fusel stops
        //with 0 fuel stops being used i.e., dp[i][0] we can only travel the startFuel distance
        
        // for(int i=0;i<=m;i++)dp[i][0] = startFuel;
        
        //We'll start from fuel stations being 1
        
//         for(int i=1;i<=m;i++)
//             for(int j=1;j<=m;j++)
//             {
//                 //intially the distance would be equal to the distance 
//                 //reachable when we didn't consider current fueling station
//                 dp[i][j] = dp[i-1][j];
                
//                 if(dp[i-1][j-1] >= stations[i-1][0])
//                     dp[i][j] = max(dp[i-1][j-1]+stations[i-1][1],dp[i][j]); 
//             }
        
//         for(int i=0;i<=m;i++)
//             if(dp[m][i]>=target)
//                 return i;
        
        vector<ll> dp(m+1,0);
        dp[0]=startFuel;
        
        for(int i=1;i<=m;i++)
            for(int j=i;j>=0;j--)
                if(j<m && stations[i-1][0] <= dp[j] )
                    dp[j+1] = max(dp[j+1],dp[j] + stations[i-1][1]);
        
        for(int i=0;i<=m;i++)
            if(dp[i]>=target)
                return i;
        
        return -1;
        
    }
};