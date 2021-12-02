class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        //freq map
        unordered_map<string,int> m;
        for(auto x: words)
            m[x]++;
        
//         vector<vector<string>>bucket(words.size());
        
//         for(auto x: m)
//         {
//             bucket[x.second].push_back(x.first);
//         }
        
//         vector<string> res;
        
//         for(int i = bucket.size()-1;i>0 && k>0;i--)
//         {
//             if(bucket[i].size() == 0)continue;
//             int n = min((int)bucket[i].size(),k);
//             res.insert(res.end(),bucket[i].begin(),bucket[i].begin()+n);
//             k -= n;
//         }
//         return res;
        auto cmp = [](pair<string,int> a, pair<string,int> b){if(a.second == b.second)return a.first>b.first;return a.second<b.second;};
        priority_queue<pair<string,int>,vector<pair<string,int>>,decltype(cmp)> pq(cmp);
        for(auto x: m)
            pq.push(x);
        
        vector<string> res;
        
        while(k--)
        {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};