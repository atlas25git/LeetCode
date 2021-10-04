class Solution {
public:
    int minSteps(int n) {
        //dp[i] denotes min operations needed to perform in need to produce i*a
        //now we discern the sequence of operations, it'd end at P
        //and there must be some C in b/w so as to produce the sequence
        //with and exception of n==1, with this case corressponding to 0 ops
        //hence the sequence of operations would contain one c and would end with a p
        
        //recurrence relation:
        //let's say j is the len of As when last C op was done
        //dp[i] = dp[j] + 1 copy aLL + (i-j)/j pastes
        //since we do not know when to perform the last C thus we explore all the options
        //and store the minimum possible result
        //and since we want the number of operations be integral thus we check if i is divisor of k
        
        //Recurrence:
        //dp[i] = min(dp[j] + (j-k)/k + 1) where 1<=i<k && k%i==0
         
        vector<int> dp(n+1,INT_MAX);
        dp[1] = 0;
        for(int k=2;k<=n;k++)
            for(int i=1;i<k;i++)
                if(!(k%i))
                dp[k] = min(dp[k],dp[i] + (k-i)/i + 1);
        return dp[n];
    }
};