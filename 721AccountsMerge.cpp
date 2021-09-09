class Solution {
public:
    string find(string s,map<string,string> &p)
    {
        return p[s]==s?s:find(p[s],p);
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        map<string,string> parent;
        map<string,string> owner;
        map<string,set<string>> coll;
        //Approach: 
        //We first intialize for every email, itself as it's parent
        //and also the owner to each of these emails as the name of person.
        //Now making a common parent of all the emails of a particular customer,
            //since the names could be repeated hence made 1st email as the parent.
        //Now made a union of all the emails with common parents in union consisting
        //of first email as the common identifying element.
        //Now used the intial mapping of all the first email vs Owner made the resulting database.
        for(auto a: accounts)
        {
            for(int j=1;j<a.size();j++)
                parent[a[j]] = a[j],
                owner[a[j]] = a[0];
            
        }
        
        for(auto a: accounts)
        {
            string p = find(a[1],parent);
            for(int j=2;j<a.size();j++)
                //since all the emails have a common parent intially
                //if two sets are joined they'll culminate for the members of the
                //complete set as well
                parent[find(a[j],parent)] = p;
        }
        
        for(auto a: accounts)
        {
            for(int i=1;i<a.size();i++)
                coll[find(a[i],parent)].insert(a[i]);
        }
        
        vector<vector<string>> res;
        
        for(auto p: coll)
        {
            vector<string> emails(p.second.begin(),p.second.end());
            emails.insert(emails.begin(),owner[p.first]);
            res.push_back(emails);
        }
        return res;
    }
};