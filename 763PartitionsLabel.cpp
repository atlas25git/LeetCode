class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<int>last(26,0);
        for(int i=0;s[i];i++)last[s[i]-'a']=i;
        
        int start=0,end=0;
        vector<int> ans;
        
        for(int i=0;s[i];i++)
        {
            end = max(end,last[s[i]-'a']);
            if(i==end)
                ans.push_back(end-start+1),
                start = i+1;
                
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26,0);
        for(int i=0;i<s.size();i++)
                last[s[i]-'a'] = i;
        
        int j=0,anc=0;
        vector<int> ans;
        for(int i=0;s[i];i++)
        {
            j = max(j,last[s[i]-'a']);
            if(i==j)
                ans.push_back(i - anc +1),
                anc = i+1;
        }
        return ans;
    }
};