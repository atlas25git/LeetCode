class Solution {
public:
    int guessNumber(int n) {
        //time complexity sugests for binary search
        //range : 1,n
        if(!guess(n))return n;
        
        int start = 1;
        int end = n;
        //int mid = 1+(n-1)/2;
        
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            
            if(guess(mid) == 0)return mid;
            else if(guess(mid)==1)
            {
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
        }
        return 0;
        
    }
};

class Solution {
public:
    int guessNumber(int n) {
        //time complexity sugests for binary search
        //range : 1,n
        if(!guess(n))return n;
        
        int start = 1;
        int end = n;
        //int mid = 1+(n-1)/2;
        
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            
            if(guess(mid) == 0)return mid;
            else if(guess(mid)==1)
            {
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
        }
        return 0;
        
    }
};