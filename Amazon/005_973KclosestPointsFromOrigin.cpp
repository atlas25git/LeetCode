class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        auto sd = [](vector<int>& point){return point[0]*point[0] + point[1]*point[1];};
        
        for(int i=0;i<points.size();i++)
        {
            pair<int,int> entry = {sd(points[i]),i};
            if(pq.size()<k)
                pq.push(entry);
            else if(entry.first < pq.top().first)
            {
                pq.pop();
                pq.push(entry);
            }
        }
        
        vector<vector<int>> ans;
        while(!pq.empty())
        {
            int eInd = pq.top().second;
            pq.pop();
            ans.push_back(points[eInd]);
        }
        return ans;
    }
    vector<vector<int>> kClosest1(vector<vector<int>>& points, int k) {
        auto sd = [](vector<int>& point){return point[0]*point[0] + point[1]*point[1];};
        sort(points.begin(),points.end(),[sd](vector<int>& a,vector<int>& b){return sd(a)<sd(b);});
        return vector<vector<int>>(points.begin(),points.begin()+k);
    }

};