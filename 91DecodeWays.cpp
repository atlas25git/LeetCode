class Solution {
public:
    int numDecodings(string s) {
        //simple array based dp solution,
        //dp[i] -> total no of ways to decode 
        //with len i, dp[0]=1, for the base case for len=2
        //the part of calculation here is that if
        //for a given i, though there'll be as many 
        //combination as i-1, and also if the preceeding 2 chars form
        //some commbination of less than 26 then dp[i-2] ways
        //would also be added
        int n = s.size();
        if(s.empty() || s[0]=='0') return 0;
        vector<int>dp(n+1,0);
        //base cases
        dp[0]=1;//as we ensured that first char is non zero
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {   
            //if the preceeding element is 0, then that's used by the i-2th 
            //element, thus to avoid redundant count we skip this.
            if(s[i-1]!='0')
            dp[i] += dp[i-1];
            
            //same is the case here if i-2th char is 0, thus
            //it is in conjunction with the i-1th thus a redundant
            //addn
            if(s[i-2]!='0')
                if(stoi(s.substr(i-2,2)) <27)
                    dp[i] += dp[i-2];
        }
        return dp[n];
    }
};