class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        const int k = 3;
        const int n = nums.size();
        vector<pair<int,int>> sv(k-1,{1e9+7,0});
        
        for(int i=0;i<nums.size();i++)
        {
            int j = 0;
            
            for(j=0;j<k-1;j++)
            {
                if(sv[j].first == nums[i])
                {
                    sv[j].second+=1;
                    break;
                }
            }
            if(j==k-1)//not present
            {   
                j=0;
                for(j=0;j<k-1;j++)
                {
                    if(sv[j].second == 0)
                    {
                        sv[j] = {nums[i],1};
                        break;
                    }
                }
            }
            
            if(j==k-1)//reducing
            {
                j=0;
                for(j=0;j<k-1;j++)
                    if(sv[j].first != nums[i])sv[j].second-=1;
            }
        }
        vector<int> res;
        for(int j=0;j<k-1;j++){
            int x = sv[j].first;
            int count = 0;
            for(auto nm : nums)
            {
                if(nm == x)count++;
            }
            if(count>n/3)res.push_back(x);
        }
        return res;
    }
};