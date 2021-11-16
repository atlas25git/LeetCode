class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cnt(256,0);
        vector<int> present(256,0);
        
        for(auto x: s)cnt[x]++;
        
        string res = "#";
        
        for(auto x : s)
        {
            //traversed hence one occurrence used
            cnt[x]--;
            if(present[x])continue;
            
            //if the present element is as such that it can occur later
            //implying it's present occurrence could be deleted.
            //and this will be the case if the occurring char is smaller lexicographically
            while(cnt[res.back()] && res.back()>x)
            {
                present[res.back()] = false;
                res.pop_back();
            }
            res += x;
            present[x] = true;
        }
        return res.substr(1);
    }
};