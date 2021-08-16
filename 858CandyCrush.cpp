class Solution {
public:
    /**
     * @param board: a 2D integer array
     * @return: the current board
     */
    vector<vector<int>> candyCrush(vector<vector<int>> &board) {
        // Write your code here
        int n = board.size(),m=board[0].size();
        bool found = true;

        while(found)
        {
            found = false;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {   
                    //since we need to crush all the candies satisfying the criteria
                    //3 in a row, thus we iterate on abs value, in each successive iteration
                    //we mark the following same sequence as been done crushing over.
                    int val = abs(board[i][j]);
                    if(val==0)continue;
                    if(j<m-2 && abs(board[i][j+1]) == val && abs(board[i][j+2])==val)
                    {
                        found = true;
                        int ind = j;
                        while(ind<m && abs(board[i][ind])==val)
                            //can't be zero as those are used to state a stable empty position too
                            //storing the negative as we'd be using the abs notation to further our positon
                            board[i][ind++]  = -val;

                    }
                    if(i<n-2 && abs(board[i+1][j])==val && abs(board[i+2][j])==val)
                    {
                        found = true;
                        int ind = i;
                        while(ind<n && abs(board[ind][j])==val)
                            board[ind++][j] = -val;
                    }
                }
            }
            if(found)
            {
                for(int j=0;j<m;j++)
                {
                    int si = n-1;
                    for(int i=n-1;i>-1;i--)
                    {
                        if(board[i][j]>0)
                            //here si and i will decrease uniformly till the first 
                            //zero is discovered, after that the relative shift will happen
                            board[si--][j] = board[i][j];
                    }
                    //the places above si are insignificant empty states
                    for(int k=si;k>-1;k--)
                        board[k][j]=0;
                }
            }
        }
        return board;      
    }
};

class Solution
{
  public:
    /**
     * @param board: a 2D integer array
     * @return: the current board
     */
    vector<vector<int>> candyCrush(vector<vector<int>> &board)
    {
        int N = board.size(), M = board[0].size();
        bool found = true;
        while (found)
        {
            found = false;
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    int val = abs(board[i][j]);
                    if (val == 0)
                    {
                        continue;
                    }
                    if (j < M - 2 && abs(board[i][j + 1]) == val && abs(board[i][j + 2]) == val)
                    {
                        found = true;
                        int ind = j;
                        while (ind < M && abs(board[i][ind]) == val)
                        {
                            board[i][ind++] = -val;
                        }
                    }
                    if (i < N - 2 && abs(board[i + 1][j]) == val && abs(board[i + 2][j]) == val)
                    {
                        found = true;
                        int ind = i;
                        while (ind < N && abs(board[ind][j]) == val)
                        {
                            board[ind++][j] = -val;
                        }
                    }
                }
            }
            if (found)
            {
                for (int j = 0; j < M; j++)
                {
                    int storeInd = N - 1;
                    for (int i = N - 1; i >= 0; i--)
                    {
                        if (board[i][j] > 0)
                        {
                            board[storeInd--][j] = board[i][j];
                        }
                    }
                    for (int k = storeInd; k >= 0; k--)
                        board[k][j] = 0;
                }
            }
        }
        return board;
    }
};
