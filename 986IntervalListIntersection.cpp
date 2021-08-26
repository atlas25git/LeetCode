class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& fL, vector<vector<int>>& sL) {
        int s =0,e=1;
        int i=0,j=0;
        vector<vector<int>> res;
        while(i<fL.size() && j<sL.size())
        {
            if(
                (fL[i][s]<=sL[j][e] && fL[i][s]>=sL[j][s])
                ||
                (sL[j][s]<=fL[i][e] && sL[j][s]>=fL[i][s])
                )
            {
                res.push_back(vector<int>({
                    max(fL[i][s],sL[j][s]),
                        min(fL[i][e],sL[j][e])
                }));
            }
            
            if(fL[i][e] < sL[j][e])i++;
            else j++;
                
        }
        return res;
    }
};

class Solution {

    private: 
        const int S = 0;
        const int E = 1;
    
    public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        vector<vector<int>> insxn;
        int i=0,j=0;
        while(i<A.size() && j<B.size())
        {
            if(insxs(A[i],B[j])){
                insxn.push_back(vector<int>({max(A[i][S],B[j][S]),
                                            min(A[i][E],B[j][E])}));
            }
            
            if(A[i][E] < B[j][E])i++;
            else j++;
        }
        return insxn;
    }
    
    bool insxs(vector<int> a,vector<int> b)
    {
        return (a[S]>=b[S] && a[S]<=b[E]) || (b[S] >= a[S] && b[S]<=a[E]);
    }
};