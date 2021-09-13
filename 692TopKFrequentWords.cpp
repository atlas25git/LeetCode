class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        //freq map
        map<string,int> m;
        for(auto x: words)
            m[x]++;
        
        vector<vector<string>>bucket(words.size());
        
        for(auto x: m)
        {
            bucket[x.second].push_back(x.first);
        }
        
        vector<string> res;
        
        for(int i = bucket.size()-1;i>0 && k>0;i--)
        {
            if(bucket[i].size() == 0)continue;
            int n = min((int)bucket[i].size(),k);
            res.insert(res.end(),bucket[i].begin(),bucket[i].begin()+n);
            k -= n;
        }
        return res;
    }
};