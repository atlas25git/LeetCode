class Solution {
public:
    bool wordBreak(string s, vector<string>& wD) {
        unordered_set<string> words(wD.begin(),wD.end());
        int n = s.size();
        //our approach here is to maintain a marker boolean array
        //corressponding to each of the string's char, thus it'll hold true
        //if it could be partitioned at that index with a space
        //running a full search loop, for every index i{1,n-1}
        //j {0,i-1}, it will check for the dp[j] true values
        //and thus will fill up the array
        
        vector<bool> dp(n+1,0);
        dp[0] = 1;
        
        for(int i=1;i<=n;i++)
            for(int j=i-1;j>-1;j--)
            {
                if(dp[j])
                {
                    if(words.count(s.substr(j,i-j)))
                    {
                        dp[i]=1;
                        //breaking the innner loop here as we just need to discern
                        //if partition is possible or not.
                        break;
                    }
                }
            }
        
        return dp[n];
        
    }
};


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> words(wordDict.begin(),wordDict.end());
        int n=s.size();
        
        vector<int> dp(n+1,0);
        dp[0]=1;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=i-1;j>=0;j--){
                if(dp[j]){
                    if(words.count(s.substr(j,i-j)))
                    {
                        dp[i]=1;
                        break;
                    }
                }
            }
        }
        for(auto x: dp)cout<<x<<" "<<endl;
        return dp[n];
    }
};