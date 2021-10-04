class Solution {
public:
    
//     vector<int> dp;
    
//     int minCostClimbingStairs(vector<int>& cost) {
//         //basically the question states that to reach at a certain
//         //step we need to pay the cost enlisted, this might confuse one with 
//         //the fwd cost but isn't
//         //for the last step that's top we can get there through either -1,-2;
//         int n = cost.size();
//         int cost1[n];int i=0;
//         for(auto x: cost)cost1[i++] = x;
//         dp.resize(n);
//         if(!n)return 0;
//         return min(mcr(cost,n-1),mcr(cost,n-2));
//     }
    
//     int mcr(vector<int>&cost,int n)
//     {
//         if(n<0)return 0;
//         if(n==0 || n==1)return cost[n];
//         if(dp[n])return dp[n];
//         return dp[n] =cost[n] + min(mcr(cost,n-1),mcr(cost,n-2));
        
//     }
    //dp based
//      int minCostClimbingStairs(vector<int>& cost){
//          vector<int> dp(cost.size(),INT_MAX);
//          dp[0] = cost[0];
//          dp[1] = cost[1];
         
//          for(int i=2;i<cost.size();i++)
//              dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
        
//          return min(dp[cost.size()-1],dp[cost.size()-2]);
//      }
    
    //space optimization as we just need 2 previous states to decide about the present one
    int minCostClimbingStairs(vector<int>& cost){
         int f=0,s=0;
         f = cost[0];
         s = cost[1];
         if(cost.size()<=2)return min(f,s);
         
        for(int i=2;i<cost.size();i++)
        { int cr  = cost[i] + min(f,s);
             f=s,s=cr;
        }
         return min(f,s);
     }
};

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+2,INT_MAX);
        
        dp[0]=0;
        dp[1] = 0;
        dp[2] = 0;
        dp[3] = min(dp[1]+cost[0],cost[1] + dp[2]);
        
        for(int i=4;i<=cost.size()+1;i++)
            dp[i] = min(dp[i-2] + cost[i-3],dp[i-1] + cost[i-2]);
        return dp[cost.size()+1];
    }
};