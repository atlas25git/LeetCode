class Solution {
public:
    //NLog(sum - sum/days)
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = accumulate(weights.begin(),weights.end(),0);
        
        //BS
        int l = sum/days,h=sum;
        int minSize = INT_MAX;
        while(l<=h)
        {
            int m = l + (h-l)/2;
            if(isValid(m,weights,days))
                {   
                    // cout<<m<<"\n";
                    minSize = min(minSize,m);
                    h = m-1;
                }
            else l = m+1;
        }
        return minSize;
    }
    
    bool isValid(int m,vector<int> weights,int days)
    {
        int cur = 0;
        int dReq=1;
        for(auto x: weights)
        {   if(m<x)return false;
            if(cur+x<=m)
                cur+=x;
            else 
                dReq++,
                cur = x;
            if(dReq>days)return false;
        }
        return dReq<=days;
    }
};