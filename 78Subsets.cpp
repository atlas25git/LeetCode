class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int k = nums.size();
        vector<vector<int>> res;
        
        for(int i=0;i<(1<<k);i++)
        {
            int n = i;
            vector<int> tmp;
            int j = 0;
            while(n)
            {
                if(n&1)tmp.push_back(nums[j]);
                j++;
                n>>=1;
            }
            res.push_back(tmp);
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int count = nums.size();
        vector<vector<int>>res;
        
        for(int i=0;i<(1<<count);i++)
        {   
            vector<int> temp;
        
            int j=0;
            int t = i;
            while(t)
            {
                int lb = t&1;
                if(lb)temp.push_back(nums[j]);
                j++;
                t = t>>1;
            }
            res.push_back(temp);
        }
        return res;
    }
};