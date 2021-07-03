class Solution {
public:
    #define ll long long
    int reverse(int x) {
         
        if(x==0)return 0;
        if(x <= INT_MIN || x>=INT_MAX)return 0;
        string res;
        int sign=1;
        if(x<0)
        {
        sign=-1;
         x=x*-1;
        }
        ll reverse=0;
        
        while(x)
        { 
            res+=to_string(x%10);
            x/=10;
            // reverse = reverse * 10 + x % 10;
            // x /= 10;
        }
        // cout<<res<<" "<<res.size();
        // return 0;
        //cout<<INT_MAX<<" "<<INT_MIN;
        if(res.size()>=10 && res[0]>2)return 0;
        ll res2 = sign*stoi(res);
        if(res2 <= INT_MIN || res2>=INT_MAX)return 0;
        return res2;
    }
};