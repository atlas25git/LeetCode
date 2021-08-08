class Solution {
public:
    
    unordered_map<char,int> getMap(string order)
    {
        unordered_map<char,int> mp;
        for(int i=0;i<order.length();i++)
                mp.insert({order[i],i});
        
        return mp;
    }
    
    bool ctxorder(string a, string b, unordered_map<char,int> om)
    {
        int i = 0;
        int j = 0;
        
        while(i<a.length() && j<b.length())
        {
            if(om[a[i]] < om[b[i]])return true;
            else if(om[a[i]] > om[b[j]])return false;
            i++,j++;
        }
        return a.length()<=b.length();
    }
    
    
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> om = getMap(order);
        //for(auto x:om)cout<<x.first<<" "<<x.second<<endl;
        
        for(int i=1;i<words.size();i++)
        {
            if(!ctxorder(words[i-1],words[i],om))return false;
        }
        return true;
    }
    
    
};