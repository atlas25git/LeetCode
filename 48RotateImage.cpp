class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reflect(matrix);
    }
    
    void transpose(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        for(int i=0;i<n;i++)
            for(int j=i;j<n;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
    }
    
    void reflect(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        for(int r=0;r<n;r++)
        {
            int i=0;
            int j=n-1;
            while(i<j)
            {
                swap(matrix[r][i++],matrix[r][j--]);
            }
        }
    }
};