//The basic thought process behind this algorithm is that:
    //We prune the search space.
    //1st criteria: We look for the sorted part, by comparing the extremes.
    //2nd         : Now we check if the sorted part is of any use to us.
//Based on these we keep on pruning the search space.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        
        while(i<=j)
        {
            int m = i + (j-i)/2;
            // cout<<"i "<<i<<" j "<<j<<" m "<<m<<" "<<nums[m]<<"\n";
            if(nums[m] == target)return m;
            
            else if(nums[m]<target)
            {   
                //checking for the sorted part, and skipping the unsorted one
                if(nums[j]>=nums[m])
                {   //deciding if the sorted part is of any use to us.
                    if(nums[j]>=target)
                        i=m+1;
                    else j=m-1;
                }
                else i = m+1;
            }
            else if(nums[m]>target)
            {
                if(nums[i]<=nums[m])
                {
                    if(nums[i]<=target)
                        j=m-1;
                    else i=m+1;
                }
                else j = m-1;
            }
        }
        return -1;
    }
};