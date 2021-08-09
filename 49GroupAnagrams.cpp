class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> map;
        vector<vector<string>> anagrams;
        
        for(auto x: strs)
        {
            vector<int>count(26);
            
            for(auto c: x)
                count[c-'a'] +=1;
            
            string sb;
            for(auto y:count)
            {
                sb+='#';
                sb+=to_string(y);
            }
            
            string key = sb;
            
            if(map.find(key)!=map.end())
                map[key].push_back(x);
            else{
                map.insert({key,vector<string>{x}});
            }
        }
        
        for(auto x: map)anagrams.push_back(x.second);
        return anagrams;
        
    }
};