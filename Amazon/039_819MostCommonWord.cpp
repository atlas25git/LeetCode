class Solution {
public:
    string mostCommonWord(string para, vector<string>& banned) {
        unordered_map<string,int> mp;
        unordered_set<string> ban(banned.begin(),banned.end());
        
        //converting the paragraph into space seperated lowercased string of words
        for(auto& c: para) c = isalpha(c)?tolower(c):' ';

        stringstream ss(para);
        string s;
        
        pair<string,int> res;
        while(ss>>s)
        {   
            if(ban.count(s))
                continue;
            if(mp.count(s))
                mp[s]++;
            else
                mp[s] = 1;
            if(res.second < mp[s])
                    res = {s,mp[s]};
        }
        
        return res.first;
    }
};