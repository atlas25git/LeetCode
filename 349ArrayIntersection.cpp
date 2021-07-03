class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if(nums1.size()>nums2.size())
        {   
            for(auto x:nums2)
            {
                if(find(nums1.begin(),nums1.end(),x)!=nums1.end())
                        if(find(res.begin(),res.end(),x)==res.end())res.push_back(x);
            }
        }
        else
        {   
            for(auto x:nums1)
            {
                if(find(nums2.begin(),nums2.end(),x)!=nums2.end())
                    if(find(res.begin(),res.end(),x)==res.end())res.push_back(x);
            }
        }
     
        return res;
    }
};