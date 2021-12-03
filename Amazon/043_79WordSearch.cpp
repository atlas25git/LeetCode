class Solution {
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                if(chk(i,j,board,word))
                    return true;
        return false;
    }
    
    bool chk(int i,int j,vector<vector<char>>& board,string word)
    {   
        if(!word.size())
            return true;
        
        if(i< 0 || j<0 || i>=board.size() || j>=board[0].size() || word.front() != board[i][j])
            return false;
        
        char x = board[i][j];
        board[i][j] = '#';
        bool res = 0;
        for(int k=0;k<4;k++)
            res = res || chk(i+dx[k],j+dy[k],board,word.substr(1));
        board[i][j] = x;
        return res;
    }
};