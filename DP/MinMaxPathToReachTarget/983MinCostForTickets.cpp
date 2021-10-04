class Solution {
public:
    vector<int>dp;
    //recursive approach
    int mincostTicketsMemo(vector<int>& days, vector<int>& costs) {
        dp.resize(367);
        return solve(days,costs,0);
    }
    
    int solve(vector<int>& days,vector<int>& costs,int si)
    {
        int n = days.size();
        if(si>=n)return 0;
        if(dp[si])return dp[si];
        int cd = costs[0] + solve(days,costs,si+1);
        int i;
        for(i=si;i<n && days[i]<days[si]+7;i++);
        
        int cw = costs[1] + solve(days,costs,i);
        
        for(i=si;i<n && days[i]<days[si]+30;i++);
        
        int cm = costs[2] + solve(days,costs,i);
        
        return dp[si] = min({cd,cw,cm});
    }
    
    int mincostTickets(vector<int>& Days, vector<int>& cost) {
        unordered_set<int> days(Days.begin(),Days.end());
        vector<int> dp(367);
        
        for(int i=1;i<366;i++)
        {
            dp[i] = dp[i-1];
            if(days.find(i)!=days.end())
            {
                dp[i] = min({dp[i-1]+cost[0],
                            dp[max(0,i-7)]+cost[1],
                                dp[max(0,i-30)] + cost[2]});
            }
            
        }
        return dp[365];
    }
};