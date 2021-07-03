class Solution {
public:
    bool isValid(string s1,int i,int j)
    {
        while(i<=j)
        {
            if(s1[i]==s1[j])
            {
                i++,j--;
            }
            else return false;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        
        int i=0,j=s.length()-1;
        
        while(i<=j)
        {
            if(s[i] != s[j]){
                if(isValid(s,i,j-1))return true;
                if(isValid(s,i+1,j))return true;
                else return false; 
                            }
            else i++,j--;
           
        }
        return true;
    }
};