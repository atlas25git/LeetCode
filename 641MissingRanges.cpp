class Solution {
public:
    /*
     * @param nums: a sorted integer array
     * @param lower: An integer
     * @param upper: An integer
     * @return: a list of its missing ranges
     */
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
        if(!nums.size()){
            if(lower==upper)return {to_string(lower)};
            return {to_string(lower)+"->"+to_string(upper)};
        }

        vector<string> res;
        long long prev = lower-1;//used -1 as in b/w arr we'll qoute range excluding it's boundary elements
        for(int i=0;i<=nums.size();i++){
            long long curr = (i==nums.size())?upper+1:nums[i];
            if(curr-prev>=2)
            {
                if(prev+1 == curr-1)
                    res.push_back(to_string(prev+1));
                else
                    res.push_back(to_string(prev+1)+"->"+to_string(curr-1));
            }
            prev = curr;
        }
    return res;
    }
};

class Solution {
public:
    /*
     * @param nums: a sorted integer array
     * @param lower: An integer
     * @param upper: An integer
     * @return: a list of its missing ranges
     */
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
        // write your code here
        if(nums.size()==0){
            if(lower==upper)return {to_string(lower)};
            return {to_string(lower)+"->"+to_string(upper)};
        }
         vector<string> res;
        long long prev = lower - 1;
        for (int i = 0; i <= nums.size(); i++) {
            long long curr = (i == nums.size()) ? upper + 1 : nums[i];
            if (curr - prev >= 2) {
                if (prev + 1 == curr - 1)
                    res.push_back(to_string(prev + 1));
                else
                    res.push_back(to_string(prev + 1)+"->"+to_string(curr - 1));
            }
            prev = curr;
        }
    return res;
    }
};