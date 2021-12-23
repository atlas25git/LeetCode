class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int ls = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(ls == sum-nums[i])return i;
            sum-=nums[i],ls+=nums[i];
        }
        return -1;
    }
};