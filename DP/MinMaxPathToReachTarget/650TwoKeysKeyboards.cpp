

class Solution {
public:
    unordered_map<string,int> memo;    
    int minSteps1(int n) {
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
        //dp[i] = min(dp[j] + (i-j)/j + 1) where 1<=i<k && i%j==0
         
        vector<int> dp(n+1,INT_MAX);
        dp[1]=0;
        for(int i=2;i<=n;i++)
            for(int j=1;j<=i;j++)
                if(i%j == 0)
                    dp[i] = min(dp[i],dp[j] + 1 + (i-j)/j);
        return dp[n];
    }
    
    int minSteps(int n)
    {
        if(n==1)return 0;
        //We've to offset the number of minimal operations by 1 as initially we're 
        //assuming that we coppied 1 A, to keep it in the buffer or else the paste 
        //procedure won't work
        return steps(1,n,1)+1;
    }
    
    int steps(int current,int total,int buffer)
    {   
        if(current>total)return 1e9;
        if(current == total)return 0;
        
        int C = 2 + steps(2*current,total,current);
        int P = 1 + steps(current + buffer,total,buffer);
        
        return min(C,P);
    }
     
};