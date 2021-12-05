class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0)return vector<int>({-1,-1});
        
        int a = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        int b = upper_bound(nums.begin(),nums.end(),target) - nums.begin();
        
        vector<int> res;
        res.push_back(nums[min((int)nums.size()-1,a)] == target?a:-1);
        // cout<<a<<" "<<b<<"\n";
        res.push_back(nums[max(b-1,0)] == target?b-1:-1);
        return res;
    }
};