//without hashmap
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<3)return res;
        int i=0;
        int j=i+1;
        int k=nums.size()-1;
        sort(nums.begin(),nums.end());
        
        while(i<nums.size()-1)
        {
            while(j<nums.size() && k>j)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum==0)
                {   //cout<<"sum000"<<endl;
                    vector<int> res1 = {nums[i],nums[j],nums[k]};
                    res.push_back(res1);
                    j++;
                    k--;
                    while(j<nums.size() && nums[j] == nums[j-1])j++;
                    
                    //compared with k not with j coz, it's the og range and j is the bool check
                    //here k and k+1 coz we need to get the first different element
                    while(k>i && nums[k] == nums[k+1])k--;

                }
                else if(sum<0)j++;
                else k--;
                
            }
            i++;
            while(i<nums.size() && nums[i-1]==nums[i])i++;
            j=i+1;
            k=nums.size()-1;
        }
        return res;
    }
};



//Hashmap based solution:
class Solution {
public:
    
    const int size = 3;
    const int target = 0; 
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_set<string> s;
        
        if(nums.size()<3)return res;
        sort(nums.begin(),nums.end());
        int i=0;
        int k=i+1;
        int j = nums.size()-1;
        //iteratively selects i among [0,n] and for k=i+1 to j=n-1
        //computes and stores sum for the given taget
        //to assure the uniqueness a seen set is maintained.
        while(i<nums.size()-1)
        {
            while(k<nums.size() && k<j)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum==target){
                    string key = to_string(nums[i]) + to_string(nums[j]) + to_string(nums[k]);
                    if(s.find(key)==s.end())
                    {   vector<int> x = {nums[i],nums[j],nums[k]};
                        res.push_back(x);
                        s.insert(key);
                    }
                k++;
                j--;
               }
              else if(sum<target)k++;
              else j--;              
            }
            i += 1;
            k = i+1;
            j=nums.size()-1;
        }
        return res;
    }
};