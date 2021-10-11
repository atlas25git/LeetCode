class Solution {
public:
    int m = 1e9+7;
    unordered_map<string,int> memo;
    
    int numRollsToTarget(int d, int f, int target) {
        //return ways(d,f,target);
        vector<int> dp(target+1,0);
        dp[0] = 1;
        
        for(int i=1;i<=d;i++)
        {
            vector<int> dp1(target+1);
            for(int j=1;j<=f;j++)
                for(int k=j;k<=target;k++)
                    dp1[k] = (dp1[k] + dp[k-j])%m;
            swap(dp,dp1);
        }
        return dp[target];
    }
    
    int ways(int d,int f,int target,int res=0)
    {
        if(!d || target<=0){
            if(!d)
                return target == 0;
            else return 0;
        }
        if(memo.count(to_string(target) + " " + to_string(d)))
            return memo[to_string(target) + " " + to_string(d)];
        
        for(int i=1;i<=f;i++)
            res = (res+ways(d-1,f,target-i))%m;
        return memo[to_string(target) + " " + to_string(d)] = res;
    }
    
};