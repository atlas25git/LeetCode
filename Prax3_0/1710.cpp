class Solution {
public:
    int maximumUnits1(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](vector<int> a,vector<int> b){
            if(a[1] == b[1])return a[0]>b[0];
            else return a[1]>b[1];
        });
        int ans = 0,i=0;
        while(truckSize>0 && i<boxTypes.size())
        {   
            if(truckSize<boxTypes[i][0])
                ans += truckSize*boxTypes[i][1],
                truckSize = 0;
            else   
                truckSize -= boxTypes[i][0],
                ans += boxTypes[i][0]*boxTypes[i][1];
            
            i++;
        }
        return ans;
    }
    // TC: O(n+k) counting sort
    //SC = O(n)
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize){
       vector<int> count(1001,0);
        for(auto x: boxTypes)
            count[x[1]] += x[0];
        
        int boxes = 0;
        for(int i = 1000;i>-1;i--)
        {
            if(count[i]>0)
            {
                int fitIn = min(truckSize,count[i]);
                truckSize-=fitIn;
                boxes += fitIn*i;
                if(truckSize == 0)
                    return boxes;
            }
        }
        return boxes;
    }

};