class Solution {
public:
    int m = 1e9+7;
    int al;
    unordered_map<string,int> memo;
    // vector<vector<int>> memo;
    
    int numWays(int steps, int arrLen) {
        // memo.resize(steps/2+1,vector<int>(steps+1,-1));
        this->al = arrLen;
        return rec(0,steps);
    }
    
    int rec(int i, int steps)
    {
        if(!steps && !i)return 1;
        
        if(i<0 || i>=al || !steps || i>steps)
                return 0;
        
        if(memo.count(to_string(i) + " " + to_string(steps)))
            return memo[to_string(i) + " " + to_string(steps)];
        // if(memo[i][steps]!=-1)
            // return memo[i][steps];
        
        return memo[to_string(i) + " " + to_string(steps)] = 
        // return memo[i][steps] =
        (
        (rec(i+1,steps-1)%m 
        +
        rec(i-1,steps-1))%m
        +
        rec(i,steps-1))%m;
    }
};