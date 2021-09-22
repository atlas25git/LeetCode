class Solution {
public:
    vector<string> ans;
    int maxLen;
    
    void solve(vector<string>& words,int j){
        
        if(j==maxLen) return;
        
        string temp = "";
        for(int i=0;i<words.size();i++)
        {
            if(j>=words[i].length()) 
                temp += " ";
            else 
                temp += words[i][j];
        }
        
        int i = temp.length()-1;
        while(temp[i--]==' '){
            temp.pop_back();
        }
        ans.push_back(temp);
        solve(words,j+1);
        
    }
    
    vector<string> printVertically(string s) {
        istringstream ss(s);
        string word; 
        vector<string> words;
        maxLen = -1;
        while (ss >> word){
            int len = word.length();
            maxLen = max(maxLen,len);
            words.push_back(word); 
        } 
               
        solve(words,0);
        return ans;
    }
};