class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(!matrix.size())return false;
        cout<<matrix[0].size()<<" "<<matrix.size();
        int s=matrix[0][0], l=matrix[matrix.size()-1][matrix[0].size()-1];
        if(target<s || target>l){cout<<"ss"<<s<<" "<<l;return false;}
        bool flag=false;
        int i=0,j=matrix[0].size()-1;
        
        while(i<=matrix.size()-1 && j>=0)
        {
            if(matrix[i][j]==target)flag=true;
            if(matrix[i][j]>target)j--;
            else i++;
        }
        
        return flag;
    }
};