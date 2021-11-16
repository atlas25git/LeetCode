class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int lo = 0, hi = m*n;
        
        while(lo<hi)
        {   
            //ksmall(hi) is the loop invariant hence we increase md
            //from lo;
            int md = lo + (hi-lo)/2;
            if(ksmall(md,m,n,k))
                    hi = md;
            else lo = md + 1;
        }
        return lo;
    }
    
    bool ksmall(int md,int m,int n,int k)
    {
        int c=0;
        for(int i=1;i<=m;i++)
            c += min(n,md/i);
        
        return c>=k;
    }
};