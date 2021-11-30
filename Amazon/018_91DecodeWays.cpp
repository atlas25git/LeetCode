class Solution {
    vector<int> dp;
    string s;
public:
    int numDecodings(string s) {
        this->s = s;
        dp.resize(s.size()+1,0);
        // return ways(0);
        if(s[0] == '0' || s.empty())return 0;
        dp[0]=dp[1]=1;
        for(int i=2;i<=s.size();i++)
            {if(s[i-1] != '0')dp[i]+=dp[i-1];
            if(s[i-2] != '0' && stoi(s.substr(i-2,2))<27)
                dp[i]+=dp[i-2];}
        return dp.back();
        
    }
    
    int ways(int ind)
    {
        if(dp[ind] != -1)return dp[ind];
        if(ind == s.size())return 1;
        
        int cntWays=0,num=0;
        for(int i=ind;i<s.size();i++)
        {
            num = num*10 + s[i]-'0';
            if(num>0 && num<27)
                cntWays += ways(i+1);
            else break;
        }
        return dp[ind] = cntWays;
    }
};