class Solution {
public:
    
    vector<string> pat = {"", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> letterCombinations(string s) {
        if(!s.size())return {};
        vector<string> res({""});
        
        for(auto x: s){
            vector<string> tmp;
            for(auto p: pat[x-'0'])
            {
                for(auto c : res)
                    tmp.push_back(c+p);
            }
            res.swap(tmp);
        }
        return res;
    }
};