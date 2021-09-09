class Solution {
public:
    
    vector<int> nums;
    
    Solution(vector<int>& nums) {
        this->nums.swap(nums);
    }
    
    int pick(int target) {
        int n = nums.size();
        int count = 0;
        int idx = 0;
        for (int i = 0; i < n; ++i) {
            // if nums[i] is equal to target, i is a potential candidate
            // which needs to be chosen uniformly at random
            if (nums[i] == target) {
                // increment the count of total candidates
                // available to be chosen uniformly at random
                count++;
                // we pick the current number with probability 1 / count (reservoir sampling)
                if (rand() % count == 0) {
                    idx = i;
                }
            }
        }
        return idx;
    }
};

//HashMap Based:
class Solution {
private:

    unordered_map<int, vector<int>> indices;

public:
    
    Solution(vector<int>& nums) {
        int l = nums.size();
        for (int i = 0; i < l; ++i) {
            this->indices[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int l = indices[target].size();
        // pick an index at random
        int randomIndex = indices[target][rand() % l];
        return randomIndex;
    }
};