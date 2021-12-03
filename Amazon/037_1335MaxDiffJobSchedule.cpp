//Approach: 
//The idea is here to check for each index i {0,jd.size()}.
//At i we discern the max till that point, and add it to the optimal such subRes
//calculated on sub problem, out of all such partitions we store the minimum.

class Solution {
    int n,d;
    vector<vector<int>> memo;
public:
    int minDifficulty(vector<int>& jd, int d) {
        n = jd.size();
        this->d = d;
        memo.resize(n,vector<int>(d+1,-1));
        //we need days on 1 based index
        fill(0,d,jd);
        
        return memo[0].back() == INT_MAX?-1:memo[0].back();
    }
    
    int fill(int ind,int d,vector<int>& jd)
    {
        if(ind == n && d==0)return 0;
        if(ind == n || d==0)return INT_MAX;
        
        if(memo[ind][d]!=-1)return memo[ind][d];
        
        int cm = INT_MIN;
        int res = INT_MAX;
       
        for(int i=ind;i<n;i++)
        {
            cm = max(cm,jd[i]);
            int subRes = fill(i+1,d-1,jd);
            if(subRes != INT_MAX)
                res = min(res,cm+subRes);
        }
        
        return memo[ind][d] = res;
    }
};