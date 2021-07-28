class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> rsum;
        int sum=0;
        int count = 0;
        
        rsum[0] = 1;
        
        for(auto num : nums)
        {
            sum += num;
            int diff = sum-k;
            if(rsum.count(diff))count+=rsum[diff];
            if(rsum.count(sum))rsum[sum]++;
            else rsum[sum]=1;
        }
        return count;
    }
};