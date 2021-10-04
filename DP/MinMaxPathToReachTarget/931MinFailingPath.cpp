class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& m) {
        for(int i=1;i<m.size();i++)
            for(int j=0;j<m[0].size();j++)
                m[i][j] += min({m[i-1][j],m[i-1][max(0,j-1)],m[i-1][min((int)m.size()-1,j+1)]});
        
        return *min_element(m.back().begin(),m.back().end());
    }
};