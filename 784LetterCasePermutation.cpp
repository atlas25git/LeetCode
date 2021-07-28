class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        //Our approach here is again a complete search based
        //we start from a global iterator, and thus for every index
        //i we make fn calls for all the possible scenarios, and when
        ///index reaches string len we add the persisting value to our results.
        
        vector<string> res;
        if(s.size())
            fill(0,res,s,"");
        return res;
    }
    
    void fill(int ind,vector<string>& res,string s,string cr)
    {
        //base case
        if(ind == s.length())
        {
            res.push_back(cr);
            return;
        }
        char c = s[ind];
        if(isdigit(c))
            //tho c is a digit but inherently it is stored in char form in string
            fill(ind+1,res,s,cr+ c);
        else{
            fill(ind+1,res,s,cr +(char)tolower(c));
            fill(ind+1,res,s,cr +(char)toupper(c));

        }
        
    }
    
};


class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        if(s.size())
            fill(0,"",s,res);
        return res;
    }
    
    void fill(int ind,string cr,string s,vector<string>& res)
    {
        if(ind == s.length())
        {
            res.push_back(cr);
            return;
        }
        char c = s[ind];
        if(isdigit(c))
//tho c is a digit but inherently it is stored in char form in string
            fill(ind+1,cr+=c,s,res);
        else
        {   char cl = tolower(c);
            char cu = toupper(c);
            //string c1 = cr + cl;
            //string c2 = cr + cu;
            fill(ind+1,cr+cl,s,res);
            fill(ind+1,cr+cu,s,res);
        }
    }
    
};



public class Solution {
    public IList<string> LetterCasePermutation(string S) {
        var list = new List<string>();
        if(string.IsNullOrEmpty(S)) return list;
        
        Permute(0, "", S, list);
        return list;
    }
    
    void Permute(int n, string sofar, string s, IList<string> list) {
        if(n == s.Length) {
            list.Add(sofar);
            return;
        }
        
        var c = s[n];
        if(char.IsDigit(c))
            Permute(n + 1, $"{sofar}{c}", s, list);
        else {
            Permute(n + 1, $"{sofar}{char.ToLower(c)}", s, list);
            Permute(n + 1, $"{sofar}{char.ToUpper(c)}", s, list);
        }    
    }
}

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        if(s.size())
            fill(0,"",s,res);
        return res;
    }
    
    void fill(int ind,string cr,string s,vector<string>& res)
    {
        if(ind == s.length())
        {
            res.push_back(cr);
            return;
        }
        char c = s[ind];
        if(isdigit(c))
            fill(ind+1,cr+=c,s,res);
        else
        {   char cl = tolower(c);
            char cu = toupper(c);
            fill(ind+1,cr+=cl,s,res);
            fill(ind+1,cr+=cu,s,res);
        }
    }
    
};