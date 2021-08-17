class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        //Hashmap based solution, using the property that 
        //sum of elements on any diagonal is constant for all it's 
        //elements
        int count =0;
        int maxKey = INT_MIN;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++)
            for(int j=0;j<nums[i].size();j++)
                    mp[i+j].push_back(nums[i][j]),
                    maxKey = max(maxKey,i+j),
                    count++;
    
        vector<int> ans(count);
        int idx = 0;
        
        for(int i=0;i<=maxKey;i++)
            for(int j=mp[i].size()-1;j>-1;j--)
                    ans[idx++]  = mp[i][j];
        
        return ans;
    }
};

//sorting Based
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int m = nums.size();
        if(m == 0) return vector<int>();
        vector<vector<int>> tuples;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < nums[i].size(); j++){
                tuples.push_back({i+j, -i, nums[i][j]});
            }
        }
        
        sort(tuples.begin(), tuples.end());
        
        vector<int> ans(tuples.size());
        
        for(int i = 0; i < ans.size(); i++){
            ans[i] = tuples[i][2];
        }
        
        return ans;
    }
};


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> bucket;
        int maxKey = INT_MIN;
        int count = 0;
        
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums[i].size(); j++){
                bucket[i+j].push_back(nums[i][j]);
                maxKey = max(maxKey, i+j);
                count++;
            }
        }
        
        vector<int> ans(count);
        int idx = 0;
        
        for(int i = 0; i <= maxKey; i++){
            for(int j = bucket[i].size()-1; j >= 0; j--){
                ans[idx++] = bucket[i][j];
            }
        }
        
        return ans;
    }
};