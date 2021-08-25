class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        while(i<=j)
        {
            int m = i + (j-i)/2;
            if(nums[m] == target)return m;
            
            if(nums[0]<=nums[m])
            {
                if(nums[0]<=target && target<nums[m])j=m-1;
                else i = m+1;
            }
            else
            {
                if(nums[m]<target && target<=nums.back())i=m+1;
                else j=m-1;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        
        while(i<=j)
        {
            int  m = i + (j-i)/2;
            if(target == nums[m])return m;
            //depending on the position of m
            //writing flows
            if(nums[0]<=nums[m])
            {
                //normal array
                if(nums[0]<=target && target<nums[m])
                    j=m-1;
                else i = m+1;
            }
            else if(nums[0]>nums[m])
            {
                if(nums[m]<target && target<=nums.back())
                        i=m+1;
                else j=m-1;
            }
            
        }
        
        return -1;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
       
        int s = 0;
        int e = nums.size() - 1;
        
        while(s <= e) {
            int m = s + (e - s)/2;
            
            if(target == nums[m]) return m;
            
            else if(nums[s] <= nums[m]) {
                if(nums[s]<= target && target < nums[m]) {
                    e = m - 1;
                }
                else {
                    s = m + 1;
                }
            }
            else {
                if(nums[m]< target && target <= nums[e]) {
                    s = m + 1;
                }
                else {
                    e = m - 1;
                }
            }
        }
        return -1;
    }
};