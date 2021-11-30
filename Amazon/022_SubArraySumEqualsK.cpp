class Solution {
public:
    int subarraySum1(vector<int>& nums, int k) {
        //our approach here is to maintain a running sum in the array
        //and store them in a hash map, then at any instance we make a
        //look up if current sume -k is present already, which cold be excluded.
        //and since it is running sum from beginning, even the diff would be proper
        //prefix's
        
        unordered_map<int,int> sumP;
        sumP[0]=1;
        int sumI=0;
        int count=0;
        for(auto num: nums)
        {
            sumI += num;
            int df = sumI - k;
            if(sumP.count(df))count += sumP[df];
            if(sumP.count(sumI))sumP[sumI]++;
            else sumP[sumI] = 1;
            
        }
        return count;
    }  
    
    
    int subarraySumAns(vector<int>& nums, int k) {
        unordered_map<int,int> rsum;
        int sum=0;
        int count = 0;
        
        rsum[0] = 1;
        
        for(auto num : nums)
        {   // The idea is that if we can remove a certain 
            //sum from this running sum, and the value is k, then we
            //have a subarray whose sum is k.
            sum += num;
            //if diff as a continuous sum is present thus could be removed
            //it'll be continuous this is a loop variant as assured in our computation style
            //since we're taking a sequential sum
            int diff = sum-k;
            
            //all the discrete values would be stored
            if(rsum.count(diff))count+=rsum[diff];
            if(rsum.count(sum))rsum[sum]++;
            else rsum[sum]=1;
        }
        return count;
    }
    
    int subarraySum(vector<int>& arr, int s) {
        unordered_map<int,int> rs;
        rs[0] = 1;
        int cnt=0,sum=0;
        for(auto x: arr)
        {
            sum+=x;
            if(rs.count(sum-s))cnt+=rs[sum-s];
            if(rs.count(sum))rs[sum]++;
            else rs[sum] = 1;
        }
        return cnt;
    }
};