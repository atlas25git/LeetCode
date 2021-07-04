class Solution {
public:
    
    int rob1(int n,vector<int> nums,vector<int>& dp)
    {   
        //1. Base case, houses over
        if(n>=nums.size())return 0;
        //checking if the solution has already been computed
        if(dp[n]!=-1)return dp[n];
        
        dp[n] = max(rob1(n+1,nums,dp),//not choosing the first house to rob
                        rob1(n+2,nums,dp)+nums[n]);//chose the first house.
        return dp[n];
    }
    
    int rob2(vector<int> nums)
    {
        vector<int> dp(nums.size(),-1);
        dp[0]=nums[0];
        dp[1]=max(nums[1],nums[0]);
        
        for(int i=2;i<nums.size();i++)
        {
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        }
        return dp[nums.size()-1];
    }
    
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        //return rob1(0,nums,dp);
        if(nums.size()==1)return nums[0];
        return rob2(nums);
    }
};