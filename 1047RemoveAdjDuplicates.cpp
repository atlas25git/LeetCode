class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        int i = 1;
        st.push(s[0]);
        
        for(i=1;i<s.size();i++)
        {
            while(!st.empty() && st.top() == s[i])st.pop(),i++;
            if(i>=s.size())break;
            st.push(s[i]);
        }
        
        string ans;
        while(!st.empty()){ans+=st.top();st.pop();}
        reverse(ans.begin(),ans.end());
        return ans;
    }
};