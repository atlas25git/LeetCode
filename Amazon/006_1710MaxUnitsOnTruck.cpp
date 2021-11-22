class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
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
};