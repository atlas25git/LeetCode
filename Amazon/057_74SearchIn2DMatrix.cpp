class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        int  i = 0,j=c-1;
        while(i<r && j>-1)
        {
            int ele = matrix[i][j];
            if(ele == target)return true;
            else if(ele<target)
                i++;
            else j--;
        }            
        return false;
    }
};