`class Solution {
public:
    int titleToNumber(string cT) {
        
        int col = 0;
        for(int i=0;i<cT[i];i++)
        {
            col *= 26;
            //each of the 26 alphabets would map to set of 26 alphabes
            //hence multiplied by 26 for their firsts
            col += cT[i] - 'A' + 1;
        }
        
        return col;
    }
};