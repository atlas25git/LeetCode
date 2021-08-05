class Solution {
public:
    vector<int> sums;
    
    Solution(vector<int>& w) {
        //since the probabilistic value here proportional to arr sum
        //thus we maintain a range wise sum and proportional to random 
        //generated value we look up for the index in sum array
        sums.resize(w.size());
        int sum=0;
        for(int i=0;i<w.size();i++)
            sum += w[i],
            sums[i] = sum;
        
    }
    
    int pickIndex() {
        
        //generating random no:
        int target = 1 + rand()%(sums[sums.size()-1]);
        //mod will generate values in accordance with 1 shifted range
        //as 0,n-1 are generated in o/p mapping of %n    
        return (lower_bound(sums.begin(),sums.end(),target) - sums.begin());
        
        
        
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

#define ll long long
class Solution {
public:
    vector<long long> sums;
    Solution(vector<int>& w) {
        sums.resize(w.size());
        ll sum = 0;
        for(int i=0;i<w.size();i++)
            
        {   sum+=w[i];
            sums[i] = sum;
        }
    }
    
    int pickIndex() {
        
        ll target = 1+ rand()%(sums[sums.size()-1]);
        //if(target==0)target++;
        ll start = 0;
        ll end = sums.size()-1;
        
        while(start<end)
        {
            ll mid = start + (end-start)/2;
            if(sums[mid] == target)return mid;
            else if(sums[mid]>target)
            {
                end = mid;
            }else start = mid +1;
            
        }
    return start;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */