class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()<nums2.size())
            swap(nums1,nums2);
        
        vector<int> res;
        for(auto x:nums2)
        {
            if(find(nums1.begin(),nums1.end(),x)!=nums1.end()) 
               //&& find(res.begin(),res.end(),x)==res.end())
            {
                //    int count = upper_bound(nums1.begin(),nums1.end(),x)
                //                 - lower_bound(nums1.begin(),nums1.end(),x);
                // cout<<x<<" "<<count<<endl;
                //while(count--)
                //{
                    res.push_back(x);
                    *find(nums1.begin(),nums1.end(),x)=INT_MAX;
                //}
                
            }   
        }
        return res;
    }
};