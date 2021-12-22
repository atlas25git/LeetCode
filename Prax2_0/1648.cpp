#define ll long long
int m = 1e9+7;

class Solution {
    map<int,int,greater<int>> mp;
public:
    int maxProfit(vector<int>& inventory, int orders) {
        ll ans = 0, l = 0, r = *max_element(inventory.begin(),inventory.end());
        for(auto x: inventory)mp[x]++;
        //Computing first non optimal low so as to greedily
        //include the max value balls.
        //Proof to the fullfilment of orders is envisaged as our isValid
        //fn return true if current low value is such that, for all the 
        //inventory items greater than it could fulfill the current orders.
        //Hence the first non optimal solution will only fulfill the orders,
        //along with the remainig ones.
        
        auto compute = [](int a,int b) -> ll
        {
            return (b-a) * (ll)(b + a + 1) / 2;
        };
            
        while(l<=r)
        {
            int m = l + (r-l)/2;
            if(isValid(m,orders))
                l = m+1;
            else r = m-1;
        }
        for(auto [f,s] : mp)
        {   
            //Greedy selection complete if:
            if(f<=l)break;
            orders -= s*(f-l);
            ans = (ans%m + s*compute(l,f)%m)%m;
        }
        
        if(orders)ans = (ans%m + orders*l%m)%m;
        return ans;
    }
    
    bool isValid(int m,int orders)
    {
        for(auto [f,s] : mp)
        {
            if(f<=m)break;
            orders -= s*(f-m);
            if(orders<=0)return true;
        }
        return orders<=0;
    }
};