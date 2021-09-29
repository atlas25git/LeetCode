class Solution {
public:
    
    double getPow(double a,int n)
    {
        double ans=1;
        while(n)
        {
            if(n&1)
            {
                ans=a*ans;
            }
            a=a*a;
            n=n>>1;
        }
        return ans;
    }
    double getPowM(double a,int n)
    {   //cout<<"M"<<endl;
        double ans=1;
        while(n)
        {
            if(n&1)
            {
                ans=ans/a;
            }
            a=a*a;
            n=n>>1;
        }
        return ans;
    }
    
    double Pow(double a,int n){
    if(n==0) return 1;

    double subprob = pow(a,n/2);

    if(n&1){
        return 1/(a*subprob*subprob);
    }
    return 1/(subprob*subprob);
    }
    
    
    double myPow(double x, int n) {
        
        double ans;
        if(x==1)return x;
        if(n<0)
        {
            ans=Pow(abs(x),abs(n));
        }
        else ans = getPow(abs(x),n);
        
        if(n&1 && x<0)
        {
            return -1*ans;
        }
        return ans;
    }
};