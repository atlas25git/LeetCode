class Solution {
public:
    /**
     * @param str: a string
     * @return: return a string
     */
    void reverse(string& s,int i,int j)
    {
        while(i<=j)
        {
            char x = s[i];
            s[i]=s[j];
            s[j] = x;
            i++,j--;
        }
        return;
    }

    string reverseWords(string &str) {
        
        if(str.length()==0)return str;
        reverse(str,0,str.size()-1);

        int i=0,j=0;

        while(j<str.length())
        {
            if(str[j] == ' ')
            {
                reverse(str,i,j-1);
                j++;
                i=j;
            }
            else j++;
        }
        //reversing the last one remaining
        reverse(str,i,j-1);
        return str;
    }
};
