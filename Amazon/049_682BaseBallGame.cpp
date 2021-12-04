class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        
        for(auto x: ops)
        {   
            // if(st.size())
            // cout<<st.top()<<endl;
            
            if(isdigit(x[0]))
                st.push(stoi(x));
            else if(x[0] == '-') 
                st.push(-1*stoi(x.substr(1)));
            else if(x == "C")
                st.pop();
            else if(x == "D")
                st.push(st.top()*2);
            else if(x == "+")
            {   
                //cout<<st.top()<<"\n";
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b);
                st.push(a);
                st.push(a+b);
            }
        }
        
        int sum = 0;
        while(!st.empty())
        {
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};