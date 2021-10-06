class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        //the problem could be reduced to simple
        //ordered set count that'd make up  given sum
        //if for the given arr, we can discern that sum/2
        //is present as a descrete set, thus is the negation of total set
        //a valid sum/2 round up
        
        int sum=0;
        for(auto x: nums)sum+=x;
        if(sum%2)return false;
        
        vector<vector<bool>>dp(2,vector<bool>(sum+1,0));
        
        //filling up the array
        for(int i=0;i<=nums.size();i++)
            for(int j=0;j<=sum;j++)
            {
                if(!j)
                    dp[i%2][j]=true;
                else if(!i)
                    dp[i%2][j]=false;
                else if(nums[i-1]<=j)
                    dp[i%2][j] = dp[(i+1)%2][j]
                                || dp[(i+1)%2][j-nums[i-1]];
                else dp[i%2][j] = dp[(i+1)%2][j];
            }
        return dp[1][sum/2];
    }
};