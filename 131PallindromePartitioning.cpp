class Solution {
public:
    vector<vector<string>> partition(string s) {
        //simple backtracking based approach
        //maintain a universal pointer, through it
        //check for all the resulting subsets and add them to
        //the results if particular subset is a pallindrome.
        vector<vector<string>> res;
        vector<string> curr;
        fill(0,s.size(),curr,res,s);
        return res;
    }
    
    void fill(int i,int n,vector<string> curr,vector<vector<string>>& res, string s)
    {
        if(i==n)//basecase reached
        {
            res.push_back(curr);
            return;
        }
        
        //iterating over all subsets resulting from a given universal ptr
        for(int j = i;j<s.length();j++)
        {   //function takes two values pos and len 
            string cr = s.substr(i,j-i+1);
            if(isBool(i,j,s))
            {
                curr.push_back(cr);
                fill(j+1,n,curr,res,s);
                curr.pop_back();
            }
        }
    }
    
    bool isBool(int i,int j,string s){
        while(i<j)
            if(s[i++]!=s[j--])return false;
        return true;
    }
    
};

class Solution {
public:
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;
        vector<string> curr;
        fill(0,s,curr,ans);
        return ans;
    }
    
    void fill(int i, string s, vector<string> curr, vector<vector<string>>& ans)
    {
        if(i == s.length())
        {
            ans.push_back(curr);
            return;
        }
        
        for(int j=i;j<s.length();j++)
        {
            if(!isPall(i,j,s))
                continue;
            curr.push_back(s.substr(i,j-i+1));
            fill(j+1,s,curr,ans);
            curr.pop_back();
        }
    }
    
    bool isPall(int i,int j, string s)
    {
        while(i<j)
            if(s[i++] != s[j--])return false;
        return true;
    }
};