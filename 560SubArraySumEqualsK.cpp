class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> rsum;
        int sum=0;
        int count = 0;
        
        rsum[0] = 1;
        
        for(auto num : nums)
        {   // The idea is that if we can remove a certain 
            //sum from this running sum, and the value is k, then we
            //have a subarray whose sum is k.
            sum += num;
            int diff = sum-k;
            //all the discrete values would be stored
            if(rsum.count(diff))count+=rsum[diff];
            if(rsum.count(sum))rsum[sum]++;
            else rsum[sum]=1;
        }
        return count;
    }
};