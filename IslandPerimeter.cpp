class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size();
        int c=grid[0].size();
        int l=0,e=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1)
                {l++;
                 //L to R
                 //top to down
                if(i>0 && grid[i-1][j]==1)e++;
                if(j>0 && grid[i][j-1]==1)e++;}
                //due to the orer of our traversal we want it to be counted 
                //just once
                //if(j<c && grid[i][j+1]==1)e++;
            }
        }
        
        //we'r substracting twice the no. of edges 
        //as the ones which are overlapped compensate for 2 natural edges.
        
        return (4*l)-(2*e);
    }
};