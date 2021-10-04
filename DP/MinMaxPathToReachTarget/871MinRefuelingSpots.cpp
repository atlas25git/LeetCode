#define ll long 
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& s) {
        //what we basically do here is that we maintain a dp array consisting of k values
        //these k are equal to the number of gas Stations.
        //We basically do a brute force computation for every fuel stop, in increasing manner
        //and keep of upgrading the maximum distance reachable by the car adding this
        //fuel stop too into the count
        int n = s.size();
        vector<ll> dp(s.size()+1);
        
        //distance reachable from starting point
        dp[0] = startFuel;
        
        for(int i=0;i<n;i++)
            for(int k=i;k>-1;k--)
                if(dp[k]>=s[i][0])//station is reachable
                    dp[k+1] = max(dp[k+1],dp[k]+(ll)s[i][1]);
        
        for(int i=0;i<=n;i++)
            if(target<=dp[i])return i;
        
        return -1;
    }
};