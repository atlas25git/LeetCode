class Solution {
public:
    int numSquares1(int n) {
        //basically the idea here is that our dp[i] will store
        //the min no of squares needed to sum up to it.
        //and hence for every no. i we'll search for all such combinations
        //till its sqrt
        
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=sqrt(i);j++)
                dp[i] = min(dp[i],dp[i-j*j]+1);
        
        return dp[n];
    }
    
    unordered_map<int,int> memo;
    
    int numSquares(int n,int ans = INT_MAX) {
        if(!n)return 0;
        if(n<0)return INT_MAX;
        
        if(memo.count(n))return memo[n];
        
        for(int i=1;i<=sqrt(n);i++)
            ans = min(ans,numSquares(n-i*i)+1);
        
        return memo[n] = ans;
    }
};