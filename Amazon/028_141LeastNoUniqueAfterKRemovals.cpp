class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> map;
        for_each(arr.begin(),arr.end(),[&map](int a){if(map.count(a))map[a]+=1;else map[a] = 1;});
        auto cmp = [](pair<int,int> a,pair<int,int> b)
      {
          if(a.second == b.second)return a.first>b.first;
          else return a.second>b.second;
      };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
        
        for(auto x: map)
            pq.push(x);
        while(k>0)
        {
            auto x = pq.top();
            if(k>=x.second)
                {
                    k -= x.second;
                    pq.pop();
                }
            else break;
        }
        return pq.size();
    }
};