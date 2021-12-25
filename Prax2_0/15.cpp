class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        
        for(int i=0;i<nums.size();)
        {
            int sum = nums[i];
            int j = i+1,k=nums.size()-1;
            while(j<k)
            {
                int sumX  =sum+ nums[j] + nums[k];
                if(!sumX)
                {
                    ans.push_back(vector<int>({nums[i],nums[j++],nums[k--]}));
                    while(j<nums.size() && nums[j-1] == nums[j])j++;
                    while(k>-1 && nums[k+1] == nums[k])k--;
                }   
                else if(sumX > 0)k--;
                else j++;
            }
            i++;
            while(i<nums.size() && nums[i-1] == nums[i])i++;
        }
        
        return ans;
    }
};