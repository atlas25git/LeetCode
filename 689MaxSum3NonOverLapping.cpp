class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        
        //basically the idea is here to store the win sum for every such starting at ind i
        //and then maintain left and right largest windows, depicting at i the window ind on l/r
        //of it and max in it
        //then performing a complete search storing the max combination for interval windows.
        
        vector<int> win(nums.size()-k+1);
        int sum =0;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            if(i>k-1)//we can delete the first element of existing window
                sum-=nums[i-k];
            if(i>k-2)//on a zero scaled index we can now store win sum vals
                win[i-(k-1)]=sum;
        }
        
        //populating the left array at any index i contains index of largest sum window on it's left
        int j=0;
        vector<int>left(win.size());
        for(int i=0;i<win.size();i++)
        { 
            if(win[i]>win[j])j=i;
            left[i]=j;
        }
        
        j=win.size()-1;
        vector<int>right(win.size());
        for(int i=win.size()-1;i>-1;i--)
        {
            if(win[i]>=win[j])j=i;//>= because we need lexicographically smallest
            right[i]=j;
        }
        vector<int> max(3,-1);
        
        for(int b=k;b<win.size()-k;b++)
        {
            int a = left[b-k];
            int c= right[b+k];//notice that < sign there
            if(max[0]==-1 || win[a]+win[b]+win[c]>win[max[0]] + win[max[1]] + win[max[2]])
                            max[0]=a,max[1]=b,max[2]=c;
        }
        return max;
    }
};

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        
        vector<int> win(nums.size()-k+1);
        int sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            if(i>=k)
                sum -= nums[i-k];//first window element reomoved
            if(i>=k-1)
                win[i-(k-1)] = sum;//window sum stored at start pos
        }
        
        int j=0;
        vector<int> left(win.size());
        for(int i=0;i<win.size();i++)
        {
            if(win[i]>win[j])j=i;
            left[i] = j;
        }
        
        j = win.size()-1;
        vector<int> right(win.size());
        for(int i=win.size()-1;i>-1;i--)
        {
            if(win[i] >= win[j])j=i;
            right[i]=j;
        }
        
        vector<int> max(3,-1);
        for(int b=k;b<win.size()-k;b++)
        {
            int a = left[b-k];
            int c = right[b+k];
            
            if(max[0]==-1 || win[a] + win[b] + win[c] > win[max[0]] + win[max[1]] + win[max[2]])
            {
                max[0]=a;
                max[1]=b;
                max[2]=c;
            }
        }
        
        return max;
    }
};

public class Window {
    public int Start { get; set; }
    public int End { get; set; }
    
    private int? CurrentSum;
    
    public void IncrementIndicesFor(int[] nums) { 
        CurrentSum -= nums[Start];
        
        Start++;
        End++;
        
        if(End < nums.Length) CurrentSum += nums[End];
    }
    
    public int Sum(int[] nums) {
        if(CurrentSum == null) {
            CurrentSum = 0;
            for(int i = Start; i <= End; i++) {
                CurrentSum += nums[i];
            }
        }
        return CurrentSum.Value;
    }
    
    public Window(int start, int end) {
        Start = start;
        End = end;
        CurrentSum = null;
    }
}

public class Solution {
    public int[] MaxSumOfThreeSubarrays(int[] nums, int k) {
        var sum = 0;
        var indices = new int[3];
        
        var w1 = new Window(0, 0 + k - 1);
        while(w1.End + 2 * k < nums.Length) {
            
            var w2 = new Window(w1.End + 1, w1.End + k);
            while(w2.End + k < nums.Length) {
                
                var w3 = new Window(w2.End + 1, w2.End + k);
                while(w3.End < nums.Length) {
                    var windowsum = w1.Sum(nums) + w2.Sum(nums) + w3.Sum(nums);
                    
                    if(windowsum > sum) {
                        indices = new int[] {
                            w1.Start,
                            w2.Start,
                            w3.Start
                        };
                        
                        sum = windowsum;
                    }
                    
                    w3.IncrementIndicesFor(nums);
                }
                w2.IncrementIndicesFor(nums);
            }
            w1.IncrementIndicesFor(nums);
        }
        
        return indices;
    }
}

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        //basically we're maintaining 3 windows here
        int w1s=0,w1e=0+k-1,w1cs=0;
        int w2s=w1e+1,w2e=w1s+k,w2cs=0;
        int w3s=w2e+1,w3e=w2s+k,w3cs=0;
        int dsum =0;
        vector<int> ind(3,0);
        while(w1e + 2*k <nums.size())
        {   
            w2s=w1e+1,w2e=w1e+k;
            while(w2e + k < nums.size())
            {
                
                w3s=w2e+1,w3e=w2e+k;
                while(w3e < nums.size())
                {
                    int ws = sum(w1s,w1e,nums,w1cs) + sum(w2s,w2e,nums,w2cs) + sum(w3s,w3e,nums,w3cs);
                    if(dsum<ws)
                    {
                        ind[0] = w1s,
                        ind[1] = w2s,
                        ind[2] = w3s;
                        dsum = ws;
                    }
                    incInd(w3s,w3e,nums,w3cs);
                }
                
                incInd(w2s,w2e,nums,w2cs);
            }          
            incInd(w1s,w1e,nums,w1cs);
        }
        
        return ind;
    }
    
     void incInd(int& s, int& e,vector<int>& nums,int& cs)
     {
         cs -= nums[s];
         s++,e++;
         if(e<nums.size()) cs += nums[e];
     }
    
    int sum(int s,int e,vector<int> nums,int& cs)
    {   
        if(cs==0)
        for(int i=s;i<=e;i++)
            cs += nums[i];
        
        return cs;
    }
    
    
};