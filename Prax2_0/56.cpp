//TC: O(NlogN) + O(N) ~ O(NlogN);
//SC: O(N), considering merge sort.

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        for(auto x: intervals)
        {   
            //case of no merge straight addn
            if(ans.empty() || ans.back()[1]<x[0])
                    ans.push_back(x);
            else
                //2,5 :: 3,4 => 2,5
                //2,4 :: 3:5 => 2,5
                ans.back()[1] = max(ans.back()[1],x[1]);
        }
        return ans;
    }
};