class Solution {
public:
    int combinationSum41(vector<int>& nums, int target) {
        vector<unsigned>dp(target+1,0);
        dp[0] = 1;
        
        for(int i=1;i<=target;i++)
            for(int j=0;j<nums.size();j++)
                if(nums[j]<=i)
                    dp[i] += dp[i-nums[j]];
             
        return dp[target];
    }
    unordered_map<int,int> memo;
    int combinationSum4(vector<int>& nums, int target)
    {
        return ways2(nums,target,nums.size());
    }
    
    int ways(vector<int>& nums, int target)
    {
        if(target<0)return 0;
        if(target == 0)return 1;
        if(memo.count(target))return memo[target];
        int res = 0;
        
        for(int i=0;i<nums.size();i++)
            res += ways(nums,target-nums[i]);
        
        return memo[target] = res;
    }
    int ways2(vector<int>& nums,int target,int n)
    {   
        if(target == 0)return 1;
        if(n==0) return 0;
        
        int res = 0;
        res += ways2(nums,target,n-1);
        if(nums[n-1]<=target)
            res += ways2(nums,target-nums[n-1],n);
        
        return res;
    }
};
