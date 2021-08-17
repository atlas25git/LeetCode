class Solution {
class Solution {
public:
    /**
     * @param s: a string
     * @param dict: a list of strings
     * @return: return a string
     */
    string addBoldTag(string &s, vector<string> &dict) {
        vector<bool> bold(s.size(),0);
        
        int end=0;
        for(int i=0;s[i];i++)
        {
            for(auto x: dict)
            {
                if(s.compare(i,x.size(),x)==0){
                    end = max(end,(int)(i+x.size()));
                }
            }
            bold[i] = end>i;
        }

        string result ="";
        for(int i=0;i<s.size();)
        {
            if(!bold[i])
            {
                result+=s[i];i++;
                continue;
            }
            int j=i;
            while(j<s.size() && bold[j])j++;
            //j-i inclusinve of i as j is made to go a step extra
            result =result +  ("<b>" + s.substr(i,j-i) + "</b>");
            //cout<<i<<" j "<<j<<endl;
            i=j;//-1 because in the next iteration i is incremented
        }
        return result;
    }
};


public:
    /**
     * @param s: a string
     * @param dict: a list of strings
     * @return: return a string
     */
    string addBoldTag(string &s, vector<string> &dict) {
        vector<bool> bold(s.size(),0);
        
        int end=0;
        for(int i=0;s[i];i++)
        {
            for(auto x: dict)
            {
                if(s.compare(i,x.size(),x)==0){
                    end = max(end,(int)(i+x.size()));
                }
            }
            bold[i] = end>i;
        }

        string result ="";
        for(int i=0;i<s.size();i++)
        {
            if(!bold[i])
            {
                result+=s[i];
                continue;
            }
            int j=i;
            while(j<s.size() && bold[j])j++;
            //j-i inclusinve of i as j is made to go a step extra
            result =result +  ("<b>" + s.substr(i,j-i) + "</b>");
            cout<<i<<" j "<<j<<endl;
            i=j-1;//-1 because in the next iteration i is incremented
        }
        return result;
    }
};

class Solution {
public:
    /**
     * @param s: a string
     * @param dict: a list of strings
     * @return: return a string
     */
    string addBoldTag(string &s, vector<string> &dict) {
        bool bold[s.size()] = {};
        int end=0;
        for (int i = 0; i < s.size(); i++) {
            for (auto & word : dict) {
                if (s.compare(i, word.size(), word) == 0) {
                    end = max(end, i + (int)word.size());
                }
            }
            bold[i] = (end > i);//marks all the strings to be included under bold
        }
        string result = "";
        for (int i = 0; i < s.length(); i++) {
            if (!bold[i]) {
                result = result + s[i];
                continue;
            }
            int j = i;
            //making j point to the last element of the bold substring
            while (j < s.size() && bold[j]) j++;
            result = result + ("<b>" + s.substr(i, j - i) + "</b>");
            i = j - 1;
        }
        
        return result;
    }
};