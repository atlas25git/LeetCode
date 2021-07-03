class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        if(nums.size()==1)return nums[0];
        
        int cs=0,msf=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            cs+=nums[i];
            msf=max(msf,cs);
            if(cs<0)cs=0;
        }
        
        return msf;
    }
};