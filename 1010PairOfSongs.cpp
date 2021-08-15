class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        //map based approach
        //for given no x: divisible by 60 if it's mod ==0
        //x%60 != 0 then, we need to add a no which's give it's
        //complementary modi.e 60-(x%60)
        
        unordered_map<int,int> mp;
        
        int count =0;
        
        for(auto x: time)
        {   
            
            if(mp.count((60 - x%60)%60))count+=mp[(60-x%60)%60];
            if(mp.count(x%60)==0)mp[x%60] = 1;
            else mp[x%60]++;
        }
        return count;
    }
};