class Solution {
public:
    /**
     * @param n: the length of strobogrammatic number
     * @return: All strobogrammatic numbers
     */
    vector<string> findStrobogrammatic(int n) {
        //backTracking based approach
        return utility(n,n);
    }

    vector<string> utility(int n,int flag)
    {
        if(n==0)return vector<string>({""});
        if(n==1)return vector<string>({"0","1","8"});
        vector<string> temp = utility(n-2,flag);
        vector<string> res;
        for(int i=0;i<temp.size();i++)
        {
            if(n!=flag)
            {
                res.push_back("0"+temp[i]+"0");
            }
            res.push_back("1"+temp[i]+"1");
            res.push_back("6"+temp[i]+"9");
            res.push_back("8"+temp[i]+"8");
            res.push_back("9"+temp[i]+"6"); 
        }
        return res;
    }
};

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return helper(n , n);
    }
    vector<string> helper(int m, int n){
        if(m == 0) {
            return vector<string>({""});
        }
        if(m == 1) {
            return vector<string>({"0", "1", "8"});
        }
        vector<string> tmp = helper(m - 2, n), res;
        for(int i = 0; i < tmp.size(); i++){
            //fwd zeros, not allowed
            if(m != n) {
                res.push_back("0" + tmp[i] + "0");
            }
            res.push_back("1" + tmp[i] + "1");
            res.push_back("6" + tmp[i] + "9");
            res.push_back("8" + tmp[i] + "8");
            res.push_back("9" + tmp[i] + "6");
        }
        return res;
    }
};