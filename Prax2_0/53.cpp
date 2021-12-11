class Solution {
public:
    int maxSubArray1(vector<int>& nums) {
        
        if(nums.size()==1)return nums[0];
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        int sum = dp[0];
        for(int i=1;i<nums.size();i++)
            dp[i] = nums[i]+(dp[i-1]>0?dp[i-1]:0),
            sum = max(sum,dp[i]);
        
        return sum;
    }
    
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1)return nums.front();
        int cs=0,cm=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            cs += nums[i];
            if(cs<0)
                cm = max(cm,nums[i]),cs=0;
            else
                cm = max(cs,cm);
        }
        return cm;
    }
};