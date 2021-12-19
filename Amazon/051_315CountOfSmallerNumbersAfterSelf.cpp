class Solution {
    vector<int> res;
    int n;
public:
    vector<int> countSmaller(vector<int>& nums) {
        n = nums.size();
        res.resize(n,0);
        vector<pair<int,int>> aug;
        for(int i=0;i<n;i++)
            aug.push_back({nums[i],i});
        
        mergeSortAug(aug,0,n-1);
        return res;
    }
    
    void mergeSortAug(vector<pair<int,int>>& aug,int l,int h)
    {
        if(l>=h)return;
        int m = l + (h-l)/2;
        
        mergeSortAug(aug,l,m);
        mergeSortAug(aug,m+1,h);
        mergeAug(aug,l,m,h);
    }
    
    void mergeAug(vector<pair<int,int>>& aug,int l,int m,int h)
    {
        vector<pair<int,int>> lt,rt;
        fill(aug,lt,l,m);
        fill(aug,rt,m+1,h);
        
        int i=0,j=0,k=l;
        int rtos = 0;
        
        while(i<lt.size() && j<rt.size())
        {
            if(lt[i] < rt[j])
                aug[k++] = lt[i],
                res[lt[i++].second] += rtos;
            
            else if(lt[i] > rt[j])
                aug[k++] = rt[j++],
                rtos++;
            
            // else i++,j++;
        }
        
        while(i<lt.size())
            res[lt[i].second] += rtos,
            aug[k++]= lt[i++];
        
        while(j<rt.size())
            aug[k++] = rt[j++];
        
        return;
        
    }
    
    void fill(vector<pair<int,int>>& aug,vector<pair<int,int>>& prop,int l,int h)
    {
        for(int i=l;i<=h;i++)
            prop.push_back(aug[i]);
        
        return;
    }
};


class Solution {
    int n;
    vector<int> ind;
public:
    vector<int> countSmaller(vector<int>& nums) {
        n = nums.size();
        vector<pair<int,int>> temp,aug;
        ind.resize(n,0);
        
        for(int i=0;i<n;i++)
            aug.push_back({nums[i],i}),
            temp.push_back({nums[i],i});
        
        mergeSort(0,n-1,aug,temp);
        return ind;
    }
    
    void mergeSort(int start,int end,vector<pair<int,int>>& nums,vector<pair<int,int>>& temp)
    {
        if(start>=end)return;
        int mid = start + (end-start)/2;
        
        mergeSort(start,mid,nums,temp);
        mergeSort(mid+1,end,nums,temp);        
        
        int left = start,right = mid+1;
        int idx = start;
        int nRightLessThanLeft = 0;
        
        while(left<=mid && right <= end)
        {
            if(nums[left] < nums[right])
                ind[nums[left].second] += nRightLessThanLeft,
                temp[idx++] = nums[left++];
            else if(nums[left] > nums[right])
                temp[idx++] = nums[right++],
                nRightLessThanLeft++;
            else 
                left++,right++;
        }
        
        while(left<=mid)
            ind[nums[left].second] += nRightLessThanLeft,
            temp[idx++] = nums[left++];
        
        while(right<=end)
            temp[idx++] = nums[right++];
        
        for(int i=start;i<=end;i++)
                nums[i] = temp[i];
        
    }
};