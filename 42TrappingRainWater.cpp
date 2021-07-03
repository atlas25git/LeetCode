class Solution {
public:
    int trap(vector<int>& height) {
        if(!height.size())return 0;
        vector<int> l(height.size(),0);
        vector<int> r(height.size(),0);
        
        int water=0;
        l[0]=height[0];
        for(int i=1;i<height.size();i++)
        {
            l[i]=max(l[i-1],height[i]);
        }
        
        r[height.size()-1]=height[height.size()-1];
        for(int i=height.size()-2;i>=0;i--)
        {
            r[i]=max(r[i+1],height[i]);
        }
        for(int i=0;i<height.size();i++)
        {
            water += max(0,min(l[i],r[i])-height[i]);
        }
        return water;
        
    }
};