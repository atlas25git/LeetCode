class NumMatrix {
public:
    vector<vector<int>> sums;
    NumMatrix(vector<vector<int>>& matrix) {
        sums = vector<vector<int>>();
        
        for(auto row : matrix)
        {   
            vector<int> temp(row.size());
            int sum=0;
            //row wise sum along the column no as end
            for(int i=0;i<row.size();i++)
                sum+=row[i],temp[i]=sum;
            
            sums.push_back(temp);
            
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
            int sum = 0;
            for(int r=row1;r<=row2;r++)
                sum+=grs(r,col1,col2);
            return sum;
    }
    
    int grs(int r,int s,int e){
        int sum = sums[r][e];
        if(s>0)sum-=sums[r][s-1];
        return sum;
    }
};