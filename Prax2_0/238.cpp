class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        pair<int,int> cntZ;
        for(int i=0;i<nums.size();i++)if(!nums[i])cntZ.first++,cntZ.second = i;
        if(cntZ.first>1)return res;
        
        if(cntZ.first == 1)
        {   int pro1 = 1;
            for(auto x: nums)if(x)pro1*=x;
            res[cntZ.second] = pro1;
         return res;
        }
        
        int pro = accumulate(nums.begin(),nums.end(),1,[](int a,int b){return a*b;});
        
        for(int i=0;i<nums.size();i++)
        {
            res[i] = pro/nums[i];
        }
        return res;
    }
};