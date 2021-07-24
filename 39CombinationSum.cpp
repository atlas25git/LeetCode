class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        fill(res,curr,0,candidates,target);
        return res;
    }
    void fill(vector<vector<int>>& res, vector<int> curr,int ind, vector<int>& cand,int target)
    {
        //base case
        if(!target)
        {
            res.push_back(curr);
            return;
        }
        
        if(target<0 || ind>=cand.size())
                return;
        
        //considering elment at ind
        curr.push_back(cand[ind]);
        fill(res,curr,ind,cand,target-cand[ind]);
        
        //backTrack
        curr.pop_back();
        fill(res,curr,ind+1,cand,target);
    }
};