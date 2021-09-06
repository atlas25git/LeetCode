class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acts) {
        
        map<string,string> parents;
        map<string,string> owner;
        map<string,set<string>> unions;
        
        //Approach: 
        //We first intialize for every email, itself as it's parent
        //and also the owner to each of these emails as the name of person.
        //Now making a common parent of all the emails of a particular customer,
            //since the names could be repeated hence made 1st email as the parent.
        //Now made a union of all the emails with common parents in union consisting
        //of first email as the common identifying element.
        //Now used the intial mapping of all the first email vs Owner made the resulting database.

        for(int i=0;i<acts.size();i++)
            //marking parens of all the mails, intially themselves
            //also the owners of these emails
            for(int j=1;j<acts[i].size();j++){
                parents[acts[i][j]] = acts[i][j];
                owner[acts[i][j]] = acts[i][0];
            }
        
        for(int i=0;i<acts.size();i++)
        {   //fixing parents of all the emails of a person to it's first mail
            string p = find(acts[i][1],parents);
            for(int j=2;j<acts[i].size();j++)
                parents[find(acts[i][j], parents)] = p;
        }
        
        for(int i=0;i<acts.size();i++)
            //making unions of all the emails with common parent
            for(int j=1;j<acts[i].size();j++)
                unions[find(acts[i][j],parents)].insert(acts[i][j]);
        
        vector<vector<string>> res;
        for(auto p : unions)
        {   
            //generating ans
            vector<string> emails(p.second.begin(),p.second.end());
            emails.insert(emails.begin(),owner[p.first]);
            res.push_back(emails);
        }
        return res;
    }
    
    string find(string s, map<string,string>& p){
        return p[s] == s?s:find(p[s],p);
    }
};