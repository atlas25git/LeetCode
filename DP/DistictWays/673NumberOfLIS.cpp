class Solution {
public:
    int findNumberOfLIS1(vector<int>& nums) {
        int n = nums.size();
        //dp[i]: {length, number of LIS which ends with nums[i]}
        vector<pair<int,int>> dp(n,{1,1});
        
        int res=0,ml=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j]){
                    //longest subsequence as the one earlier stored would've been 
                    //dp[j]+1, and hence if it's repeated hence it's a repeated LIS
                    if(dp[i].first == dp[j].first+1)dp[i].second += dp[j].second;
                    //in the search space prior to i'th element we encountered LIS of greater len
                    if(dp[i].first < dp[j].first + 1)dp[i] = {dp[j].first+1,dp[j].second};
                }
            }
                //storing in ml the max len yet encountered of LIS's and in result we thus 
                //store the sum of such LIS's
                if(ml == dp[i].first)res+=dp[i].second;
                if(ml < dp[i].first)
                {
                    ml = dp[i].first;
                    res = dp[i].second;
                }
            } 
        
        return res;
    }
    
    int findNumberOfLIS(vector<int>& nums){
        vector<pair<int,int>> dp(nums.size(),{1,1});
       //we're intializing with 1,1 as we need to use lenghts in calculation
        int n = nums.size();
        //dp[i].first -> len of LIS ending with i
        //dp[i].second -> total number of LIS's ending with i
        int ml=0,res=0;
        for(int i=0;i<n;i++)
        { 
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    if(dp[i].first == dp[j].first + 1)dp[i].second+=dp[j].second;
                    if(dp[i].first < dp[j].first + 1)
                            dp[i].first = dp[j].first+1,
                            dp[i].second = dp[j].second;
                }
                
            }
            if(ml == dp[i].first)res+=dp[i].second;
            if(ml < dp[i].first)
            {
                ml = dp[i].first;
                res = dp[i].second;
            }
            
        }  
        return res;
    }
};