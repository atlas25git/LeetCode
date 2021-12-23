class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //for every number used in a sudoku it  should be uniquely
        //addressable by 3 coordinates i,j,k hence using 9x9 3 different 
        //markers as a teller
        int usedI[9][9] = {0};
        int usedJ[9][9] = {0};
        int usedK[9][9] = {0};        
        
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
            {   
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0' -1;
                    int k = (i/3)*3 + (j/3);
                    if(usedI[num][i] || usedJ[num][j] || usedK[num][k])
                    return false;
                    usedI[num][i] = usedJ[num][j] = usedK[num][k] = 1;
                }
            }
        
        return true;
    }
};