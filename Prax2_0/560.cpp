class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //it could be done using the idea of storing continuous subarray sums
        //at each index and then do a search for sum-k in the mapping of prefix sums.
        
        //our approach here is to maintain a running sum in the array
        //and store them in a hash map, then at any instance we make a
        //look up if current sume -k is present already, which cold be excluded.
        //and since it is running sum from beginning, even the diff would be proper
        //prefix's
        
        unordered_map<int,int> mp;
        //mp stores the running sums in array
        mp[0] = 1;
        int sum=0,cnt=0;
        for(auto x: nums)
        {
            sum += x;
            if(mp.count(sum-k))cnt+=mp[sum-k];
            mp[sum]++;
        }
        return cnt;
    }
};