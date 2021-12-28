class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)return s;
        vector<string> row(min(numRows,(int)s.size()));
        int cr = 0;
        int dir = 0;
        
        for(auto c: s)
        {
            if(cr == 0 || cr == row.size()-1)
                dir++;
            
            row[cr] += c;
            cr += dir&1?1:-1;
        }
        string res;
        for_each(row.begin(),row.end(),[&res](string s){res+=s;});
        return res;
    }
};