class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        //Approach:
        //here we are resorting for a full search with back tracking for the given false checks.
        //We maintain a common iterator in the string, and for each we check all the possible
        //string sets of size <=3, this however checks for validity at index out of bound
        //when segments become>4 we backtrack, and when n string len that is entire string has been
        //traversed thus we then check if seg condn is satisfied, and thus store it as viable sol.
        
        vector<string> res;
        if(s.size())
            fill(0,0,res,s,"");
        return res;
    }
    
    void fill(int ind, int seg, vector<string>& res, string s,string cip)
    {
        if(seg>4)return;
        if(ind == s.size())
        {
            if(seg == 4)
                res.push_back(cip);
        }
        
        //search begins
        //for each ind in [0,s.size) we check for all valid strings starting from this of len [1,3]
        for(int i=1; i<=3 && i+ind <= s.size();i++)
        {
            string cur = s.substr(ind,i);
            //basically coz we're considering for every poss 3 lettered seg
            string dot = ind==0?"":".";
            
            //backTrack
            if(cur.size()>1 && cur[0]=='0')return;
            if(stoi(cur)>255)return;
            
            //fn call
            fill(ind+i,seg+1,res,s,cip+dot+cur);
            
            
        }
    }
    
};



class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
            vector<string> ips;
        if(!s.size())return ips;
        getIps(0,0,"",s,ips);
        return ips;
    }
    
    void getIps(int n,int seg,string ip,string s,vector<string>& ips)
    {
        if(seg>4)return;
        if(n==s.length())
        {
            if(seg==4)ips.push_back(ip);
            return;
        } 
        for(int i=1;i<=3 && i+n <= s.length(); i++)
        {   //i spans in 1,2,3 as they are valid lens for a comp.
            string cur = s.substr(n,i);
            string dot = n==0?"":".";
            
            if(cur.length()>1 && cur[0] == '0')return;
            if(stoi(cur) > 255)return;
            
            getIps(n+i,seg+1,ip+dot+cur,s,ips);
        }
    }
    
};