class Solution {
public:
    vector<string> generateParenthesis(int n) {
        //simple bt based choose vs not choose
        vector<string> ans;
        fill(0,n,0,0,"",ans);
        return ans;
    }
    
    void fill(int i,int n, int op, int cl,string curr,vector<string>& ans)
    {
        //here basically we make 2 calls onew by including ( and then )
        //we maintain the no of count in such calls of both types of brackets
        //if in some case open/close bracket count defies the possible soln we backtrack.
        
        //half case only just that we check agains 2*n
        if(op>i || cl>i)return;
        
        //acceptance case
        if(i==n*2)
        {
            if(op==cl)ans.push_back(curr);
            return;
        }
        
        //first call including "(" ob
        
        fill(i+1,n,op+1,cl,curr + "(",ans);
        
        //makes sure that we've open bracket already
        if(op>cl)
            fill(i+1,n,op,cl+1,curr+")",ans);
        
    }
};


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        fill(0,n,0,0,"",ans);
        return ans;
    }
    
    void fill(int ind,int n,int op,int cl,string curr,vector<string>& ans)
    {
        if(op>ind || cl>ind)return;
        
        if(ind == n*2)
        {
            if(op == cl)ans.push_back(curr);
            return;
        }
        
        fill(ind+1,n,op+1,cl,curr + "(",ans);
        if(cl<op)
            fill(ind+1,n,op,cl+1,curr+")",ans);
    }
    
};