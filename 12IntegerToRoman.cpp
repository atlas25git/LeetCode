public class Solution {
    
    public int RomanToInt(string s) {
        if(s.Length == 1) return Roman[s[0].ToString()];
        
        var num = 0;
        var i = s.Length - 1;
        
        while(i > 0) {
            var prev = s[i].ToString();
            var curr = s[i - 1].ToString();
            
            if(prev == curr) {
                num += Roman[prev];
                i--;
            }
            else {
                if(!Roman.ContainsKey(curr + prev)) {
                    num += Roman[prev];
                    i--;
                }
                else {
                    num += Roman[curr + prev];
                    i -= 2;
                }
            }
        }
        
        if(i == 0) {
            num += Roman[s[i].ToString()];
        }
        
        return num;
    }
    
    public static Dictionary<string, int> Roman =>
     new Dictionary<string, int> {
        { "I", 1 },
        { "IV", 4 },
        { "V", 5 },
        { "IX", 9 },
        { "X", 10 },
        { "XL", 40 },
        { "L", 50 },
        { "XC", 90 },
        { "C", 100 },
        { "CD", 400 },
        { "D", 500 },
        { "CM", 900 },
        { "M", 1000 }
    };
}