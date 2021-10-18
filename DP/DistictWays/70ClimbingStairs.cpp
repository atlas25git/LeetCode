class Solution {
public:
    int climbStairs1(int n) {
        vector<int>dp(n+1,0);
        dp[0]=1;
        
        for(int i=1;i<=n;i++)
            for(int j=1;j<=2;j++)
            {
                if(j<=i)
                    dp[i] += dp[i-j];
            }
        // for(auto x: dp)cout<<x<<" ";
        return dp[n];
    }
    unordered_map<int,int> memo;
    int climbStairs(int n){
        return ways(n);
    }
    
    int ways(int n)
    {   
        if(!n)return 1;
        if(n<0)return 0;
        if(memo.count(n))return memo[n];
        return memo[n] = ways(n-1) + ways(n-2);
    }

};