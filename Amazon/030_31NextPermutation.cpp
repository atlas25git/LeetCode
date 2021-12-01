//Aproach:
//While traersing from the last index we find the first index where the descending sequence ends.
//That is first pair where nums[i-1]<nums[i]
//swap nums[i-1], with it's upperbound in the arr[i,end];
//reverse the sub part arr[i,end]

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i,j,c=0;
        for(i=nums.size()-1;i>0;i--)
        {
            if(nums[i-1]<nums[i])
            {
                c++;
                j=i-1;
                break;
            }
        }
        
        if(c)
        {
            reverse(nums.begin()+j+1,nums.end());
            int x = upper_bound(nums.begin()+j+1,nums.end(),nums[j]) - nums.begin();
            swap(nums[x],nums[j]);
        }
        else sort(nums.begin(),nums.end());
    }
};