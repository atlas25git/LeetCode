class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-1;
        
        while(i>0)
        {
            if(nums[i-1] >= nums[i])
                    i--;
            else{
                int j = nums.size()-1;
                while(j>i-1)
                {
                    if(nums[j] > nums[i-1])
                    {
                        int temp = nums[j];
                        nums[j]=nums[i-1];
                        nums[i-1]=temp;
                    
                        reverse(nums,i,nums.size()-1);
                        return;
                    }
                    else j--;
                }
            }
            
        }
        reverse(nums,0,nums.size()-1);
    }
    
    void reverse(vector<int>& nums,int i,int j)
    {
        while(i<j)
        {
            int temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
            i++;
            j--;
        }
        return;
    }
};

class Solution {
public:
    
    void rev(vector<int>& nums,int i,int j)
    {
        while(i<j){
            
            int t = nums[i];
            nums[i]= nums[j];
            nums[j] = t;
            i++,j--;
        }
        return;
    }
    
    void nextPermutation(vector<int>& nums) {
        //simple pattern look up
        //we see if the array is decreasing, we'll just reverse the array
        //else for the next greater permutation we scan for the index such that
        //it's farthest:: coz we need to give lexicographically next increasing, 
        //hence farther it is the smaller the increasing squence becomes.
        //from start and is first occr in decreasing fashion
        //arr[i-1]<arr[i]
        //now in the remaining array we'll find first larger next value
        //since we've covered end to i, checking for the condn such that arr[i-1]>arr[i] is the last one from right
        //hence all beyond i in the sub part are arr[i-1]<arr[i] compliance
        //now we'll replace this i and j, and will reverse the subpart consisting of i+1,end
        //as it'll be decreasing sorted intially
        
        int n = nums.size()-1;
        int i = nums.size()-1;
        
        while(i>0)
        {
            if(nums[i-1]>=nums[i])i--;
            else
            {
                //first from left, and last from right i such that arr[i-1]>arr[i]
                int j = n;
                while(j>i-1)//since we need to find first greater no, than i
                {
                    if(nums[j]>nums[i-1])
                    {
                        //first occr from ri8
                        int t = nums[j];
                        nums[j]  = nums[i-1];
                        nums[i-1] = t;
                        rev(nums,i,n);
                        return;
                    }
                    else j--;
                }
            }
        }
        
        rev(nums,0,n);
        return;
    }
};