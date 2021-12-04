class Solution {

    int ind;
    public:
    string decodeString(string s) {
        ind = 0;
        return decode(s);
    }
    
    string decode(string& s)
    {
        string res;
        int num = 0;
        for(;ind<s.size();ind++)
        {
            char cr = s[ind];
            if(cr == '[')
                {ind++;
                string subRes = decode(s);
                while(num>0)res+=subRes,num--;}
            else if(isdigit(cr))
                num = num*10 + cr - '0';
            else if(isalpha(cr))
                res += cr;
            else if(cr == ']')
                return res;
        }
        
        return res;
    }
};