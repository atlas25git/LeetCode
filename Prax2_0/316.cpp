class Solution {
public:
    string removeDuplicateLetters(string s) {
        //We're here approaching the problem through greedy paradigm
        //let's say for any char having occr more than once, we have the choice to
        //delete either of the occr's, but we need to satisfy the smallest lexicographical order
        //for this we can use the concept of next smaller element, for any char whose occr is 
        //more than once we can delete it for the lexicographically smaller char encountered.
        vector<int> cnt(26,0);
        vector<bool> vis(26,0);
        for(auto x: s)cnt[x-'a']++;
        string res = "#";
        
        for(auto x: s)
        {
            ///doing it here to let even the vis char's freq be reduced
            cnt[x-'a']--;
            //already finalized
            if(vis[x-'a'])continue;
            
            //Making a Greedy choice for lexicographically char be leftmost
            while(res.back() != '#' && cnt[res.back()-'a'] && res.back() > x)
                vis[res.back()-'a'] = 0,
                res.pop_back();
            
            res += x;
            vis[x-'a'] = 1;
        }
        return res.substr(1);
    }    
};