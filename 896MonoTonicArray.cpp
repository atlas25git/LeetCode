class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        
        bool iN=false,dN=false;
        int n = nums.size()-1;
        for(int i=0;i<n;i++)
                if(nums[i]>nums[i+1])
                        iN=true;
        
        for(int i=0;i<n;i++)
                if(nums[i]<nums[i+1])
                        dN=true;
        
        if(iN && !dN || !iN && dN || !iN && !dN)return true;
        return false;
    }   
};