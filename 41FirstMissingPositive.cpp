class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int>m(nums.size()+1);
        int  one = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 1)one=1;
            if(nums[i]<1 || nums[i]>nums.size())nums[i]=1;
            m[nums[i]]++;
        }
        
        if(!one)return 1;
        
        for(int i=1;i<m.size();i++)
                if(!m[i])return i;
        
        return nums.size()+1;
    }
};