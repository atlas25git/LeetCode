class Solution {
public:
    string longestPalindrome(string str) {
        //naive
//         int n=s.size();
//         int mL = 1,start=0;
        
//         for(int i=0;i<s.size();i++){
//             for(int j=i;j<n;j++)
//             {
//                 int flag = 1;
                
//                 for(int k=0;k<(j-i+1)/2;k++)
//                         if(s[i+k]!=s[j-k])
//                             flag=0;
//                 if(flag && (j-i+1)>mL)
//                     start = i,
//                     mL = j-i+1;
//             }
//         }
//         return s.substr(start,mL);
        
        //dp based
        int n = str.size();
        //string str = s;
        vector<vector<bool>> dp(n,vector<bool>(n,0));
        //dp[i][j] -> substring i:j
        int mL = 1;
        
        //marking all the substrings of length 1
        for(int i=0;i<n;i++)dp[i][i]=1;
        
//         for(int i=0;i<n;i++)
//         {for(int j=0;j<n;j++)
//                         cout<<dp[i][j]<<" ";
            
//         cout<<endl;
//         }
        //substrings of len 2
        int start = 0;
        for(int i=0;i<n-1;i++)
        {
            if(str[i] == str[i+1]){
                dp[i][i+1] = 1;
                start = i;
                mL=2;
            }
        }
        
        //for len>2 odd factor
        for(int k=3;k<=n;k++)
        {   //fixing the first index
            //0 to one based conversion
            for(int i=0;i<n-k+1;i++)
            {   //cout<<"::"<<endl;
                int j = i+k-1;
                //i to j is our subString len
                //and i+1,j-1 is the one excluding both 
                //the extremes
                if(dp[i+1][j-1]==1 && str[i] == str[j])
                {   //cout<<"called1"<<endl;
                    dp[i][j]=true;
                    if(k>mL)
                        //cout<<"C2"<<endl,
                        start = i,
                        mL=k;
                    
                }
            }
        }
        //cout<<"mL "<<mL<<"start "<<start<<endl;
        
        return str.substr(start,mL);
    }
};