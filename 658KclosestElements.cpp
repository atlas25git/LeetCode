int y;


class Solution {
public:
    
    static bool cmp(int a,int b)
    {   
        //cout<<y<<endl;
        if(abs(a-y) == abs(b-y))
            return a<b;
        return abs(a-y)<abs(b-y);
    }
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        y = x;
        sort(arr.begin(),arr.end(),cmp);
        arr.resize(k);
        sort(arr.begin(),arr.end());
        return arr;
    }
};