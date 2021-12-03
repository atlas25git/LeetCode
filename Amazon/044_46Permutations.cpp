class Solution {
    vector<vector<int>> res;
    public:
    vector<vector<int>> permute(vector<int>& nums) {
        fill(nums,0);
        return res;
    }
    
    void fill(vector<int>& nums,int ind)
    {
        if(ind>=nums.size())
        {
            res.push_back(nums);
            return;
        }
        
        for(int i=ind;i<nums.size();i++)
        {
            swap(nums[ind],nums[i]);
            fill(nums,ind+1);
            swap(nums[ind],nums[i]);
        }
    }
};