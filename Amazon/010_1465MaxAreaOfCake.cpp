class Solution {
public:
    
    int gM(int hh,vector<int>& h)
    {
        sort(h.begin(),h.end());
        int nh = h.size();
        int mh = max(hh-h[nh-1],h[0]);
        
        for(int i=1;i<nh;i++)
            mh = max(mh,h[i]-h[i-1]);
        return mh;
    }
    
    int maxArea(int h, int w, vector<int>& hh, vector<int>& ww) {
        return (int)((long)gM(h,hh)*gM(w,ww)%((long)1e9+7));
    }
};