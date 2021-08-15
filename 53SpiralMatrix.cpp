class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r1=matrix.size();
        int c =matrix[0].size();

        vector<int> ans;
        int l=0,u=0,r=c-1,d=r1-1;
        
        while(l<=r && u<=d)
        {
            //1> L to R
            for(int i=l;i<=r;i++)
                ans.push_back(matrix[u][i]);
            u++;//excluding the current row
            
            //2:u TO d
            for(int i=u;i<=d;i++)
                ans.push_back(matrix[i][r]);
            r--;//excluding curr col
            
            //r to l
            if(u<=d)
            {
                for(int i=r;i>=l;i--)
                    ans.push_back(matrix[d][i]);
                d--;
            }
            
            if(l<=r)
            {
                for(int i=d;i>=u;i--)
                    ans.push_back(matrix[i][l]);
                l++;
            }
        }
        return ans;
    }    
    
};