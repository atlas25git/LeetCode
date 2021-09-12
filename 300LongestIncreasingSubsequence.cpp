class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size()+1);
        int len=1;
        dp[1] = nums[0];
        
        for(int i=1;i<nums.size();i++)
        { 
            for(auto x: dp)cout<<x<<" ";

            if(nums[i]>dp[len])
                dp[++len] = nums[i];
            else
            {   
                int ind = lower_bound(dp.begin()+1,dp.begin()+len,nums[i])-dp.begin();
                dp[ind] = nums[i];
                len = max(len,ind);
            }
            cout<<endl;

        }
        for(auto x: dp)cout<<x<<" ";
        return len;
    }
};