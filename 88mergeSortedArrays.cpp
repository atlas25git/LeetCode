class Solution {
public:
    void merge(vector<int>& n1, int m, vector<int>& n2, int n) {
        
        vector<int> res;
        int i=0,j=0,k=0;
        
        while(i<m && j<n)
        {
        if(n1[i]<n2[j])
        {
            res.push_back(n1[i]);
            i++;
        }
        else
        {
            res.push_back(n2[j]);
            j++;
        }
        }
        
        while(i<m)
        {
            res.push_back(n1[i++]);
        }
        
        while(j<n)
        {
            res.push_back(n2[j++]);
        }
        
        n1 = res;
    }
};