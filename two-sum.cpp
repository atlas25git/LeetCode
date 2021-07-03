class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     
        //sort(nums.begin(),nums.end());
        vector<int> res;
        int i=0,j=nums.size()-1;
       
//         while(i<j)
//         {
//             if(nums[i] + nums[j] == target )
//             {
//                 res.push_back(i);
//                 res.push_back(j);
//             }
//            else if (nums[i] + nums[j] > target)j--;
//             else i++;
                
//         }
        for(i=0;i<=j;i++)
        {
            for(int k=i+1;k<=j;k++)
            {
                if(nums[i] + nums[k] == target)
                {
                    res.push_back(i);
                    res.push_back(k);
                    break;
                }
            }
        }
        return res;
    }
};