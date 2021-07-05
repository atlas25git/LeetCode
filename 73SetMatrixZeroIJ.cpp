class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        vector<bool> rows(matrix.size(),false);
        vector<bool> col(matrix[0].size(),false);
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(!matrix[i][j])
                {
                    rows[i]=true;
                    col[j]=true;
                }
            }
        }
        
        for(int i=0;i<rows.size();i++)
        {
            if(rows[i])
            {
                matrix[i].assign(col.size(),0);
            }
            
        }
        for(int i=0;i<col.size();i++)
        {
            if(col[i])
            {   int r = rows.size();
                while(r--)
                {
                    matrix[r][i] =0;
                }
            }
        }
        
    }
};