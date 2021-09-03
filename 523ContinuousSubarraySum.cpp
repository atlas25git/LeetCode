class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        //the approach is simple, we leverage the fact that
        //for any continuous sum over a range a mod value
        //is repeated only if there exists a multiple of value
        //we're using to mod with
        unordered_set<int> modCount;
        int sum=0;
        int pre = 0;
        //to maintain relative order of sum, as even next 0,
        //would keep the mod same, and hence not a right answer
        for(int i=0;i<nums.size();i++)
        {   
            sum+=nums[i];
            int mod = sum%k;
            if(modCount.count(mod))return true;
            modCount.insert(pre);
            pre = mod;
        }
        return false;
    }
};