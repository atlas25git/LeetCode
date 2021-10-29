class Solution {
    vector<vector<int>> ans;
    
    public:
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //basicall a backtracking based approach, we'll approach the 
        //particular elements as to be chosen or not.
        sort(nums.begin(),nums.end());
        vector<int> a;
        fill(nums,a,0);
        return ans;
    }
    
    void fill(vector<int>& nums,vector<int> a,int ind)
    {
        //if all the elements covered
        if(ind > nums.size())return;
        if(ind == nums.size())
        {
            ans.push_back(a);
            a.clear();
            return;
        }
        
        //calculating total frequency of current element
        int c=1;
        for(int i=ind+1;i<nums.size();i++)
            if(nums[ind] == nums[i])c++;
        
        //starting from zero to cover the case of not including at all the current element
        //not including
        fill(nums,a,ind+c);
        //including
        for(int i=1;i<=c;i++)
        {   
            for(int j=1;j<=i;j++)a.push_back(nums[ind]);
            fill(nums,a,ind+c);
            for(int j=1;j<=i;j++)a.pop_back();

        }   
    }
};