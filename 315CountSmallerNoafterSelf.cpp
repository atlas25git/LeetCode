//super naive

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>>aux;
        for(int i=0;i<nums.size();i++)
            aux.push_back({nums[i],i});
        
        sort(aux.begin(),aux.end());
        int n = aux.size();
        vector<int> res(n,0);
        for(int i = n-1;i>-1;i--)
        {
            for(int j=i-1;j>-1;j--)
            {
                if(aux[i].second < aux[j].second)
                    res[aux[i].second]++;
            }
        }
        
        return res;
    }
};