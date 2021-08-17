class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int y = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        return nums[y] == target?y:y;
    }
};