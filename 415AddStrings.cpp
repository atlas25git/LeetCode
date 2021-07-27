class Solution {
public:
    string addStrings(string num1, string num2) {
        
        int n1 = num1.size();
        int n2 = num2.size();
        int carr = 0;
        stack<int> st;
        
        while(n1>-1 || n2>-1)
        {
            int n11 = n1<0?0:num1[n1--] - '0';
            int n22 = n2<0?0:num2[n2--] - '0';
            int res = Add(n11,n22,carr);
            //cout<<res<<endl;
            if(res>=0)st.push(res);
        }
        
        if(carr>0)st.push(carr);    
        string sum = "";
        while(!st.empty())
        {
            sum += to_string(st.top());
            st.pop();
        }
        return sum;
    }
    
    int Add(int a,int b,int& carr)
    {
        int sum = a+b+carr;
        
        if(sum<10)
        {  
           carr = 0; 
           return sum;
        }
        else {
            carr = sum/10;
            return sum%10;
        }
    }
    
};


class Solution {
public:
    string addStrings(string num1, string num2) {
        
        int i=0,j=0;
        int sum=0,carr=0;
        string res = "";
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        
        for(i=0,j=0;num1[i] && num2[j]; i++,j++)
        {
            int n1 = num1[i]-'0';
            int n2 = num2[j]-'0';
            int pd = n1+n2+carr;
            if(pd>9)
                carr = (n1+n2+carr)/10;
            int digit = pd%10;
            
//             if(carr)
//             {
//                 digit = (n1+n2+carr)%10;
//                 carr  = digit/10;
                
//             }
            
            res += to_string(digit);
        }
        //cout<<i<<" "<<j;
        if(i<num1.length())
        {   //cout<<"I";
            string rem = num1.substr(i,num1.size());
            int x = stoi(rem);
            
            res += rem;
        }
        if(j<num2.length())
        {   //cout<<"J";
            string rem = num2.substr(j,num2.size());
            res += rem;
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};