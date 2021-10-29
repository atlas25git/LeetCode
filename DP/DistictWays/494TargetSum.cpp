class Solution {
public:
    // map<pair<int,int>,int> memo;
    int offset = 0;
    vector<vector<int>> dp;
    
    int findTargetSumWays1(vector<int>& nums, int target) {
     
        for(auto x: nums)offset+=x;
        dp.resize(nums.size()+1,vector<int>(2*offset+1,INT_MIN));
        
        
        
        
        // return dp[nums.size()][offset+target];
        return recft(nums,target,0,0);
    }
    
    int recft(vector<int>& nums, int target,int i,int sum)
    {
        if(i==nums.size())
        {
            if(target == sum)return 1;
            else return 0;
        }
        // if(memo.count({i,sum}))return memo[{i,sum}];
           if(dp[i][offset + sum]!=INT_MIN)return dp[i][offset+sum];

        return dp[i][offset + sum] = 
                recft(nums,target,i+1,sum+nums[i]) +                                                                                     recft(nums,target,i+1,sum-nums[i]);
    }
    
    int findTargetSumWays(vector<int>& nums, int target){
        
        int n = nums.size();
        vector<unordered_map<int,int>> dp(n+1);
        dp[0][0] = 1;
        //dp[i][j]
        //here states no of ways to make a sum of j using i members
        //this is a demonstration of discontinuous dp;
        for(int i=0;i<n;i++)
            for(auto &p: dp[i]){
                //here p.first -> is the initial sum which was present
                //with it we're creating sum that'd be formed with +/- of item in consideration
                //and thus we'll check all in all how many such combinations are possible
                //by mapping it's frequency to the sum
                dp[i+1][p.first + nums[i]] += p.second;
                dp[i+1][p.first - nums[i]] += p.second;
            }
        
        return dp[n][target];
    }

};

