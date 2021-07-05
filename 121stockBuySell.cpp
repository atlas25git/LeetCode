class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1)return 0;
        vector<int> nextg8(prices.size());
        nextg8[prices.size()-1] = prices[prices.size()-1];
        
        for(int i=prices.size()-2;i>=0;i--)
            nextg8[i]=max(nextg8[i+1],prices[i]);
        
        //for(auto x:nextg8)cout<<x<<" : ";
        
        int ans = INT_MIN;
        for(int i=0;i<prices.size();i++)
            ans= max(ans,nextg8[i]-prices[i]);
        
        return ans;
    }
};