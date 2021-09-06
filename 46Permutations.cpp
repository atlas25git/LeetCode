class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        fill(nums,0,res);
        return res;
    }
    
    void fill(vector<int> nums,int s,vector<vector<int>>&res)
    {
        if(s>=nums.size())
        {
            res.push_back(nums);
            return;
        }
        
        for(int i=s;i<nums.size();i++)
        {
            swap(nums[s],nums[i]);
            fill(nums,s+1,res);
            swap(nums[s],nums[i]);
        }
        
    }
};