#define ll long long

//resolve 
// "- (3 + (4 + 5))" 
// 37/41 cases passed
class Solution {
public:
    string infixToPostfix(string s)
    {
        stack <char> st;
        st.push('N');
        string cnvrt;
        for(int i=0;i<s.size();i++)
        {
            if(isNotOperator(s[i]))
                cnvrt += s[i];
                
            else if(s[i] == '(')
                st.push('(');
            else if(s[i] == ')')
            {   cnvrt+='#';
                while(st.top() != '(')
                {
                    char c = st.top();
                    st.pop();
                    cnvrt+=c;
                }
                st.pop();
            }
            else
            {   
                cnvrt+='#';
                while(prec(s[i]) <= prec(st.top()))
                {
                    cnvrt += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        cnvrt+='#';
        while(st.top()!='N')
        {
            cnvrt+=st.top();
            st.pop();
        }
        return cnvrt;
    }
    
    bool isNotOperator(char c)
    {
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || isdigit(c))return true;
        return false;
    }
    
    int prec(char c)
    {
        if(c=='^')return 3;
        else if(c=='*' || c=='/')return 2;
        else if(c=='+' || c=='-') return 1;
        else return -1;
    }
    
    string fixNeg(string s)
    {
        if(s[0]=='-'){
            string s1;
            for(int i=1;i<s.size();i++)
                    {
                if(s[i] == '+')
                    s1+='-';
                else if(s[i] == '-')
                    s1+='+';
                else s1+=s[i];
                     }
            if(s[0]=='+')
                    s1 = s.substr(1,s.size()-1);
            return s1;  
        }
        return s;
    }
    
    int calculate(string s) {
        
        string s1;
        int sign = 1;
        if(s[0]=='-')sign=-1;
        for(auto x: s)if(x!=' ')s1+=x;
        s1 = fixNeg(s1);
        string postfix = infixToPostfix(s1);
        cout<<postfix<<" "<<s1<<endl;
        return sign*evaluate(postfix);
    }
    
    int evaluate(string s)
    {
        stack<ll> st;
        
        for(int i=0;i<s.size();i++)
        {   if(s[i]=='#')continue;
            if(isNotOperator(s[i]))
            {   string s0;
                while(s[i] != '#')
                    s0+=s[i++];
                    // i++;
                    st.push(stoi(s0));
            }
            else //if(st.size()>=2)
            {
                ll a = st.top();st.pop();
                ll b = st.top();st.pop();
                ll x = eval(b,a,s[i]);
                st.push(x);
                // cout<<a<<" "<<b<<" "<<s[i]<<" "<<x<<" "<<st.top()<<"\n";
            }
        }
        return st.top();
    }
    
    ll eval(ll x,ll y,ll sign)
    {   
        if(sign == '+')
            return (x+y);
        else if(sign  == '-')
            return (x-y);
        else if(sign  == '*')
            return (x*y);
        else if(sign == '/')
            return (x/y);
        else if(sign == '^')
            return (x^y);
        return 0;
    }
};