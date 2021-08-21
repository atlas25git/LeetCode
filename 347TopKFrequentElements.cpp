class Solution {
public:
    
    struct cmp{
        bool operator()(pair<int,int> p1, pair<int,int> p2)
        {
            if(p1.second == p2.second)return p1.first<p2.first;
            return p1.second<p2.second;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        for(int i=0;i<nums.size();i++)um[nums[i]]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq(um.begin(),um.end());
        
        vector<int> temp;
        while(k--)temp.push_back(pq.top().first),pq.pop();
        return temp;
    }
};