class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        unordered_map<int,int> count;
        
        for(auto a:ages)count[a]++;
        int res=0;
        
        for(auto a: count)
            for(auto b: count)
                if(request(a.first,b.first))
                    //if for an age x in a, b also corressponds to x
                    //then we'll be having a case where there'd be same count
                    //of the person,as a person can't send req to himself, thus
                    //-1 for the case.
                    res += a.second*(b.second - (a.first == b.first?1:0));
        return res;
    }
    bool request(int a,int b)
    {
        return !(b<=0.5*a+7 || b>a || (b>100 && a<100));
    }
};