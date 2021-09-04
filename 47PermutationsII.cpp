class Solution {
public:
    
    void fill(vector<int> nums,vector<int> tmp,vector<bool>& vis,vector<vector<int>>&res)
    {
        if(tmp.size() == nums.size())
        {
            res.push_back(tmp);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(vis[i])continue;
            if(i>0 && nums[i-1] == nums[i] && !vis[i-1])continue;
            vis[i]=true;
            tmp.push_back(nums[i]);
            fill(nums,tmp,vis,res);
            vis[i] = false;
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> tmp;
        vector<bool> vis(nums.size());
        fill(nums,tmp,vis,res);
        return res;
    }
};

class Solution {
public:
    
    void fill(vector<int> nums,vector<int> tmp,vector<bool>& vis,vector<vector<int>>&res)
    {
        if(tmp.size()==nums.size())
        {
            res.push_back(tmp);
            return;
        }
        for(int j=0;j<nums.size();j++)
        {
            if(vis[j])continue;
            if(j>0 && nums[j-1]==nums[j] && !vis[j-1])continue;
            tmp.push_back(nums[j]);
            vis[j] = true;
            fill(nums,tmp,vis,res);
            tmp.pop_back();
            vis[j]=false;
        }
    }
    
    vector<vector<int>> permuteUniqaue(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> tmp;
        vector<bool> vis(nums.size());
        fill(nums,tmp,vis,res);
        return res;
    }
};