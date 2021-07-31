class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(!nums.size())return 0;
        int i=0,j=1;
        int n=nums.size();
        while(j<n)
        {
            while(j<n && nums[j] == nums[i])j++;
            if(j<n)
                nums[i+1]=nums[j],
            i++,j++;
        }
        return i+1;
    }
};


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(!nums.size())return 0;
        //basically here our approach is to check for the duplicate posn
        //and mark their count, we'll shift the rest of the arr elements by that places,
        //and we do this over the course of array length
        int i=0,j=i+1;
        
        while(j<nums.size()){
            
            while(j<nums.size() && nums[j] == nums[i])
                j++;
            //i holds the intial posn, after which there were copies
            //j has been crossed to the doman where there are only distinct elements;
            if(j<nums.size())
                nums[i+1] = nums[j],
                i++,j++;
        }
        
        return i+1;
        
        
    }
};


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int i=0,j=i+1;
        
        while(j<nums.size())
        {
            while(j<nums.size() && nums[j] == nums[i])
                j++;
            if(j<nums.size()){
                nums[i+1]=nums[j];
                i++,j++;
            }
        }
        return i+1;
    }
};