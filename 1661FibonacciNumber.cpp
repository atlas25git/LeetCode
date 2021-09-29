class Solution {
public:
    int fib(int n) {
        if(n==0)return 0;
        int a = 1,b=1;
        int res=a;
        if(n>2)n-=2;
        else return res;
        while(n--){
            res = a+b;
            a=b;
            b=res;
        }
        return res;
    }
};