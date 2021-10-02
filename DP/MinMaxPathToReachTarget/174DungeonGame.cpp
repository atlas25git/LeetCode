class Solution {
public:
    vector<vector<int>> dp;
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        dp.resize(dungeon.size(),vector<int>(dungeon[0].size(),INT_MAX));
        
        return solveBUP(dungeon);
    }
    
    int solve(vector<vector<int>>& d,int i,int j)
    {
        if(i >= d.size() || j >= d[0].size())return INT_MAX;
        
        if(i==d.size()-1 && j==d[0].size()-1)
                return d[i][j]>0?1:-1*(d[i][j])+1;
        if(dp[i][j]!=INT_MAX)
                return dp[i][j];
        
        int r = solve(d,i+1,j);
        int dw = solve(d,i,j+1);
        
        //merge step
        //for positive power value our king will get those as incentives on
        //arriving here hence we can reduce this cost from total
        int mhrc = min(r,dw) - d[i][j];
        
        dp[i][j] = mhrc>0?mhrc:1;
        return dp[i][j];
    }
    
    int solveBUP(vector<vector<int>>& dg)
    {
        int r = dg.size(),c=dg[0].size();
        vector<vector<int>> dp(r+1,vector<int>(c+1,INT_MAX));
        
        //r-1,c-1 is the destination it's destiation in defined terms
        //hence should have the minimum possible energy to be calculated
        dp[r][c-1] = 1;
        dp[r-1][c] = 1;
        
        
        for(int i=r-1;i>-1;i--)
            for(int j=c-1;j>-1;j--)
            {
                int nd = min(dp[i+1][j],dp[i][j+1]) - dg[i][j];
                dp[i][j] = nd>0?nd:1;
            }
        
         for(auto x: dp)
        {
            for(auto y: x)
                cout<<y<<" ";
            cout<<endl;
        }
        
        return dp[0][0];
    }
    
    int solveBUP1(vector<vector<int>>& dg)
    {
        int r = dg.size(),c=dg[0].size();
        
        vector<vector<int>> dp(r+1,vector<int>(c+1));
        
        dp[0][0] = dg[0][0]>0?1:-dg[0][0]+1;
        
        for(int i=1;i<c;i++)dp[0][i] = dp[0][i-1] + (dg[0][i]>0)?0:-dg[0][i];
        for(int i=1;i<r;i++)dp[i][0] = dp[i-1][0] + (dg[i][0]>0)?0:-dg[i][0];
        
        for(int i=2;i<r;i++)
            for(int j=2;j<c;j++)
            {
                dp[i][j] = min(dp[i-1][j],dp[i][j-1]) - (i<r && j<c)?dg[i][j]:0;
            }
        
        for(auto x: dp)
        {
            for(auto y: x)
                cout<<y<<" ";
            cout<<endl;
        }
        
        return dp[r][c];
    }
};


int calculateMinimumHP(vector<vector<int> > &dungeon) {

        int n = dungeon.size();
        int m = dungeon[0].size();

        vector<vector<int> > dp(n + 1, vector<int>(m + 1, 1e9+5));
        dp[n][m - 1] = 1;
        dp[n - 1][m] = 1;
        
        for (int i = n - 1; i >= 0; i--) 
        {
            for (int j = m - 1; j >= 0; j--) 
            {
                int need = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];                
                // store this value
                dp[i][j] = need <= 0 ? 1 : need;
            }
        }
        return dp[0][0];
    }

    int getVal(vector<vector<int>> &mat, vector<vector<int>> &dp , int i=0, int j=0)
    {
        int n = mat.size();
        int m = mat[0].size();    
        
        if(i == n || j == m)    return 1e9+5; 
        
        if(i == n-1 and j == m-1)
            return (mat[i][j] <= 0) ? -mat[i][j] + 1 : 1;
        
        /// if we know the answer for this cell then no need to recalculate those, simply return those values 
        if( dp[i][j] != 1e9+5 )
            return dp[i][j];
        
        int IfWeGoRight = getVal(mat , dp , i , j+1);
        int IfWeGoDown = getVal(mat , dp , i+1 , j);
        
        int minHealthRequired =  min(IfWeGoRight , IfWeGoDown) -mat[i][j];
        
        /// before returning the values, we must store the answers for this cell which we hacve calculated
        /// in next recurssive call this value will be used to save some computation, aka repetative work which we are doing.
        dp[i][j] = ( minHealthRequired <= 0 ) ? 1 : minHealthRequired;      
        return dp[i][j];
    }


int getVal(vector<vector<int>> &mat, int i=0, int j=0)
    {
        int n = mat.size();
        int m = mat[0].size();
        // Base case : we have crossed the matrix, ie. out of bound
        /// if current row crosses then my row is below the princess or 
        /// if current column crosses then my column is ahead the column of princess
        /// and beacause we can go only down and right so we wont be able reach princess
        if(i == n || j == m)    return 1e9+5; 
        
		// Base Case : we have reached our destination ie. last cell
        /// we reached princess , cheers return this cost;
        if(i == n-1 and j == m-1)   
            return (mat[i][j] <= 0) ? -mat[i][j] + 1 : 1;
        
        /// now we must try all possible paths , we ask our right and and down cell
        int IfWeGoRight = getVal(mat , i , j+1);
        int IfWeGoDown = getVal(mat , i+1 , j);
        
        /// min of either values and then cost of this cell
        int minHealthRequired =  min(IfWeGoRight , IfWeGoDown) -mat[i][j];
        
        /// point 2 as explained 
        return ( minHealthRequired <= 0 ) ? 1 : minHealthRequired;      
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        return getVal(dungeon);     
    }

    int calculateMinimumHP(vector<vector<int> > &dungeon) {

        int n = dungeon.size();
        int m = dungeon[0].size();

        vector<vector<int> > dp(n + 1, vector<int>(m + 1, 1e9+5));
        dp[n][m - 1] = 1;
        dp[n - 1][m] = 1;
        
        for (int i = n - 1; i >= 0; i--) 
        {
            for (int j = m - 1; j >= 0; j--) 
            {
                int need = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];                
                // store this value
                dp[i][j] = need <= 0 ? 1 : need;
            }
        }
        return dp[0][0];
    }