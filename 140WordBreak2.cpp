class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& w) {
        
        unordered_set<string>w1(w.begin(),w.end());
        unordered_map<int,vector<string>> mp;
        return util(0,s,w1,mp);
    }
    
    vector<string> util(int ind,string s,unordered_set<string> w1,unordered_map<int,vector<string>> mp)
    {
        if(mp.count(ind))return mp[ind];
        vector<string> res;
        //looking for all the prefixes
        for(int i=1;i+ind<=s.length();i++)
        {   
            //gives sub strings for the ones starting at index and
            //span till the end
            string word = s.substr(ind,i);
            //checking wether or not it is a valid word
            if(w1.find(word) == w1.end())
                continue; //not a valid word
            //substr is a valid word
            
            //think of it in terms that you're iterating for the ind, and i is just for
            //the rem len in string's valid ambits
            if(i+ind==s.length())//no chars rem of string on the right
                res.push_back(word);
            //not that case, there're some chars on the right
            else
            {
                //so here we've a valid word on the left side, and the subsequent right call up
                //would now fetch us the words break in the former part, as in for any word found 
                //interim, it'll call for the valid part in it's right, and now these words would be added with the 
                //intial left word and would be a part of the res
                //and these addn will be spaced and formated hence just one addn
                vector<string> words = util(i+ind,s,w1,mp);
                for(int j=0;j<words.size();j++)
                    res.push_back(word + " " + words[j]);
            }
        }
        mp[ind]=res;
        return res;
        
    }
};


class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& w) {
        unordered_set<string> w1(w.begin(),w.end());
        unordered_map<int,vector<string>> mp;
        
        return util(0,s,w1,mp);
    }
    
    vector<string> util(int ind, string s,unordered_set<string> w1,unordered_map<int,vector<string>> mp)
    {
        if(mp.count(ind))return mp[ind];
        vector<string> res;
        for(int i=1;i+ind<=s.length();i++)
        {
            string word = s.substr(ind,i);
            
            if(w1.find(word)!=w1.end())
            {
                if(i+ind == s.length())
                    res.push_back(word);
                else
                {
                    vector<string> words = util(i+ind,s,w1,mp);
                    for(int j=0;j<words.size();j++)
                        res.push_back(word + " " + words[j]);
                }
            }
        }
        
        mp[ind]=res;
        return res;
    }
    
};

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wD) {
        unordered_set<string> wD1(wD.begin(),wD.end());
        unordered_map<int,vector<string>> memo;
        
        return break1(0,s,wD1,memo);
    }
    
    vector<string> break1(int ind,string s, unordered_set<string> wD1,unordered_map<int,vector<string>> memo)
    {   
        if(memo.count(ind)==1)return memo[ind];
        vector<string> res;
        
        for(int i=1;i+ind<=s.length();i++)
        {   
            //for any ind given searches for all the valid prefixes.
            string word = s.substr(ind,i);
            if(wD1.find(word)==wD1.end())
                    continue;
            //if found
            //if this is the end no right part remaining, just add this.
            if(i+ind == s.length())
                res.push_back(word);
            //called on the remaining part of string.
            else{
                vector<string> words = break1(i+ind,s,wD1,memo);
                for(int j=0;j<words.size();j++)
                        res.push_back(word+" "+ words[j]);
            }
        }
    
        memo[ind]=res;
        return res;
    }
    
};