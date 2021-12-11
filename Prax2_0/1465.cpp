class Solution {
public:
    int maxArea(int h, int w, vector<int>& hC, vector<int>& vC) {
        
        auto getmax = [](vector<int>& cuts,int len) -> int
        {
            sort(cuts.begin(),cuts.end());
            int maxL = INT_MIN;
            int n = cuts.size();
            maxL = max(cuts[0],len - cuts.back());
            for(int i=1;i<cuts.size();i++)
                maxL = max(maxL,cuts[i]-cuts[i-1]);
            return maxL;
        };
        
        int ans = ((long)getmax(hC,h)*getmax(vC,w))%((int)1e9+7);
        return ans;
    }
};