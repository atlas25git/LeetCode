class Solution {
public:
    int singleNumber(vector<int> &A) {
        int s = 0;
        for (auto a : A)
            s ^= a;
        return s;
    }
};