class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> mp;
        for(auto x: arr)
            mp[x]++;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto x: mp)pq.push(x.second);
        
        while(k>0)
        {   
            if(k>=pq.top())
                k -= pq.top(),
                pq.pop();
            else break;
        }
        return pq.size();
    }
};