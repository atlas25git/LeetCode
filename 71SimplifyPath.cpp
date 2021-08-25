class Solution {
public:
    vector<string> tokenize(string s, const char* del)
    {   
        vector<string> res;
        auto x = s.c_str();
        char y[s.size()+1];
        strcpy(y,x);
        auto tok = strtok(y,del);
        while(tok)
        {
            res.push_back(string(tok));
            tok = strtok(0,del);
        }
        return res;
    }
    string simplifyPath(string path) {
        vector<string> res = tokenize(path,"/");
        stack<string> st;
        
        for(auto x: res)
        {
            if(x=="" || x==".")continue;
            else if(x=="..")
                {if(st.size()!=0)st.pop();}
            else st.push(x);
        }
        
        stack<string> rev;
        while(st.size()>0)
        {
            rev.push(st.top());
            st.pop();
        }
        
        string ans;
        
        while(rev.size()>0)
        {
            ans+="/";
            ans+=rev.top();
            rev.pop();
        }
        
        return ans.size()==0?"/":ans;
    }
};