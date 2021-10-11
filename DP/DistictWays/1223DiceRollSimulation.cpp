class Solution {
public:
    int m = 1e9+7;
    vector<vector<vector<int>>> memo;
    
    int dieSimulator(int n, vector<int>& rollMax) {
        memo.resize(5000,vector<vector<int>>(6,vector<int>(16,0)));
        return rec(n,rollMax,-1,0);

    }
    
    int rec(int dieLeft, vector<int>& rM,int last,int cl,int ans=0)
    {
        if(!dieLeft){
            return 1;
        }
        if(last>=0 && memo[dieLeft][last][cl])return memo[dieLeft][last][cl];
        
        for(int i=0;i<6;i++){
            if(i==last && cl == rM[i])continue;
            ans = (ans + rec(dieLeft-1,rM,i,i == last?cl+1:1))%m;
        }
        if(last>=0)memo[dieLeft][last][cl] = ans;
        return ans;
    }
};