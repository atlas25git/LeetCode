// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int strt = 1;
        int mid = n;
        int end = n;
        if(!isBadVersion(n))return n;
        while(1)
        {
            mid = (strt) + (end-strt)/2;
            
            if(!isBadVersion(mid) && mid<n && isBadVersion(mid+1))
                return mid+1;//since mid is last not bad
            else if(mid==1 && isBadVersion(mid))return mid;
            else if(!isBadVersion(mid))
                strt=mid+1;
            else
                end=mid-1;
            
        }
    }
};