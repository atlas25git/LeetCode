class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tortoise  = nums[0];
        int hare = nums[nums[0]];
        
        while(tortoise!=hare)
        {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        }
        
        tortoise = 0;
        while(tortoise!=hare)
        {
            tortoise= nums[tortoise];
            hare = nums[hare];
        }
        
        return tortoise;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];
        
        while(1)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast)break;
        }
        
        slow =0;
        
        while(slow!=fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};