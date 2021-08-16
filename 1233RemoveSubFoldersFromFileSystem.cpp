class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        
        unordered_set<string>s(folder.begin(),folder.end());
        vector<string> list;
        
        for(auto path : folder)
        {
            if(pathExisting(path,s))continue;
            list.push_back(path);
        }
        
        return list;
        
    }
    
    bool pathExisting(string path, unordered_set<string>&s)
    {
        int i=1;
        while(i<path.size())
        {
            if(path[i]=='/'){
                string par = path.substr(0,i);
                if((s.find(par)!=s.end()) && par.length()<path.length())return true;
            }
            i+=1;
        }
        return false;
    }
};