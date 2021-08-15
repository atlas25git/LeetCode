#define ll long long

class Solution {
public:
    const std::string WHITESPACE = " \n\r\t\f\v";
 
    std::string ltrim(const std::string &s)
    {
        size_t start = s.find_first_not_of(WHITESPACE);
        return (start == std::string::npos) ? "" : s.substr(start);
    }
     
    std::string rtrim(const std::string &s)
    {
        size_t end = s.find_last_not_of(WHITESPACE);
        return (end == std::string::npos) ? "" : s.substr(0, end + 1);
    }
     
    std::string trim(const std::string &s) {
        return rtrim(ltrim(s));
    }
    
    
    
    int myAtoi(string s) {
        ll i = 0;
        ll sign = 1;
        ll result = 0;

        if(!s.size())return 0;
        s = trim(s);
        if(s.size() == 0) return 0;
        
        if(s[i] == '-' || s[i] == '+')
            sign = s[i++] == '-' ? -1 : 1;

        //cout<<(sign);
        
        while (i < s.length() && isdigit(s[i])) {
            if(result > INT_MAX / 10 || result == INT_MAX / 10 && s[i] - '0' >
               INT_MAX % 10)
                return sign == 1 ? INT_MAX : INT_MIN;
            
            result = result * 10 + s[i++] - '0';
        }
        return result * sign;
    }
};