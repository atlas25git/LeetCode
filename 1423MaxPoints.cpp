class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n=cardPoints.size();
        int Tsum=0;
        
        for(int i=0;i<n;i++)Tsum+=cardPoints[i];
        
        //cout<<"Tsum "<<Tsum<<endl;
        int ws = cardPoints.size()-k;
        
        int wSum=0;
        for(int i=0;i<ws;i++)wSum+=cardPoints[i];
        //cout<<"Tsum "<<wSum<<endl;
        
        int minWsum=wSum;
        
        for(int i=ws;i<n;i++)
        {
            wSum += cardPoints[i] - cardPoints[i-ws];
            minWsum = min(wSum,minWsum);
        }
        return Tsum-minWsum;
        
    }
};