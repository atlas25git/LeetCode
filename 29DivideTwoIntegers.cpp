class Solution {
public:
    int divide(int dvd, int div) {
        if(!div || (dvd == INT_MIN && div == -1))return INT_MAX;
        
        long divd = abs((long)dvd);
        long divs = abs((long)div);
        int sign = (dvd>0)^(div>0)?-1:1;
        long res = 0;
        
        while(divd >= divs)
        {
            long tmp  = divs, p=1;
            while(divd>=tmp<<1)
            {
                tmp <<= 1;
                p <<= 1;
            }
            res += p;
            divd -= tmp;
        }
        return sign>0?res:-res;
    }
};

class Solution {
public:
    int divide(int dvd, int div) {
        
        if(!div || (dvd == INT_MIN && div ==-1))return INT_MAX;
        //as -1+INT_MIN would overflow int
        
        long dvdl = abs((long)dvd);
        long divl = abs((long)div);
        int sign = (dvd>0)^(div>0)?-1:1;
        int res = 0;
        while(dvdl>=divl)
        {
            long tmp = divl;
            long p = 1;
            while(dvdl>=tmp<<1)
            {
                tmp<<=1;
                p<<=1;
            }
            dvdl -= tmp;
            res += p;
        }
        
        return sign>0?res:-res;
    }
};