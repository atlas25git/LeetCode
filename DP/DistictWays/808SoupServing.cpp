class Solution {
public:
    
    unordered_map<string,pair<double,double>> memo;
    
    string getHash(int A,int B)
    {
        return to_string(A) +" " + to_string(B);
    }
    
    double soupServings(int n) {
        if(n>5000)
            return 1;
        
        auto res = helper(n,n);
        
        return res.first + res.second/2;
    }
    
    pair<double,double> helper(int A, int B)
    {
        string hash = getHash(A,B);
        
        if(memo.count(hash))return memo[hash];
        
        else if(A<=0 && B<=0)
            return {0,1};
        
        else if(A<=0 && B>0)
            return {1,0};
        
        else if(A>0 && B<=0)
            return {0,0};
        
        else{
            pair<double,double> res = {0,0},curr;
            vector<pair<double,double>> ops = {{100,0},{75,25},{50,50},{25,75}};
            
            for(int i=0;i<4;i++)
            {
                auto curr = helper(A-ops[i].first,B-ops[i].second);
                res.first += curr.first;
                res.second += curr.second;
            }
            
            res.first /= 4;
            res.second /= 4;
            
            memo[hash] = res;
            return res;
            
        }
    }
};

