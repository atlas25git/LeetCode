class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        if(!s.size())return ans;
        vector<int> lp(26,-1);
        for(int i=s.size()-1;i>-1;i--)
                if(lp[s[i] - 'a'] == -1)
                    lp[s[i]-'a'] = i;
        int minP = -1,pLen = 0;
        
        for(int i=0;s[i];i++)
        {
            int lpcc = lp[s[i]-'a'];
            minP = max(minP,lpcc);
            pLen++;
            
            if(i==minP)
                ans.push_back(pLen),
                pLen = 0,minP = -1;
        }
        return ans;
    }
};