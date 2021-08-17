class Solution {
public:
    string multiply(string num1, string num2) {
        //The idea is to store the sum of multiplicative shifted values
        //of each digit of num2 being multiplied with that of num1
        //as a final step we'll adjust the carrie
        if(num1 == "0" || num2 == "0")return "0";
        int n = num1.size() + num2.size();
        vector<int>res(n,0);
        
        for(int i=num2.size()-1;i>-1;i--)
            for(int j=num1.size()-1;j>-1;j--)
                    //plus one as on 0 based indexing 2+2 =4, when in actual terms
                    //3+3 = 6 > which on 0 based scale is 5, thus the discrepancy factor
                    //of 1
                    res[i+j+1] += (num2[i]-'0')*(num1[j]-'0');
        
        //adjusting the carry's
        for(int i=n-1;i>0;i--)
        {
            res[i-1] += res[i]/10;
            res[i] %=10;
        }
        
        string ans;
        //removing the following zeros
        //coverting the vector into strings
        for(int i=0;i<res.size();i++)
        {
            if(ans.empty() && res[i] == 0)continue;
            ans+=char(res[i]+'0');
        }
        
        return ans;
    }
};

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")return "0";
        
        int n=num1.length() + num2.length();
        vector<int>res(n,0);
        
        for(int i=num1.size()-1;i>-1;i--)
            for(int j=num2.size()-1;j>-1;j--)
                    //with the virtue of i the multiplicative shift will be happening
                    //in each iteration
                    res[i+j+1] += (num1[i]-'0')*(num2[j]-'0');
        
        for(auto x:res)cout<<x<<" ";
        cout<<endl;
        for(int i=n-1;i>0;i--)
        {
            res[i-1] += res[i]/10;
            res[i] %= 10;
        }
        for(auto x:res)cout<<x<<" ";
        cout<<endl;
        string ans;
        for(int i=0;i<n;i++)
        {
            if(res[i]==0 && ans.empty())continue;
            ans+=char(res[i]+'0');
        }
        return ans;
        
    }
};